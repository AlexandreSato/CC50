// Programa para o usuário adivinhar o número aleatório sorteado pela máquina

#include <cc50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int
main (void)

{

	//seed do PRNG
	srand(time(NULL));

	// escolhe número pseudo-aleatório entre (0, 1023)
	int SKITTLES = rand () % 1024;


	//TODO
//	printf ("\nO numero sorteado é %i\n", SKITTLES);

	printf ("Este é um jogo que eu Alexandre Nobuharu Sato tive que desenvolver como tarefa do curso de ciência da computação CC50, nele você precisará adivinhar EM ATÉ 15 TENTATIVAS um número que é sorteado aleatóriamente entre 0 e 1023\n");

	int i = 1;
	//int CHUTE = 0;

	while (i<15)
		{
		printf ("\ntentativa %i de 15\n", i);
		
		printf ("\nDigite qual número você acha que é?\n");

		int CHUTE = GetInt ();

		i++;
			if (CHUTE==SKITTLES)
			{
			printf ("\nparabéns você acertou!\n");
			break;
			}
			else if (CHUTE<SKITTLES)
			{
			printf ("\no número tentado %i é menor do que o sorteado\n", CHUTE);
			printf ("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
			}
			else
			{
			printf ("\no número tentado %i é MAIOR do que o sorteado\n", CHUTE);
			printf (">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
			}
		}

}
