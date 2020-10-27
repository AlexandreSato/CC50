all: crack beer caesar vigenere

crack: crack.c
	gcc -ggdb -std=c99 -Wall -Werror -Wformat=0 -o crack crack.c -lcc50 -lcrypt

beer: beer.c
	gcc -ggdb -std=c99 -Wall -Werror -Wformat=0 -o beer beer.c -lcc50 -lm

caesar: caesar.c
	gcc -ggdb -std=c99 -Wall -Werror -Wformat=0 -o caesar caesar.c -lcc50 -lm
	
vigenere: vigenere.c
	gcc -ggdb -std=c99 -Wall -Werror -Wformat=0 -o vigenere vigenere.c -lcc50 -lm
