// Programa para calcular quantidade de moedas mínimo para o troco, com moedas de $0,25 $0,10 $0,05 e $0,01

#include <stdio.h>
#include <cc50.h>
#include <math.h>

int
main (void)
{

printf (" Olá este é um programa para calcular a quantidade mínima de moedas\npara efetuar o seu troco.\n\nPor favor digite o seu troco, utilizando ponto ao invés de vírgula\n");
float f = GetFloat(); // captando o digitado com a biblioteca CC50.h ao invés do scanf

while (f < 0) // Testando se o valor digitado é positivo
	{
	printf ("Por favor digite um valor POSITIVO e utilize o ponto ao invés da vírgula para representar a casa decimal\n");
	f = GetFloat();
	}

//separando a parte inteira da decimal e arredondando os centavos 
int INT = f;
int ROUND = round (f * 100);
int CENTS = ROUND - (INT * 100);
printf ("\n%.10f ponto flutuante\n%i inteiro\n%i centavos\n", f, INT, CENTS);

//Calculando as moedas a serem utilizadas para fazer o troco
int COIN_25 = CENTS / 25;
printf ("\n%i moedas de $25\n", COIN_25);

int COIN_10 = (CENTS    - (COIN_25 * 25)   )/10;
printf ("%i moedas de $10\n", COIN_10);

int COIN_05 = (CENTS    - (COIN_25 * 25) - (COIN_10 * 10)  )/5;
printf ("%i moedas de $05\n", COIN_05);

int COIN_01 = (CENTS    - (COIN_25 * 25) - (COIN_10 * 10) - (COIN_05 * 5)   )/1;
printf ("%i moedas de $01\n", COIN_01);

//Calculando a quantidade mínima de moedas para fazer o troco
int QT_MIN = COIN_25 + COIN_10 + COIN_05 + COIN_01;
printf ("\nA quantidade mínima possível de moedas para fazer o troco é:\n%i\n", QT_MIN);

}
