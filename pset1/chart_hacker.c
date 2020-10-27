

//Programa para gerar gráfico de COLUNAS (VERSÃO HACKER) de pessoas procurando pessoas "I Saw You Harvard"

#include <stdio.h>
#include <cc50.h>
#include <math.h>

int 
main (void)

{

//Captando as quantidades
printf ("\nM procurando F: ");
int M_F = GetInt();
printf ("F procurando M: ");
int F_M = GetInt();
printf ("F procurando F: ");
int F_F = GetInt();
printf ("M procurando M: ");
int M_M = GetInt();

//Realizando cálculos matemáticos das porcentagens das COLUNAS
float TOTAL = M_F + F_M + F_F + M_M;
float PERC_M_F = M_F / TOTAL;
float PERC_F_M = F_M / TOTAL;
float PERC_F_F = F_F / TOTAL;
float PERC_M_M = M_M / TOTAL;


//Realizando cálculos matemáticos para plotar o gráfico ALTURA MÁXIMA DE CADA COLUNA
int SIZE_MAX = 20; //Número máximo de LINHAS que corresponderão à 100%
int PLOT_M_F = SIZE_MAX * PERC_M_F;
int PLOT_F_M = SIZE_MAX * PERC_F_M;
int PLOT_F_F = SIZE_MAX * PERC_F_F;
int PLOT_M_M = SIZE_MAX * PERC_M_M;

//Descobrindo qual é o valor máximo de linhas que precisão ser plotadas e atribuindo a MAX_LINE que será usado no índice do loop
int MAX_LINE = PLOT_M_F;
if (PLOT_F_M>MAX_LINE)
	{MAX_LINE=PLOT_F_M;}
if(PLOT_F_F>MAX_LINE)
	{MAX_LINE=PLOT_F_F;}
if(PLOT_M_M>MAX_LINE)
	{MAX_LINE=PLOT_M_M;}

printf ("\n\nQuem procura quem?\n\n");

//Plotando o gráfico de COLUNAS
int i;
for (i=1; i<=MAX_LINE; i++)
	{
	char M_F=32, F_M=32, F_F=32, M_M=32;
	if (i>(MAX_LINE-PLOT_M_F))
		{
		M_F=35;
		}
	if (i>(MAX_LINE-PLOT_F_M))
		{
		F_M=35;
		}
	if (i>(MAX_LINE-PLOT_F_F))
		{
		F_F=35;
		}
	if (i>(MAX_LINE-PLOT_M_M))
		{
		M_M=35;
		}
	printf ("%c%c%c  %c%c%c  %c%c%c  %c%c%c\n",M_F,M_F,M_F,F_M,F_M,F_M,F_F,F_F,F_F,M_M,M_M,M_M);
	}
printf ("M-F  F-M  F-F  M-M\n");
printf ("\n\n");

}

