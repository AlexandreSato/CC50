///*Programa para aprender a utilizar Ncurses por Alexandre Nobuharu Sato em 24/12/2020 */
//ALT + A selecionar, ALT + 3 comentar, ALT + ] ir para começo/final de parenteses colchetes ou chaves

#include <ncurses.h>
#include <unistd.h>
#include <ctype.h>

//Macro for processing CTRL characters
#define CTRL(x)		((x) & ~0140)

int
main(void)
{
	//Initialize the screen and set up memory and clears the screen
	initscr();
	keypad(stdscr, TRUE);
	cbreak();
	noecho();
	nonl();

	int ch = getch();

	clear();
	printw("\nDigite uma tecla\n");
	ch = getch();
//	ch = toupper(ch);


	if (ch == KEY_DOWN)
		printw ("\nVocê pressionou key_down\n");

	switch(ch)
	{
		case KEY_UP:
		printw ("\nVocê pressionou key_up\n");
		break;

		case CTRL('A'):
		printw ("\nVocê pressionou CTRL+A\n");
		break;
	}

	getch();

	endwin();
	//dealocates memory and end ncurses
	return 0;
}


//	int height, width, x_init, y_init;
//	height = 10;
//	width = 20;
//	x_init = 20;
//	y_init = 40;
//
//	WINDOW *win = newwin(height, width, y_init, x_init);
//	refresh();
//
//	box(win, 0, 0);
//	wrefresh(win);
