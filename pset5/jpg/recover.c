/* **************************************************************************************
 * recover.c
 *
 * Programa para recuperar fotos jpg de um cartão FAT (512bytes por bloco)
 *
 * Curso CC50 por Gabriel Lima Guimarães, traduzido do original CS 50 (Harvard) de David J. Malan
 * Pset 5
 *
 * Aluno: Alexandre Nobuharu Sato e Tabata em Ribeirão Pires - SP, 2 de abril de 2021
 * *************************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

#define MAGIC_NUMBER 55551  //0xd8ff is jpg and 0x4d42 is bmp

typedef uint8_t BYTE;
typedef uint16_t WORD;

typedef struct
{
	WORD magicNumber;
	BYTE padding[510];
}__attribute__((__packed__))
BUFFER;

int
main(void)
{
	FILE *fp = fopen("card.raw", "r");
	if (fp == NULL)
	{
		printf("Could not open %s.\n", fp);
		return 1;
	}

	//Getting fp size
	fseek(fp, 0L, SEEK_END);
	int size = ftell(fp);
	fseek(fp, 0L, SEEK_SET);

	int count = 0;
	for(int i = 0; i < (size / sizeof(BUFFER)); i++)
	{

		BUFFER buffer;
		fread(&buffer, sizeof(BUFFER), 1, fp);
		if (buffer.magicNumber == MAGIC_NUMBER)
		{
			printf("Encontrei %2d em i:%3d\n", ++count, i);


			char outfile[8];
			sprintf (outfile, "%03d.jpg", count);
			FILE *outptr = fopen(outfile, "w");
			if (outptr == NULL)
			{
				fprintf(stderr, "Could not create %s.\n", outfile);
				return 2;
			}

			fwrite(&buffer, sizeof(BUFFER), 1, outptr);

			fread(&buffer, sizeof(BUFFER), 1, fp);

			do
			{
				fwrite(&buffer, sizeof(BUFFER), 1, outptr);
				fread(&buffer, sizeof(BUFFER), 1, fp);
				i++;
			}
			while (buffer.magicNumber != MAGIC_NUMBER && i < (size / sizeof(BUFFER)));

			fseek(fp, -sizeof(BUFFER), SEEK_CUR);

		}

	}
	return 0;
}
