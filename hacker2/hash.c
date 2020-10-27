/* Programa para gerar hash com a função Crypt(), Autor: Alexandre Nobuharu Sato, 10 de outubro de 2020 12:15*/
#define _XOPEN_SOURCE

#include <stdio.h>
#include <cc50.h>
#include <crypt.h>
#include <string.h>

int
main (void)
{

	printf ("introduza a senha:");
	char *senha = GetString();
	printf ("\ndigite o salt com dois caracteres:");
	char *salt = GetString();

	char *hash = crypt ( senha, salt);

	printf ("\nO Hash é: %s\n", hash);

	printf ("Digite o Hash\n");
	char *test = GetString();

	if ( ! strcmp ( hash, test) )/*Comparando o hash*/
		printf ("Coincide o hash\n");
	else
		printf ("Ocorreu algum erro\n");

}
