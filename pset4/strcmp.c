//Teste de strcmp , Alexandre Nobuharu Sato, Jabaquara-SP 14/01/2021
#include <stdio.h>
#include <cc50.h>
#include <string.h>

void
main(void)
{
    printf ("\nDigite uma string A:");
    char *stringA = GetString();
    printf ("\nDigite uma string B:");
    char *stringB = GetString();
    //First
//    char *result = (!strcmp(stringA, stringB)) ? "IGUAIS" : "DIFERENTES";

    //Alternative
    char*result;
     if (!strcmp(stringA, stringB))
         result = "IGUAIS";
     else
         result = "DIFERENTES";    
  

      //Alternative 1 Dont work
//     char*result =
//        if (!strcmp(stringA, stringB))
//            "IGUAIS";
//        else
//            "DIFERENTES"; 

    printf ("\nAs strings são %s\n", result);
}

