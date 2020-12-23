/* Programa para treinar a utilizar funções recursivas, por: Alexandre Nobuharu Sato em 18/12/2020
 * testando calcular fatorial
 */

#include <stdio.h>
#include <cc50.h>

//prototype
long long int
factorial(long long int number);

//global variable
long long int number;


int
main(void)
{
	printf ("Digite o número a ser calculado o valor fatorial:");
	number = GetInt();
	number = factorial(number);
	printf ("\nO Resultado do cálculo é:%.01lli\n", number);
	return 0;
}


//Recursive function
long long int
factorial(long long int number)
{
	if (number <= 1)
		return 1;
	else
	{
		number = number * factorial(number -1);
		return number;
	}
}
