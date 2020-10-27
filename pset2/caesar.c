//Programa para aprender arrays e criptografia do CS50 David J. Malan e CC50 do Gabriel Lima Guimarães

#include <stdio.h>
#include <cc50.h>
#include <string.h>

int
main (int argc, char *argv[])
  {
  if (argc != 2)
	{
	return 1;
	}
  int k = atoi (argv[1]);
  printf ("A chave de criptografia é: %d\n", k);
  printf ("Digite uma frase a ser criptografada\n");
  char *STRING = GetString ();
  printf ("A frase criptografada é:\n");
  for (int i = 0, LETRA_CRIPTED; i < strlen (STRING); i++)
	{
	int LETRA_ORIGINAL = STRING[i];
	if ((LETRA_ORIGINAL >= 65 && LETRA_ORIGINAL <= 90) || (LETRA_ORIGINAL >= 97 && LETRA_ORIGINAL <= 122))
		{
		if (LETRA_ORIGINAL >= 65 && LETRA_ORIGINAL <= 90)
			{
			LETRA_CRIPTED = ((LETRA_ORIGINAL + k -65 )%26) + 65;
			}
		else
			{
			LETRA_CRIPTED = ((LETRA_ORIGINAL + k - 97) %26) + 97;
			}
		}
	else
		{
		LETRA_CRIPTED = LETRA_ORIGINAL;
		}
	printf ("%c", LETRA_CRIPTED);
	}
  printf ("\n");
  return 0;
  }
