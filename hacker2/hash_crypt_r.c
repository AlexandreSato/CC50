/*Autor: Alexandre Nobuharu Sato , programa para gerar Hash DES-BASED
com a função crypt_r() */

#define _GNU_SOURCE
#include <cc50.h>
#include <crypt.h>
#include <stdio.h>

int
main (void)
{
	printf ("Digite a senha\n");
	char *SENHA = GetString();
	printf ("Digite o salt\n");
	char *SALT = GetString();

	struct crypt_data data[1] = {0};
	char *res = crypt_r ( SENHA, SALT, data);

	printf("O valor de retorno da função crypt_r é: %s\n", res);
	return 0;

}

