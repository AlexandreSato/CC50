 /* Programa para criar minha primeira função perzonalizada no C chamada "swap" que irá trocar a string A pela B
  * autor: sato_alexandre@hotmail.com em 30/10/2020 */

#include <stdio.h>
#include <cc50.h>

void
swap (char **M, char **N); //Protótipo da função


int
main (void){

	char *A;
	char *B;

	printf ("\nDigite a string A:");
	A = GetString();
	printf ("\nDigite a string B:");
	B = GetString();

	printf ("\nInvocando a função swap\n");
	swap(&A, &B);

	printf ("A string A é: %s\n", A);
	printf ("A string B é: %s\n", B);
}


void
swap (char **M, char **N) { //Definição da função swap

	//Trocando as strings
	char *TEMP = *M;
	*M = *N;
	*N = TEMP;

	printf ("Trocando ...\n");

}
