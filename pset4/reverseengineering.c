/*Programa para crackear a memória da máquina, acessando o que não deveria (teoricamente)
 *Por: Alexandre Nobuharu Sato em 24/12/2020 */
#include <stdio.h>
#include <cc50.h>
#include <string.h>

void
main(void)
{
	printf("\nTestando segmentation fault (stack overflow)\n");
	char * PETER = "Peter";
	int SIZE = strlen(PETER);
	printf("A quantidade de caracteres é:%d\n", SIZE);
	for (int i=0; i<10; i++)
		printf("[%d]:%c ",i, PETER[i]);
	printf("\n");

	*PETER[5] = 1;
	SIZE = strlen(PETER);
	printf("A quantidade de caracteres é:%d\n", SIZE);
}
