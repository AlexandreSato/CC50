//Programa para executar a criptografia Cifra_Vigenere para o curso CC50 @Gabriel Lima Guimarães e CS50 @David J. Malan

#include <stdio.h>
#include <cc50.h>
#include <string.h>

int
main (int argc, char *argv[]) //captando argumentos depois do comando do terminal
	{
	if (argc != 2) //testando se a função tem mais de um argumento
		{return 1;}
	printf ("Digite a frase a ser criptografada:\n");
	char *STRING = GetString(); //captando a frase a ser criptografada

	for (int i = 0, j = 0, CHAR = 0, ZERO; i < strlen (STRING); i++)
		{
		CHAR = STRING[i]; //Casting ASCII p/ inteiro
		if (    (CHAR > 64 && CHAR < 91) || (CHAR > 96 && CHAR < 123)    )//Se o caractere for upper OU lowercase ASCII
			{
			int CONTADOR = j % strlen(argv[1]); //pegando o módulo do contador da chave de Vigenére

			int k = argv[1][CONTADOR]; //Transformando o respectivo caratere da chave em inteiro

			if ( k < 91)  //Vendo se o caractere da chave é upper ou lowercase e aplicando o seu devido zero aritmético
				{k = k - 65;}
			if ( k > 96)
				{k = k - 97;}

			if (CHAR > 64 && CHAR < 91)
				{ZERO = 65;}//Zero para aritmética do módulo de uppercase
			if (CHAR > 96 && CHAR < 123)
				{ZERO = 97;}//zero para a aritmética do módulo de lowercase

			CHAR = (CHAR - ZERO + k) %26 + ZERO ; //somando a chave de criptografia da vez ao caractere

			printf ("%c", CHAR);

			j++ ;//incrementando contador da chave de criptografia
			}
		else  //se não é caractere uppercase ou lowercase da tabela ASCII então não faz nda
			{
			printf ("%c", CHAR);
			}
		}

	printf ("\n");
	return 0;
	}
