//Programa para plotar as opções de cores de ANSI ESCAPES, autor sato_alexandre@hotmail.com em 08/11/2020

#include <stdio.h>

int
main (void)
{

	int i, j, n;
	for (i=0; i<10; i++)
	{
		for (j=0; j<10; j++)
		{
			n = 10 * i +j;
			if (n > 108)
				break;
			printf ("\033[%dm", n);
		}
		printf ("\n");
	}
	return 0;

}
