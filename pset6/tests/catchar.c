//Testing captch char typed on keyboard
// Alexandre Nobuharu Sato, São Bernardo do Campo - SP, 14 de abril de 2021

#include <stdio.h>

void
main(void)
{
	printf("Type something\n");
	int c = fgetc(stdin);
	printf("U typed: %d\n", c);
	printf("Converting binaries in lower case: %d\n", c | 0x20); //0x20 is 00100000 bin
	printf("Converting with binaries 'A' begining in 1, 'B' in 2, etc: %d\n", c & 0x9f); //0x9e is 10011111 bin
}

