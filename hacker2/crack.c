/*Programa para quebrar senhas DES-BASED para o curso CC50 ministrado por @Gabriel Lima Guimarães e CS50 por @David J. Malan
Autor: Alexandre Nobuharu Sato em 10 de outubro de 2020 às 16h56min.*/

/* para executar:
alesato@ubuntusato: $ ./crack.c <hash>
Ex:
alesato@ubuntusato: $ ./crack.c 42r8gDz47ETXY
Senha: lemon                                  */

#define _XOPEN_SOURCE
#include <crypt.h>
#include <string.h>
#include <cc50.h>
#include <stdio.h>

int
main (int argc, char *argv[])
{
	if (argc != 2)
		return 1;
	char SALT[2];
	SALT[0] = argv[1][0];
	SALT[1] = argv[1][1];
	printf ("SALT DES-BASED: %s\n", SALT);

	/*Teste por brute-force, seis loops para seis caracteres lower case
        limitados a isto devido minha capacidade computacional*/

	for (int LETRA_0 = 97; LETRA_0 <= 122; LETRA_0++)
	  {
	    for (int LETRA_1 = 97; LETRA_1 <= 122; LETRA_1++)
	    {
	    	for (int LETRA_2 = 97; LETRA_2 <= 122; LETRA_2++)
	  	{
	    	  for (int LETRA_3 = 97; LETRA_3 <= 122; LETRA_3++)
	  	  {
	    	    for (int LETRA_4 = 97; LETRA_4 <= 122; LETRA_4++)
	  	      {
			for (int LETRA_5 = 97; LETRA_5 <= 122; LETRA_5++)
	  		{
	    		char SENHA[6];
			SENHA[0] = (char) LETRA_0;
			SENHA[1] = (char) LETRA_1;
			SENHA[2] = (char) LETRA_2;
			SENHA[3] = (char) LETRA_3;
			SENHA[4] = (char) LETRA_4;
			SENHA[5] = (char) LETRA_5;
			char *HASH_TEST = crypt ( SENHA, SALT );
				/*É aqui que a mágica acontece, compara com
				a senha gerada pelo brute force com o hash 
				do começo */
				printf ("Senha em teste: %s  Hash: %s\n", SENHA, HASH_TEST);
				if ( !strcmp ( HASH_TEST, argv[1] ))
				{
				  printf ("A senha é: %s\n", SENHA);
				  return 0;
				}
	  	         }
                       }
	  	    }
	  	 }
	      }
	   }
}
