 /***************************************************************************
 * fifteen.c
 *
 * CC50
 * Pset 3
 *
 * Implements The Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 *
 * Aluno: Alexandre Nobuharu Sato em 07/11/2020 sato_alexandre@hotmail.com
 ***************************************************************************/

#define _XOPEN_SOURCE 500

#include <cc50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


// constants
#define DIM_MIN 3
#define DIM_MAX 9


// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;


// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);


int
main(int argc, char *argv[])
{
    // greet user with instructions
    greet();

    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: %s d\n", argv[0]);
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %d x %d and %d x %d, inclusive.\n",
         DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }

    // that's all folks
    return 0;
}


/*
 * Clears screen using ANSI escape sequences.
 */

void
clear(void)
{
    printf("\033[2J");//Clear Screen
    printf("\033[%d;%dH", 15, 0);//Move the draw
    printf("\033[1;93m");//Change Colors
}


/*
 * Greets player.
 */

void
greet(void)
{
    clear();
    printf("WELCOME TO THE GAME OF FIFTEEN\nBEM  VINDO  AO  JOGO  DOS  QUINZE\n");
    usleep(2000000);
}


/*
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */

void
init(void)
{
	 // TODO Ok! in 08/11/2020, imputing tiles on the board
	int TILE = d*d -1;
	for (int i=0; i<d; i++)
	{
		for (int j=0; j<d; j++)
		{
			if (d*d %2 == 0 && i == d -1 && j == d -3)//inverting the 2 with 1 at the end of board
			{
				board[i][j]= 1;
				TILE--;
			}
			else if (d*d %2 == 0 && i == d -1 && j == d -2) //inverting the 2 with 1 at the end of board
			{
				board[i][j]= 2;
				TILE--;
			}
			else
			{
				board[i][j]= TILE;
				TILE--;
			}
		}
	}

}


/* 
 * Prints the board in its current state.
 */

void
draw(void)
{
	// TODO Ok! in 08/11/2020, printing the board
	for (int i=0; i<d; i++)
	{
		for (int j=0; j<d; j++)
		{
			if (board[i][j] == 0)
				printf ("%5c", 95);//printing "-" character
			else
				printf ("%5d", board[i][j]);
		}
		printf ("\n\n\n");
	}
	printf ("\n\n");
}


/* 
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */

bool
move(int tile)
{
    // TODO Ok! in 09/11/2020
	int I_TALE_POSITION, J_TALE_POSITION; //Index positions of the tile on the array
	int I_GAP, J_GAP; //Index positions of the Gap    char "_"95 << int'0'
	for (int i=0; i<d; i++)//Searching TILE and GAP postions on the array
	{
		for (int j=0; j<d; j++)
		{
			if (board[i][j] == tile)
			{
				I_TALE_POSITION = i;
				J_TALE_POSITION = j;
			}
			if (board[i][j] == 0)
			{
				I_GAP = i;
				J_GAP = j;
			}
		}
	}

	if ((abs(I_TALE_POSITION-I_GAP)==0&&abs(J_TALE_POSITION-J_GAP)==1) || (abs(I_TALE_POSITION-I_GAP)==1&&abs(J_TALE_POSITION-J_GAP)==0))
	{
		board[I_GAP][J_GAP] = board[I_TALE_POSITION][J_TALE_POSITION];
		board[I_TALE_POSITION][J_TALE_POSITION] = 0;
		return true;
	}
	else
		return false;
}

/*
 * Returns true if game is won (i.e., board is in winning configuration),
 * else false.
 */

bool
won(void)
{
    // TODO Ok!! in 09/11/2020
	int TEST = 1;
	for (int i=0; i<d; i++)
	{
		for (int j=0; j<d; j++)
		{
			if (i==d-1 && j==d-1)
				TEST = 0; //last position
			if (board[i][j] != TEST)
			{
			return false;
			break;
			}
			TEST++;
		}
	}


    return true;
}
