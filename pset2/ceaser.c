//Programa para aprender criptografia para o curso CC50, prof David J. Malan e Gabriel Lima Guimarães

#include <stdio.h>
#include <cc50.h>
#include <string.h>

int
main (int argc, char *argv[])
  {
//  printf ("\nContador argc:%d  String no Argv:%c\n", argc, argv[2][1]);
//  int k = atoi(argv[1]);
//  int j = k + 1;
//  printf ("\nargumento 1:%d\nj:%d\n", k, j);
  char *A = GetString();
  printf ("\n%s \n", A);

  int n = strlen (A);
  printf ("o Comprimento da string é:%d\n", n);

}
