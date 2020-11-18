//Programa para produzir números pseudo aleatórios sem repetir Autor: sato_alexandre@hotmail.com em 18/11/2020
#include <stdio.h>
#include <time.h>
#include <unistd.h>//Para funcionar a função usleep()
#include <stdlib.h>//Para funcionar a função rand()

int
main (int argc, char *argv[])
{
	if (argc != 2 && argc != 3)//validation
	{
		printf ("\nUsage %s [n_max] [seed]\n", argv[0]);
		return 1;
	}

	if (argc == 3)
		srand ((unsigned int) atoi (argv[2]) );
	else
		srand ((unsigned int) time(NULL));
/*
	printf ("\n");
	for (int i = 10; i > 0; i--)
	{
		printf ("[%2d] %2d\n", i, rand() % atoi(argv[1]) );
	}
*/

	int QT_MAX = atoi (argv[1]);
	int SUPPORT_VECTOR[QT_MAX], TEMP, TEST = 1;
	for (int i= 0; i < QT_MAX; i++)
	{
		SUPPORT_VECTOR[i] = 0;
	}
	int i = 0;
	while (i < QT_MAX)//injetando numeros não repetidos no vetor de suporte
	{
		TEMP = rand() % atoi(  argv[1]  ) ;
		for (int j = 0; j < i; j++)
		{
			if (SUPPORT_VECTOR[j] == TEMP)//se  houver alguma repetição muda TEST para false
				TEST = 0;
		}
		if (TEST == 1)
		{
			SUPPORT_VECTOR[i] = TEMP;//se não é repetido injeta rand() na posição i do vetor de suporte
			i++ ;
		}
		TEST = 1;
	}

	printf ("\n");
	for (int i = 0; i < QT_MAX; i++)
	{
		printf ("[%2d] %3d\n", i, SUPPORT_VECTOR[i]);
	}
	return 0;
}


/*
 * Entendendo a funçao time(NULL)
 *
int
main (void)
{
	int t;
	while ( 1 )
	{
		printf ("\033[2J"); //Limpando a tela usando ANSI escapes
		printf ("\033[%d;%dH", 15, 0); //Posicionando no começo da tela
		printf ("Digite CTRL + C para parar a execução");
		t= time(NULL);
		printf ("\nA quantidade de segundos desde 1 de janeiro de 1970 até hoje é:\n\n %d\n", t);
		usleep (500000);
	}

}
 */

