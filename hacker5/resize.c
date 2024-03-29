/****************************************************************************
 * resize.c
 *
 * CC50
 * Pset 5 HACKER EDITION
 *
 * Multiplies pixels by a factor "f" accepting float values
 *
 * By: Alexandre Nobuharu Sato, Ribeirão Pires-SP, 04 de abril de 2021
 ***************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"


int
main(int argc, char *argv[])
{

    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: resize f infile outfile\n");
        return 1;
    }

    //"f" factor
    float f;
    sscanf(argv[1], "%f", &f);

    // ensure f is between 0 and 100
    if (f < 0 || f > 100)
    {
	printf("f must be between 0 and 100\n");
	return 1;
    }


    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // make a copy for bi_output
    BITMAPINFOHEADER bi_out;
    bi_out = bi;

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }


    // determine padding for outfile's
    int temp = bi_out.biWidth * f;
    int padding_out =  (4 - (temp * sizeof(RGBTRIPLE)) % 4) % 4;

    // recalculate header
    bi_out.biWidth *= f;
    bi_out.biHeight *= f;
    bi_out.biSizeImage = (bi_out.biWidth * sizeof (RGBTRIPLE) + padding_out) * abs(bi_out.biHeight);
    bf.bfSize = bi_out.biSizeImage + bf.bfOffBits;

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);
    // write outfile's BITMAPINFOHEADER
    fwrite(&bi_out, sizeof(BITMAPINFOHEADER), 1, outptr);

    // determine padding for scanlines
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;


    printf("padding_out: %d, OutWidth: %d, OutHeight: %d, OutSizeImage: %d, BfSize: %d\n", padding_out, bi_out.biWidth, bi_out.biHeight, bi_out.biSizeImage, bf.bfSize);
//    printf("%d    %d\n", bi.biWidth / bi_out.biWidth, bi.biHeight / bi_out.biHeight);

    if (f < 0.5)
    {
	    // iterate over infile's scanlines
	    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
	    {

	        // iterate over pixels in scanline
	        for (int j = 0; j < bi.biWidth; j++)
	        {
	            // temporary storage
	            RGBTRIPLE triple;

	            // read RGB triple from infile
	            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

		    // applying f factor in Width
		    if (((j + 1) % (bi.biWidth / bi_out.biWidth) == 0) && ((i + 1) % (bi.biHeight / bi_out.biHeight) == 0))
	           	 // write RGB triple to outfile
	            	fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
		}

		if((i + 1) % (bi.biHeight / bi_out.biHeight) == 0)
		        // write padding to outfile
		        for (int k = 0; k < padding_out; k++)
		            fputc(0x00, outptr);

	        // skip over padding, if any
	        fseek(inptr, padding, SEEK_CUR);
	    }
    }


    if (f >= 0.5 && f < 1)
    {
	    // iterate over infile's scanlines
	    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
	    {

	        // iterate over pixels in scanline
	        for (int j = 0; j < bi.biWidth; j++)
	        {
	            // temporary storage
	            RGBTRIPLE triple;

	            // read RGB triple from infile
	            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

		    // applying f factor in Width
		    if  (!((j + 1) % (bi.biWidth / (bi.biWidth - bi_out.biWidth)) == 0) && !((i + 1) % (bi.biHeight / (bi.biHeight - bi_out.biHeight)) == 0))
	           	 // write RGB triple to outfile
	            	fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
		}

		if (! (i + 1) % (bi.biHeight / (bi.biHeight - bi_out.biHeight)) == 0)
		        // write padding to outfile
		        for (int k = 0; k < padding_out; k++)
		            fputc(0x00, outptr);

	        // skip over padding, if any
	        fseek(inptr, padding, SEEK_CUR);
	    }
    }

    if (f >= 1)
    {
	    int n = f;
	    float decimal = f - n;

	    // iterate over infile's scanlines
	    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
	    {

		// applying n factor in Height
		for (int m = 0; m < n; m++)
		{
		        // iterate over pixels in scanline
		        for (int j = 0; j < bi.biWidth; j++)
		        {
		            // temporary storage
		            RGBTRIPLE triple;

		            // read RGB triple from infile
		            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

			    // applying n factor in Width
			    for (int l = 0; l < n; l++)
			            // write RGB triple to outfile
			            fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);

			    if (! (decimal <= 0))
			    {
				int DELTAWIDTH = bi.biWidth * decimal;
				int GAPWIDTH = bi.biWidth / DELTAWIDTH;
			    	if ((j + 1) % GAPWIDTH == 0)
			            fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
			    }

			}

		        // write padding to outfile
		        for (int k = 0; k < padding_out; k++)
		            fputc(0x00, outptr);


			   if (! (decimal <= 0))
			   {
				int DELTAWIDTH = bi.biWidth * decimal;
				int GAPWIDTH = bi.biWidth / DELTAWIDTH;
			        int DELTAHEIGHT = bi.biHeight * decimal;
			        int GAPHEIGHT = bi.biHeight / DELTAHEIGHT;
				if((i + 1) % GAPHEIGHT == 0)
				{
					fseek(inptr, bi.biWidth * -sizeof(RGBTRIPLE), SEEK_CUR);
				        for (int j = 0; j < bi.biWidth; j++)
				        {
				            // temporary storage
				            RGBTRIPLE triple;

				            // read RGB triple from infile
				            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

					    // applying n factor in Width
					    for (int l = 0; l < n; l++)
					            // write RGB triple to outfile
					            fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);

					    if ((j + 1) % GAPWIDTH == 0)
					            fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);

					}

				        // write padding to outfile
				        for (int k = 0; k < padding_out; k++)
				            fputc(0x00, outptr);
				}
			    }

			// returning to begin of the line
			if (m != n - 1)
				fseek(inptr, bi.biWidth * -sizeof(RGBTRIPLE), SEEK_CUR);
		}

	        // skip over padding, if any
	        fseek(inptr, padding, SEEK_CUR);
	    }
      }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
