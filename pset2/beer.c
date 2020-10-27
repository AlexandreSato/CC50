//Canção de bar ... cerveja no muro

#include <stdio.h>

int
main (void)
  {
  printf ("\n");

  for (int i = 10; i > 0; i--)
    {

    int j = i - 1 ;

    if ( i == 2)
	{
	printf ("%.2d garrafas de cerveja no muro, bebo uma, jogo no lixo, %d garrafa no muro...\n", i, j);
	}

    else if (i == 1)
	{
	printf ("%.2d garrafa de cerveja no muro, bebo uma, jogo no lixo, nenhuma garrafa no muro...\n", i);
	}

    else
	{
		printf ("%.2d garrafas de cerveja no muro, bebo uma, jogo no lixo, %d garrafas no muro...\n", i, j);
	}
    }

  printf ("\n");

  return 0;
  }
