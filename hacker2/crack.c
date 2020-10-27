//teste de programa para crackear senhas
#include <stdio.h>
#include <cc50.h>
#include <math.h>
#include <stdlib.h>

int
main (void)
{
	printf ("Digite a potência de 10 para testar tempo de computação\n");
	long long CONTADOR = GetInt();
	CONTADOR = pow (10, CONTADOR);

	for (int i = 0; i < CONTADOR; i++)
	{
		printf (" O contador está em: %d\n", i);
	}
GetString();
system ("clear");
return 0;
}

