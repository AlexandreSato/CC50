//Programa para entender o funcionamento da varíavel INT_MAX e a digitação dos botões "CTRL+D", por: sato_alexandre@hotmail.com em 01/11/2020

#include <stdio.h>
#include <cc50.h>

int
main (void)
{
	int TEMP = 0;
	int COUNT = 0;
	while (TEMP != INT_MAX)
	{
		printf ("Iteration: %2d, Enter a value for TEMP:", COUNT);
		TEMP = GetInt();
//		printf ("\nTEMP is: %d", TEMP);
		COUNT += 1;
	}

	printf ("\n CTRL+D (EOF) Pressed, INT_MAX = %d\n", INT_MAX);
}
