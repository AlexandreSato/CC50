//Programa para aprender a produzir gráfico de colunas

#include <stdio.h>
#include <cc50.h>


int
main (void)
{

printf ("\nDigite o número de linhas desejado\n\n");
int MAXBAR = GetInt();

int MAXBAR2 = MAXBAR - (MAXBAR * .5) ;// Teste para plotar coluna diferente na metade da altura máxima

char M_F;

int i;
for (i=1; i<= MAXBAR; i++)
	{
	if (i<=MAXBAR2)
		{
		M_F = 32;
		}
	else if (i>MAXBAR2)
		{
		M_F = 35;
		}
	printf ("%c%c%c   ###   ###   ###\n", M_F, M_F, M_F);
	} 

printf ("M-F   F-M   F-F   M-M\n\n");

}
