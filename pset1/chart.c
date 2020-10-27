

//Programa para gerar gráfico de barras de pessoas procurando pessoas "I Saw You Harvard"

#include <stdio.h>
#include <cc50.h>
#include <math.h>

int 
main (void)

{

//Captando as quantidades
printf ("\nDigite a quantidade de M procurando F ");
int M_F = GetInt();
printf ("\nDigite a quantidade de F procurando M ");
int F_M = GetInt();
printf ("\nDigite a quantidade de F procurando F ");
int F_F = GetInt();
printf ("\nDigite a quantidade de M procurando M ");
int M_M = GetInt();


//Emitindo um resumo das quantidades
printf ("\n\nM procurando F: %i\nF procurando M: %i\nF procurando F: %i\nM procurando M: %i\n", M_F, F_M, F_F, M_M);


//Realizando cálculos matemáticos das porcentagens das barras
float TOTAL = M_F + F_M + F_F + M_M;
float PERC_M_F = M_F / TOTAL;
float PERC_F_M = F_M / TOTAL;
float PERC_F_F = F_F / TOTAL;
float PERC_M_M = M_M / TOTAL;

//Realizando cálculos matemáticos para plotar o gráfico de barras
int SIZE_MAX = 80; //Número máximo de "#" que corresponderão à 100%
int PLOT_M_F = SIZE_MAX * PERC_M_F;
int PLOT_F_M = SIZE_MAX * PERC_F_M;
int PLOT_F_F = SIZE_MAX * PERC_F_F;
int PLOT_M_M = SIZE_MAX * PERC_M_M;

//Plotando o gráfico de barras
printf ("\n\nQuem procura quem?\n");
printf ("\nM procurando F\n");

	int i;
	for (i=1 ; i<= PLOT_M_F ; i++)
	{
	printf ("#");
	}

printf ("\n\nF procurando M\n");

	int j;
	for (j=1 ; j<= PLOT_F_M ; j++)
	{
	printf ("#");
	}

printf ("\n\nF procurando F\n");

	int k;
	for (k=1 ; k<= PLOT_F_F ; k++)
	{
	printf ("#");
	}

printf ("\n\nM procurando M\n");

	int w;
	for (w=1 ; w<= PLOT_M_M ; w++)
	{
	printf ("#");
	}

printf ("\n\n");

}
