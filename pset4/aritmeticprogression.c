/* Programa para treinar a utilizar funções recursivas, por: Alexandre Nobuharu Sato em 18/12/2020
 * testando calcular fatorial
 */

#include <stdio.h>
#include <cc50.h>

//prototype
long long int
PA(long long int number);

//global variable
long long int number;


int
main(void)
{
	printf ("Digite o número a ser calculado o progressão aritmética até 0:");
	number = GetInt();
	number = PA(number);
	printf ("\nO Resultado do cálculo é:%.01lli\n", number);
	return 0;
}


//Recursive function
long long int
PA(long long int number)
{
	if (number < 1)
		return 0;
	else if (number == 1)
		return 1;
	else
		return number = number + PA(number -1);

}
