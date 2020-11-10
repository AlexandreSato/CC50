//Programa para testar a captura de teclas direcionais do teclado by sato_alexandre@hotmail.com em 09/11/2020


#include <stdio.h>
#include <cc50.h>
#include <ncurses.h>

int
main (void)
{

	initscr();
	clear();
	noecho();
	cbreak(); //Desabilitar linha de buffer. Passa em tudo.
	int ch = getch();

	while (true)
	{
		ch = getch();

		if (ch == 'q')
		{
			endwin();
			return 0;
		}
		if (ch == 'w')
		{
			printf ("Tecla 'w' pressionada\n");
		}

		if (ch == 's')
		{
			mvprintw (0, 0, "Tecla 's' pressionada");
//			clrtoeol();
//			refresh();
		}
	}
}


