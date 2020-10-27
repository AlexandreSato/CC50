//Programa para testar a biblioteca CC50 capturar teclado

#include <stdio.h>
#include <cc50.h>

int
main (void)

{

	printf ("\nDigite uma string\n");

	string STRING = GetString();

	printf ("\nVoce digitou %s \n", STRING) ;


}
