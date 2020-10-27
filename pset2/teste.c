//Testar se a biblioteca do CC50 está instalada

#include <stdio.h>
#include <cc50.h>
#include <string.h>

int
main (void)
  {
  printf ("\nDigite uma palavra\n");
  char *string = GetString();
//  printf ("\nDigite um número de letra da palavra\n");
//  int LETRA = GetInt ();
//  printf ("A palavra digitada foi %s\n", string);
//  int LETRA_2 = LETRA - 1 ;
//  printf ("A letra número %d da Palavra digitada é: %c\n", LETRA, string[LETRA_2]);
  for (int i = 0; i < strlen(string); i++)
	{
	printf ("%c", string[i]);
	}
  printf ("\n");
  return 0;
  }


