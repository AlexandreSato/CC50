//testando cálculo de porcentagem no loop
/* Teste de Comentário*/
/*
}
*/

#include <stdio.h>
#include <cc50.h>

int
main (void)
{
	printf ("digite um número de 1 a 10\n");
	int a = GetInt();
	for (int i = 1; i <= a; i++)
	{
		int b = i * 100 / 10;
		printf ("o percentual é: %d \n", b);

	}
		return 0;

}
