/****************************************************************************
 * sudoku.c
 *
 * CC 50
 * Pset 4
 *
 * Implements the game of Sudoku. HACKER VERSION
 * Aluno: Alexandre Nobuharu Sato, em Jabaquara-SP 02/02/2021
 ***************************************************************************/

#include "sudoku.h"

#include <ctype.h>
#include <ncurses.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>


// macro for processing control characters
#define CTRL(x) ((x) & ~0140)

// size of each int (in bytes) in *.bin files
#define INTSIZE 4


// wrapper for our game's globals
struct
{
    // the current level
    char *level;

    // the game's board
    int board[9][9];

    // initial game board
    int init_board[9][9];

    // solved board for (H)int "Hacker Version"
    int solved_board[9][9];

    // the board's number
    int number;

    // the board's top-left coordinates
    int top, left;
    // the cursor's current location between (0,0) and (8,8)
    int y, x;
    // if is need redraw numbers
    bool redraw_numbers;
} g;


// prototypes
void draw_grid(void);
void draw_borders(void);
void draw_logo(void);
void draw_numbers(void);
void hide_banner(void);
bool load_board(void);
void handle_signal(int signum);
void log_move(int ch);
void redraw_all(void);
bool restart_game(void);
void show_banner(char *b);
void show_cursor(void);
void shutdown(void);
bool startup(void);
int  test(int entered_number);
bool won(void);
void solve_board(void);//Hacker Version
bool test_for_solve(int itered_number, int y, int x);//Hacker Version
bool solved(void);//Hacker Version
void brute_force(int y, int x);//Solve l337 is more difficult


/*
 * Main driver for the game.
 */

int
main(int argc, char *argv[])
{
    // define usage
    const char *usage = "Usage: sudoku n00b|l33t [#]\n";

    // ensure that number of arguments is as expected
    if (argc != 2 && argc != 3)
    {
        fprintf(stderr, usage);
        return 1;
    }

    // ensure that level is valid
    if (strcmp(argv[1], "debug") == 0)
        g.level = "debug";
    else if (strcmp(argv[1], "n00b") == 0)
        g.level = "n00b";
    else if (strcmp(argv[1], "l33t") == 0)
        g.level = "l33t";
    else
    {
        fprintf(stderr, usage);
        return 2;
    }

    // n00b and l33t levels have 1024 boards; debug level has 9
    int max = (strcmp(g.level, "debug") == 0) ? 9 : 1024;

    // ensure that #, if provided, is in [1, max]
    if (argc == 3)
    {
        // ensure n is integral
        char c;
        if (sscanf(argv[2], " %d %c", &g.number, &c) != 1)
        {
            fprintf(stderr, usage);
            return 3;
        }

        // ensure n is in [1, max]
        if (g.number < 1 || g.number > max)
        {
            fprintf(stderr, "That board # does not exist!\n");
            return 4;
        }

        // seed PRNG with # so that we get same sequence of boards
        srand(g.number);
    }
    else
    {
        // seed PRNG with current time so that we get any sequence of boards
        srand(time(NULL));

        // choose a random n in [1, max]
        g.number = rand() % max + 1;
    }

    // start up ncurses
    if (!startup())
    {
        fprintf(stderr, "Error starting up ncurses!\n");
        return 5;
    }

    // register handler for SIGWINCH (SIGnal WINdow CHanged)
    signal(SIGWINCH, (void (*)(int)) handle_signal);

    // start the first game
    if (!restart_game())
    {
        shutdown();
        fprintf(stderr, "Could not load board from disk!\n");
        return 6;
    }
    redraw_all();

    // let the user play!
    int ch;
    if_is_first_or_won: do
    {
        // refresh the screen
        refresh();

        // get user's input
        ch = getch();

        // capitalize input to simplify cases
        ch = toupper(ch);

        // process user's input
        switch (ch)
        {
            // start a new game
            case 'N':
                g.number = rand() % max + 1;
                if (!restart_game())
                {
                    shutdown();
                    fprintf(stderr, "Could not load board from disk!\n");
                    return 6;
                }
                break;

            // restart current game
            case 'R':
                if (!restart_game())
                {
                    shutdown();
                    fprintf(stderr, "Could not load board from disk!\n");
                    return 6;
                }
                break;

            // let user manually redraw screen with ctrl-L
            case CTRL('L'):
                redraw_all();
                break;

	   // lets arrow keys work
	   case KEY_UP:
		if (g.redraw_numbers == true)
		{
			 draw_numbers();
			 g.redraw_numbers = false;
		}
		g.y == 0? g.y = 8 : --g.y;
        	hide_banner();
		show_cursor();
		break;
	   case KEY_DOWN:
		if (g.redraw_numbers == true)
		{
			 draw_numbers();
			 g.redraw_numbers = false;
		}
		g.y == 8? g.y = 0 : ++g.y;
        	hide_banner();
		show_cursor();
		break;
	   case KEY_LEFT:
		if (g.redraw_numbers == true)
		{
			 draw_numbers();
			 g.redraw_numbers = false;
		}
		hide_banner();
		g.x == 0? g.x = 8 : --g.x;
		show_cursor();
		break;
	   case KEY_RIGHT:
		if (g.redraw_numbers == true)
		{
			 draw_numbers();
			 g.redraw_numbers = false;
		}
		g.x == 8? g.x = 0 : ++g.x;
        	hide_banner();
		show_cursor();
		break;
	  case KEY_BACKSPACE:
	  case KEY_DC:
		if (g.init_board[g.y][g.x] == 0)
		{
			g.board[g.y][g.x] = 0;
                	mvaddch(g.top + g.y + 1 + g.y/3, g.left + 2 + 2*(g.x + g.x/3), '.' );
                	refresh();
		}
		hide_banner();
		show_cursor();
		break;
        case 'H'://Hacker Edition
            if(has_colors())
                attron(COLOR_PAIR(PAIR_HINT));
            char temp[1];
            sprintf(temp, "%d", g.solved_board[g.y][g.x]);
            mvaddstr(g.top + g.y + 1 + g.y/3, g.left + 2 + 2*(g.x + g.x/3), temp);
            show_cursor();
            refresh();
            if(has_colors())
                attroff(COLOR_PAIR(PAIR_HINT));
            sleep(1); //whait 1 second
            draw_numbers();
            show_cursor();
            refresh();
            break;
        }

	//Enter Numbers on board
	if (isdigit(ch) && ch !=48 && g.init_board[g.y][g.x] == 0 && !test(ch - 48)) //If ch is digit, not zero, not comming on init board and possible
	{
		draw_numbers();
		hide_banner();
		if (g.init_board[g.y][g.x] == 0)
			g.board[g.y][g.x] = ch - 48;
		if (has_colors())
			attron(COLOR_PAIR(PAIR_PLAYNUMBER));
		char temp[1];
		sprintf(temp, "%d", ch - 48);
		mvaddstr(g.top + g.y + 1 + g.y/3, g.left + 2 + 2*(g.x + g.x/3), temp);
		refresh();
		if (has_colors())
			attroff(COLOR_PAIR(PAIR_PLAYNUMBER));
		show_cursor();
	        if (won())
	        {
			hide_banner();
			show_banner("Congrats ftw!");
			do
			{
				refresh();
				ch = getch();
				ch = toupper(ch);
				switch (ch)
				{
			            // start a new game
			            case 'N':
			                g.number = rand() % max + 1;
			                if (!restart_game())
			                {
			                    shutdown();
			                    fprintf(stderr, "Could not load board from disk!\n");
			                    return 6;
			                }
					hide_banner();
					show_cursor();
					goto if_is_first_or_won;
			                break;

			            // restart current game
			            case 'R':
			                if (!restart_game())
			                {
			                    shutdown();
			                    fprintf(stderr, "Could not load board from disk!\n");
			                    return 6;
			                }
					hide_banner();
					show_cursor();
					goto if_is_first_or_won;
			                break;
				}
			}
			while (ch != 'Q');
			goto end;
		}
	}

        // log input (and board's state) if any was received this iteration
        if (ch != ERR)
            log_move(ch);


    }
    while (ch != 'Q');

    // shut down ncurses
    end: shutdown();

    // tidy up the screen (using ANSI escape sequences)
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);

    // that's all folks
    printf("\nkthxbai!\n\n");
    return 0;
}


/*
 * Draw's the game's board.
 */

void
draw_grid(void)
{
    // get window's dimensions
    int maxy, maxx;
    getmaxyx(stdscr, maxy, maxx);

    // determine where top-left corner of board belongs
    g.top = maxy/2 - 7;
    g.left = maxx/2 - 30;

    // enable color if possible
    if (has_colors())
        attron(COLOR_PAIR(PAIR_GRID));

    // print grid
    for (int i = 0 ; i < 3 ; ++i )
    {
        mvaddstr(g.top + 0 + 4 * i, g.left, "+-------+-------+-------+");
        mvaddstr(g.top + 1 + 4 * i, g.left, "|       |       |       |");
        mvaddstr(g.top + 2 + 4 * i, g.left, "|       |       |       |");
        mvaddstr(g.top + 3 + 4 * i, g.left, "|       |       |       |");
    }
    mvaddstr(g.top + 4 * 3, g.left, "+-------+-------+-------+" );

    // remind user of level and #
    char reminder[maxx+1];
    sprintf(reminder, "   playing %s #%d", g.level, g.number);
    mvaddstr(g.top + 14, g.left + 25 - strlen(reminder), reminder);

    // disable color if possible
    if (has_colors())
        attroff(COLOR_PAIR(PAIR_GRID));
}


/*
 * Draws game's borders.
 */

void
draw_borders(void)
{
    // get window's dimensions
    int maxy, maxx;
    getmaxyx(stdscr, maxy, maxx);

    // enable color if possible (else b&w highlighting)
    if (has_colors())
    {
        attron(A_PROTECT);
        attron(COLOR_PAIR(PAIR_BORDER));
    }
    else
        attron(A_REVERSE);

    // draw borders
    for (int i = 0; i < maxx; i++)
    {
        mvaddch(0, i, ' ');
        mvaddch(maxy-1, i, ' ');
    }

    // draw header
    char header[maxx+1];
    sprintf(header, "%s     by: %s", TITLE, AUTHOR);
    mvaddstr(0, (maxx - strlen(header)) / 2, header);

    // draw footer
    mvaddstr(maxy-1, 1, "[N]ew Game   [R]estart Game   [H]int");
    mvaddstr(maxy-1, maxx-13, "[Q]uit Game");

    // disable color if possible (else b&w highlighting)
    if (has_colors())
        attroff(COLOR_PAIR(PAIR_BORDER));
    else
        attroff(A_REVERSE);
}


/*
 * Draws game's logo.  Must be called after draw_grid has been
 * called at least once.
 */

void
draw_logo(void)
{
    // determine top-left coordinates of logo
    int top = g.top + 2;
    int left = g.left + 30;

    // enable color if possible
    if (has_colors())
        attron(COLOR_PAIR(PAIR_LOGO));

    // draw logo
    mvaddstr(top + 0, left, "               _       _          ");
    mvaddstr(top + 1, left, "              | |     | |         ");
    mvaddstr(top + 2, left, " ___ _   _  __| | ___ | | ___   _ ");
    mvaddstr(top + 3, left, "/ __| | | |/ _` |/ _ \\| |/ / | | |");
    mvaddstr(top + 4, left, "\\__ \\ |_| | (_| | (_) |   <| |_| |");
    mvaddstr(top + 5, left, "|___/\\__,_|\\__,_|\\___/|_|\\_\\\\__,_|");

    // sign logo
    char signature[3+strlen(AUTHOR)+1];
    sprintf(signature, "by %s", AUTHOR);
    mvaddstr(top + 7, left + 35 - strlen(signature) - 1, signature);

    // disable color if possible
    if (has_colors())
        attroff(COLOR_PAIR(PAIR_LOGO));
}


/*
 * Draw's game's numbers.  Must be called after draw_grid has been
 * called at least once.
 */

void
draw_numbers(void)
{
    // iterate over board's numbers
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            // putting the number of the player with a different color on the board
            if (g.init_board[i][j] == 0 && g.board[i][j] != 0)
            {
                if (has_colors())
                    attron(COLOR_PAIR(PAIR_PLAYNUMBER));

                // determine char
                char c = (g.board[i][j] == 0) ? '.' : g.board[i][j] + '0';
                mvaddch(g.top + i + 1 + i/3, g.left + 2 + 2*(j + j/3), c);
                refresh();

                if (has_colors())
                    attroff(COLOR_PAIR(PAIR_PLAYNUMBER));
            }
            else
            {
                // determine char
                char c = (g.board[i][j] == 0) ? '.' : g.board[i][j] + '0';
                mvaddch(g.top + i + 1 + i/3, g.left + 2 + 2*(j + j/3), c);
                refresh();
            }



        }
    }
}


/*
 * Designed to handles signals (e.g., SIGWINCH).
 */

void
handle_signal(int signum)
{
    // handle a change in the window (i.e., a resizing)
    if (signum == SIGWINCH)
        redraw_all();

    // re-register myself so this signal gets handled in future too
    signal(signum, (void (*)(int)) handle_signal);
}


/*
 * Hides banner.
 */

void
hide_banner(void)
{
    // get window's dimensions
    int maxy, maxx;
    getmaxyx(stdscr, maxy, maxx);

    // overwrite banner with spaces
    for (int i = 0; i < maxx; i++)
        mvaddch(g.top + 16, i, ' ');
}


/*
 * Loads current board from disk, returning true iff successful.
 */

bool
load_board(void)
{
    // open file with boards of specified level
    char filename[strlen(g.level) + 5];
    sprintf(filename, "%s.bin", g.level);
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL)
        return false;

    // determine file's size
    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);

    // ensure file is of expected size
    if (size % (81 * INTSIZE) != 0)
    {
        fclose(fp);
        return false;
    }

    // compute offset of specified board
    int offset = ((g.number - 1) * 81 * INTSIZE);

    // seek to specified board
    fseek(fp, offset, SEEK_SET);

    // read board into memory
    if (fread(g.board, 81 * INTSIZE, 1, fp) != 1)
    {
        fclose(fp);
        return false;
    }

    // seek again to specified board
    fseek(fp, offset, SEEK_SET);

    // save the initial board into memory
    if (fread(g.init_board, 81 * INTSIZE, 1, fp) != 1)
    {
        fclose(fp);
        return false;
    }

    // load another board for solve, because we love the hacker edition
    fseek(fp, offset, SEEK_SET);
        if (fread(g.solved_board, 81 * INTSIZE, 1, fp) != 1)
    {
        fclose(fp);
        return false;
    }

    // w00t
    fclose(fp);
    return true;
}


/*
 * Logs input and board's state to log.txt to facilitate automated tests.
 */

void
log_move(int ch)
{
    // open log
    FILE *fp = fopen("log.txt", "a");
    if (fp == NULL)
        return;

    // log input
    fprintf(fp, "%d\n", ch);

    // log board
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            fprintf(fp, "%d", g.board[i][j]);
        fprintf(fp, "\n");
    }

    // that's it
    fclose(fp);
}


/*
 * (Re)draws everything on the screen.
 */

void
redraw_all(void)
{
    // reset ncurses
    endwin();
    refresh();

    // clear screen
    clear();

    // re-draw everything
    draw_borders();
    draw_grid();
    draw_logo();
    draw_numbers();

    // show cursor
    show_cursor();
}


/*
 * (Re)starts current game, returning true iff succesful.
 */

bool
restart_game(void)
{
    // reload current game
    if (!load_board())
        return false;

    // solve board for use (H)int button (Hacker Edition)
    solve_board();

    // redraw board
    draw_grid();
    draw_numbers();

    // get window's dimensions
    int maxy, maxx;
    getmaxyx(stdscr, maxy, maxx);

    // move cursor to board's center
    g.y = g.x = 4;
    show_cursor();

    // remove log, if any
    remove("log.txt");

    // w00t
    return true;
}


/*
 * Shows cursor at (g.y, g.x).
 */

void
show_cursor(void)
{
    // restore cursor's location
    move(g.top + g.y + 1 + g.y/3, g.left + 2 + 2*(g.x + g.x/3));
}


/*
 * Shows a banner.  Must be called after show_grid has been
 * called at least once.
 */

void
show_banner(char *b)
{
    // enable color if possible
    if (has_colors())
        attron(COLOR_PAIR(PAIR_BANNER));

    // determine where top-left corner of board belongs
    mvaddstr(g.top + 16, g.left + 64 - strlen(b), b);

    // disable color if possible
    if (has_colors())
        attroff(COLOR_PAIR(PAIR_BANNER));
}


/*
 * Shuts down ncurses.
 */

void
shutdown(void)
{
    endwin();
}


/*
 * Starts up ncurses.  Returns true iff successful.
 */

bool
startup(void)
{
    // initialize ncurses
    if (initscr() == NULL)
        return false;

    // prepare for color if possible
    if (has_colors())
    {
        // enable color
        if (start_color() == ERR || attron(A_PROTECT) == ERR)
        {
            endwin();
            return false;
        }

        // initialize pairs of colors
        if (init_pair(PAIR_BANNER, FG_BANNER, BG_BANNER) == ERR ||
            init_pair(PAIR_GRID, FG_GRID, BG_GRID) == ERR ||
            init_pair(PAIR_BORDER, FG_BORDER, BG_BORDER) == ERR ||
            init_pair(PAIR_LOGO, FG_LOGO, BG_LOGO) == ERR ||
            init_pair(PAIR_PLAYNUMBER, FG_PLAYNUMBER, BG_PLAYNUMBER) == ERR ||
	    init_pair(PAIR_REPEATEDNUMBER, FG_REPEATEDNUMBER, BG_REPEATEDNUMBER) == ERR ||
            init_pair(PAIR_HINT, FG_HINT, BG_HINT) == ERR)
        {
            endwin();
            return false;
        }
    }

    // don't echo keyboard input
    if (noecho() == ERR)
    {
        endwin();
        return false;
    }

    // disable line buffering and certain signals
    if (raw() == ERR)
    {
        endwin();
        return false;
    }

    // enable arrow keys
    if (keypad(stdscr, true) == ERR)
    {
        endwin();
        return false;
    }

    // wait 1000 ms at a time for input
    timeout(1000);

    // w00t
    return true;
}


/*
 * Testing if the number is valid 
 */

int
test(int entered_number)
{
	draw_numbers();
	int count_repetition = 0;
	//Testing in columns
	for (int i = 0; i < 9; i++)
	{
		if (i != g.y)
		{
			if (g.board[i][g.x] == entered_number)
			{
				hide_banner();
				show_banner("Repeated Number!");
				show_cursor();
				if (has_colors())
					attron(COLOR_PAIR(PAIR_REPEATEDNUMBER));
				char temp[0];
				sprintf(temp, "%d", entered_number);
				mvaddstr(g.top + g.y + 1 + g.y/3, g.left + 2 + 2*(g.x + g.x/3), temp);
				refresh();
				mvaddstr(g.top + i + 1 + i/3, g.left + 2 + 2*(g.x + g.x/3), temp);
				refresh();
				show_cursor();
				if (has_colors())
					attroff(COLOR_PAIR(PAIR_REPEATEDNUMBER));
				count_repetition++;
			}
		}
	}
	//Testing in rows
	for (int i = 0; i < 9; i++)
	{
		if (i != g.x)
		{
			if (g.board[g.y][i] == entered_number)
			{
				hide_banner();
				show_banner("Repeated Number!");
				show_cursor();
				if (has_colors())
					attron(COLOR_PAIR(PAIR_REPEATEDNUMBER));
				char temp[0];
				sprintf(temp, "%d", entered_number);
				mvaddstr(g.top + g.y + 1 + g.y/3, g.left + 2 + 2*(g.x + g.x/3), temp);
				refresh();
				mvaddstr(g.top + g.y + 1 + g.y/3, g.left + 2 + 2*(i + i/3), temp);
				refresh();
				show_cursor();
				if (has_colors())
					attroff(COLOR_PAIR(PAIR_REPEATEDNUMBER));
				count_repetition++;
			}
		}
	}
	//Testing in quadrant
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i != g.y % 3 && j != g.x % 3)//skipping the entered_number row and column
			{
				int offset_y = g.y / 3 * 3;
				int offset_x = g.x / 3 * 3;
				if (g.board[offset_y + i][offset_x + j] == entered_number)
				{
					hide_banner();
					show_banner("Repeated Number!");
					show_cursor();
					if (has_colors())
						attron(COLOR_PAIR(PAIR_REPEATEDNUMBER));
					char temp[0];
					sprintf(temp, "%d", entered_number);
					mvaddstr(g.top + g.y + 1 + g.y/3, g.left + 2 + 2*(g.x + g.x/3), temp);
					refresh();
					mvaddstr(g.top + (offset_y + i) + 1 + (offset_y + i)/3, g.left + 2 + 2*((offset_x + j) + (offset_x + j)/3), temp);
					refresh();
					show_cursor();
					if (has_colors())
						attroff(COLOR_PAIR(PAIR_REPEATEDNUMBER));
					count_repetition++;
				}
			}
		}
	}
	if (count_repetition > 0)
		 g.redraw_numbers = true;
	return count_repetition;
}


/*
 * If game is won
 */

bool
won(void)
{
	//testing if there is any empty
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if(g.board[i][j] == 0)
				return false;
		}
	}
	//testing if there any repetition in column
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			for (int k = 0; k < 9 ; k++)
			{
				if (k != j)
				{
					if (g.board[j][i] == g.board[k][i])
						return false;
				}
			}
		}
	}
	//testing if there any repetition in row
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			for (int k = 0; k < 9 ; k++)
			{
				if (k != j)
				{
					if (g.board[i][j] == g.board[i][k])
						return false;
				}
			}
		}
	}

	//Testing if there any repetition in quadrant
	for (int k = 0; k < 9; k++)//9 is all board
	{
		for (int l = 0; l < 9; l++)//9 is all board
		{
			for (int i = 0; i < 3; i++)//3 is just quadrant
			{
				for (int j = 0; j < 3; j++)//3 is just quadrant
				{
					if (i != k % 3 && j != l % 3)//skipping the same row and column
					{
						int offset_y = k / 3 * 3;
						int offset_x = l / 3 * 3;
						if (g.board[offset_y + i][offset_x + j] == g.board[k][l])
						{
							return false;
						}
					}
				}
			}

		}
	}


	return true;
}


/*
 * Hint using the solved board (Hacker Edition)
 */

void
solve_board(void)
{
    for (int count = 0; count < 89 && !solved(); count++)
    {
        for ( int i = 0; i < 9; i++)
        {
            for ( int j = 0; j < 9; j++)
            {
                if (g.solved_board[i][j] == 0)
                {
                    int count_repetitions = 0, tested_number;
                    for (int k = 1; k < 10; k++)
                    {
                        if (test_for_solve(k, i, j))
                        {
                            count_repetitions++;
                            tested_number = k;
                        }
                    }
                    if (count_repetitions == 1)
                    {
                        g.solved_board[i][j] = tested_number;
                    }
                }
            }
        }
    }
//    if (!solved())
//	brute_force(0, 0);
}


/*
 * Testing if the number itered for "solve_board()" is possible
 */

bool
test_for_solve(int itered_number, int y, int x)
{
	int count_repetition = 0;
	//Testing in columns
	for (int i = 0; i < 9; i++)
	{
		if (i != y)
		{
			if (g.solved_board[i][x] == itered_number)
			{
				count_repetition++;
			}
		}
	}
	//Testing in rows
	for (int i = 0; i < 9; i++)
	{
		if (i != x)
		{
			if (g.solved_board[y][i] == itered_number)
			{
				count_repetition++;
			}
		}
	}
	//Testing in quadrant
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i != y % 3 && j != x % 3)//skipping the entered_number row and column
			{
				int offset_y = y / 3 * 3;
				int offset_x = x / 3 * 3;
				if (g.solved_board[offset_y + i][offset_x + j] == itered_number)
				{
					count_repetition++;
				}
			}
		}
	}
	if (count_repetition > 0)
		return false;
	return true;
}


/*
 * Testing if the solved_board is really solved
 */

bool
solved(void)
{
	//testing if there is any empty
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if(g.solved_board[i][j] == 0)
				return false;
		}
	}
	//testing if there any repetition in column
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			for (int k = 0; k < 9 ; k++)
			{
				if (k != j)
				{
					if (g.solved_board[j][i] == g.solved_board[k][i])
						return false;
				}
			}
		}
	}
	//testing if there any repetition in row
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			for (int k = 0; k < 9 ; k++)
			{
				if (k != j)
				{
					if (g.solved_board[i][j] == g.solved_board[i][k])
						return false;
				}
			}
		}
	}

	//Testing if there any repetition in quadrant
	for (int k = 0; k < 9; k++)//9 is all board
	{
		for (int l = 0; l < 9; l++)//9 is all board
		{
			for (int i = 0; i < 3; i++)//3 is just quadrant
			{
				for (int j = 0; j < 3; j++)//3 is just quadrant
				{
					if (i != k % 3 && j != l % 3)//skipping the same row and column
					{
						int offset_y = k / 3 * 3;
						int offset_x = l / 3 * 3;
						if (g.solved_board[offset_y + i][offset_x + j] == g.solved_board[k][l])
						{
							return false;
						}
					}
				}
			}

		}
	}

	return true;
}


/*
 * Solving the board in recursive brute force
 */

void
brute_force( int y, int x)
{
	if(solved())
		return;
	if (g.init_board[y][x] == 0)
	{
		for (int tested_number = 1; tested_number <= 9; tested_number++)
		{
			if (test_for_solve(tested_number, y, x))
			{
				g.solved_board[y][x] = tested_number;
				if (x == 8)
				{
					y++;
					x = 0;
					brute_force(y, x);
				}
				else
				{
					x++;
					brute_force(y, x);
				}
			}
		}
		g.solved_board[y][x] = 0;
	}
	else
	{
		if (x == 8)
		{
			y++;
			x = 0;
			brute_force(y, x);
		}
		else
		{
			x++;
			brute_force(y, x);
		}
	}
}
