//Teste para averiguar se fscanf coloca o '\0' no final da string
//Alexandre Nobuharu Sato, São Paulo, 26 de abril de 2021
#include <stdio.h>

void
main(void)
{
    FILE *fp = fopen("test.txt", "r");
    if (fp == NULL)
    {
        printf("Could not open.\n");
        return;
    }
    
    char str[20];
    int tmp;
    while (!feof(fp))
    {
        if (fscanf(fp, "%s %d", str, &tmp) == 1)
        {      
            
            for(int i = 0; i < 20 && str[i] != '\0'; i++)
                printf("%02d-%c  ", i, str[i]);
            
            printf("\n");
            printf("%s\n\n\n", str);
        }
    }
    
}
