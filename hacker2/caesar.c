//Programa para executar a cifra de César a partir da primeira linha de um arquivo de texo salvo no diretório, para o curso CC50 ministrado por @Gabriel Lima Guimarães e o CS50 ministrado por @David J. Malan
//Aluno Alexandre Nobuharu Sato
#include <stdio.h>
#include <cc50.h>
#include <string.h>
//#include <stdlib.h>

int
main (int argc, char*argv[])
{
	if (argc != 2) //Aceita apenas um argumento após o comando
		return 1;
	int k = atoi(argv[1]); //trasformando o argumento após o comando em um  número inteiro
	if (k < 0) //Aceita apenas números positivos
		return 1;
	printf ("A Chave cadastrada para a Cifra de Cesar é K: %d\nAgora digite o nome do arquivo com o texto a ser criptogrado incluindo a sua extensão. Ex: 'nescau.txt'\n", k); //exibe a chave cadastrada para a cifra de César
	char *FILENAME = GetString(); //coletando o nome do arquivo a ser aberto

//	system ("clear");
	//início rotina para ler o arquivo
	FILE *arq;
	char *result;
	char Linha[100];
	int i;
	arq = fopen (FILENAME, "rt");// Abre um arquivo de texto para leitura
	if (arq == NULL) // Se houve erro na abertura
	{
		printf ("Prolema na leitura do arquivo\n");
		return 1;
	}
	i = 1;
	while (!feof(arq))// Lê uma linha inclusive com o '\n'
	{
		result = fgets (Linha, 100, arq); //o 'fgets' lê até 99 caracteres ou até o '\n'
		if (result) //Se foi possível ler
			printf ("Linha : %d %s", i,  Linha);
		i++;
	}
	fclose (arq);
	//FIM rotina para ler o arquivo > texto do arquvio carregado na string "Linha"
	printf ("\n");

	//INÍCIO da criptografia
	for (int i = 0, CHAR = 0, ZERO; i < strlen (Linha); i++)
	{
		CHAR = Linha[i];//Transformando caractere para número, pois CHAR foi declarado "int" no início do loop
		if ( (CHAR > 64 && CHAR < 91) || (CHAR > 96 && CHAR < 123) )//Testando se o caractere é upper ou lowercase conforme número da tabela ASCII
		{
			if ( CHAR > 96)//Atribuindo valor zero dos caracteres lowercase
				ZERO = 97;
			if ( CHAR < 91)//Atribuindo o valor zero dos caracteres uppercase
				ZERO = 65;
			CHAR = ( CHAR - ZERO + k ) %26 + ZERO; //Aplicando a chave de criptografia
		}
		printf ("%c", CHAR);
	}
	printf ("\n");
	return 0;
}

