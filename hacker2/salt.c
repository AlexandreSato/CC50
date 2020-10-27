/*loop para gerar o salts de teste autor: Alexandre Nobuharu Sato em 10 de outubro de 2020 */
#include <stdio.h>
#include <cc50.h>
#include <string.h>
#include <crypt.h>

int
main (void)
{
	printf ("Digite a senha:");
	char *SENHA = GetString();
	printf ("\nDigite o hash:");
	char *HASH = GetString();
	char SALT[2];
	/* loop para gerar todas as combinações possíveis de salt*/
	for (int j = 65; j <= 122; j++)
	{
		if ( j == 91 )
			j = 97;
		for (int i = 65; i <= 122; i++)
		{
			if (i == 91)
				i = 97;
			SALT[1] = i;
			SALT[0] = j;
			char *HASH_TEST = crypt ( SENHA, SALT );
			if ( !strcmp ( HASH, HASH_TEST) )
				printf ("\no Salt é: %s\n",SALT);
		}
	}
}

