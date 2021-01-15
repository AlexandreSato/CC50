//Quando sscanf retorna 2 em vez de 1?
//Resposta, a função sscanf retorna a quantidade de argumentos completados com sucesso!
#include <stdio.h>

void
main(int argc, char const *argv[])
{
//    int TEMP;
//    char TEMP1;
    float TEMP2;
//    int TEST = sscanf(argv[1]," %d %c %f", &TEMP, &TEMP1, &TEMP2);
    int TEST = sscanf(argv[1],"  %f",   &TEMP2);
//    printf("\nTEST: %2d  |   int TEMP: %d  |  char TEMP1: %c | float TEMP2: %f\n", TEST, TEMP, TEMP1, TEMP2);
    printf("\nTEST: %2d  |   int TEMP:   |  char TEMP1:  | float TEMP2: %f\n", TEST,   TEMP2);
}
