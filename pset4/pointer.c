//Programa para treinar a utilização de ponteiros por: Alexandre Nobuharu Sato em 24/12/2020

#include <stdio.h>
#include <cc50.h>


void
swap(char **a, char **b);//Prototype of function with pointer


int
main(void)
{
	printf ("\nDigite a entrada a:");
	char *a = GetString();
	printf ("\nDigite a entrada b:");
	char *b = GetString();
	printf ("\nA saída a:%s   b:%s\n", a, b);

	printf("Trocando.....");
	swap(&a, &b);

	printf ("\nA saída a:%s   b:%s\n", a, b);
	return 0;
}

void
swap(char **a, char **b)
{
	char *TEMP = *a;
	printf ("\nTEMP:%s",TEMP);
	*a = *b;
	*b = TEMP;
}
