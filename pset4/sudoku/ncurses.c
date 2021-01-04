/*Programa para aprender a utilizar Ncurses por Alexandre Nobuharu Sato em 24/12/2020 */
#include <ncurses.h>
#include <unistd.h>

int
main(void)
{
	//Initialize the screen and set up memory and clears the screen
	initscr();
/*
	int x, y;
	x = y = 10;

	move (20, 40);

	printw("O hai World!");
	usleep (100 * 1000); //100ms
*/

//	refresh();
	int height, width, x_init, y_init;
	height = 10;
	width = 20;
	x_init = 20;
	y_init = 40;

	WINDOW *win = newwin(height, width, y_init, x_init);
	refresh();

	box(win, 0, 0);
	wrefresh(win);


	int c = getch();

	endwin();
	//dealocates memory and end ncurses
	return 0;
}

