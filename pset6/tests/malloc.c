//Programa para testar acessar indevidamente partes do heap
// By: Alexandre Nobuharu Sato, Ribeirão Pires 27 de abril de 2021
#include <stdio.h>
#include <stdlib.h>
#include <cc50.h>
#include <string.h>

void
main(void)
{
    char *str = malloc(10 * sizeof(char));
    printf ("Digite uma string:\n");
    // str = GetString();
    fscanf (stdin, "%s", str);
    printf ("Str is: %s\n", str);
    printf ("        ");
    
    for(int i = 0; i < strlen(str); i++)
        printf("%d", i);
    printf ("\nDigite CTRL + D para parar\n\n");
    
    str[strlen(str)] = 'X'; //H4xx0R 1337 

    for (int i = 0; i != INT_MAX; i = GetInt())
    {
        printf ("index[%d]  %c   %s    ", i, str[i], str - i);
    }

    printf ("\n");
    free(str);
}