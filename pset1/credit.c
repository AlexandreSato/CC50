//programa para testar a validade de cartões de crédito

#include <stdio.h>
#include <cc50.h>
#include <math.h>

int
main (void)

{
printf ("\nDigite o número de cartão de crédito\n");
long long int CARDNUMBER = GetLongLong();

//testando se o número digitado é positivo
while (CARDNUMBER < 0) 
	{
	printf ("O número precisa ser positivo\nTente novamente:");
	CARDNUMBER = GetLongLong();
	}

//Pegando os dígitos pares e executando o algorítmo de Hans Peter Luhn
long long int SUN ;
int i;
for (i=1; i<=15; i+=2)
	{ 
	long long int POTENCIA = pow(10, i);
	long long int NUMBER_MAX = CARDNUMBER / POTENCIA ;
	long long int NUMBER_MIN = CARDNUMBER /(POTENCIA*10)*10; 
	long long int NUMBER = NUMBER_MAX - NUMBER_MIN;//Fim de captar dígitos pares
	int NUMBER2 = 2*NUMBER;//Multiplicando por dois os dígitos pares conforme algoritmo de Hans Peter Luhn
	if (NUMBER2 > 9)//Se o resultado do produto der dois digitos precisa somar separadamente
		{
		int NUMBER_MAX2 = NUMBER2 / 10;//dígito da dezena
		int NUMBER_MIN2 = NUMBER2 / 10 * 10;//dezena vezes dez para extrair o dígito da unidade
		int NUMBER3 = NUMBER_MAX2 + (NUMBER2 - NUMBER_MIN2);
		SUN = SUN + NUMBER3;
		}
	else
		{SUN = SUN + NUMBER2;}

	}


//Pegando os dígitos ímpares e executando o algorítmo de Hans Peter Luhn
int j;
for (j=0; j<=15; j+=2)//j=0 para começar do primeiro dígito da direita para a esquerda
	{
	long long int POTENCIA2 = pow (10, j);
	long long int NUMBER_MAX2 = CARDNUMBER / POTENCIA2;
	long long int NUMBER_MIN2 = CARDNUMBER / (POTENCIA2*10)*10;//tirando o lado esquerdo do número devida a peculiaridade computacional no "int";
	long long int NUMBER4 = NUMBER_MAX2 - NUMBER_MIN2;
	SUN = SUN + NUMBER4;
	}

printf ("\nCHECKSUN = %lli\n", SUN);

//Realizando o CheckSum
if (SUN %10 != 0)
	{
	printf ("\nO número digitado é invalido, você digitou corretamente?\nINVALID\n");
	}

//detectando a bandeira
else if (CARDNUMBER>=340000000000000 && CARDNUMBER<=349999999999999 || CARDNUMBER>=370000000000000 && CARDNUMBER<=379999999999999)
	{
	printf ("\nAMEX\n");
	}
else if (CARDNUMBER>=5100000000000000 && CARDNUMBER<=5599999999999999)
	{
	printf ("\nMASTERCARD\n");
	}
else if (CARDNUMBER>=4000000000000 && CARDNUMBER<=4999999999999 || CARDNUMBER>= 4000000000000000 && CARDNUMBER<=4999999999999999)
	{
	printf ("\nVISA\n");
	}

}
