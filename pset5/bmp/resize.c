/****************************************************************************
 * resize.c
 *
 * CC50
 * Pset 5
 *
 * Multiplies pixels by a factor "n"
 *
 * By: Alexandre Nobuharu Sato, Ribeirão Pires-SP, 26 de março de 2021
 ***************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"


int
main(int argc, char *argv[])
{

    //"n" factor
    int n = atoi(argv[1]);

    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: resize n infile outfile\n");
        return 1;
    }

    // ensure n is between 1 and 100
    if (n < 1 || n > 100)
    {
	printf("n must be between 1 and 100\n");
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
    int padding_out =  (4 - (bi.biWidth * n * sizeof(RGBTRIPLE)) % 4) % 4;

    // recalculate header
    bi.biWidth *= n;
    bi.biHeight *= n;
    bi.biSizeImage = (bi.biWidth * sizeof (RGBTRIPLE) + padding_out) * abs(bi.biHeight);
    bf.bfSize = bi.biSizeImage + bf.bfOffBits;

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // determine padding for scanlines
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {

	// applying n factor in Heigth
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

		}

	        // write padding to outfile
	        for (int k = 0; k < padding_out; k++)
	            fputc(0x00, outptr);

		// returning to begin of the line
		if (m != n - 1)
			fseek(inptr, bi.biWidth * -sizeof(RGBTRIPLE), SEEK_CUR);
	}


        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
