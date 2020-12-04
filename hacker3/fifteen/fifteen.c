 /***************************************************************************
 * fifteen.c
 *
 * CC50
 * Pset 3 ! HACKER VERSION !  Releases: Randomness and GOD MODE
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
 * Aluno: Alexandre Nobuharu Sato em 18/11/2020 sato_alexandre@hotmail.com
 ***************************************************************************/

#define _XOPEN_SOURCE 500

#include <cc50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>


// constants
#define DIM_MIN 3
#define DIM_MAX 9
#define SHUFFLE 100000


// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;


// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile); //line250
bool won(void);
void god(void);//Hacker Versions | line342
void begin_god(int tile, int i_destin, int j_destin);
void begin_first_engage(int d, int i);
void end_first_engage(int d, int i);


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
	int tile;
	char *STRING = GetString();
	if (!strncmp(STRING, "god", 3)) //Invoking the GOD mode cheat
	{
		god();
	}
	if (atoi(STRING) != 0)
        {
		tile = atoi(STRING);

        	// move if possible, else report illegality
        	if (!move(tile))
        	{
            		printf("\nIllegal move.\n");
	            	usleep(500000);
        	}

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
    printf("WELCOME TO THE GAME OF FIFTEEN\nBEM  VINDO  AO  JOGO  DOS  QUINZE\n  por: Alexandre Nobuharu Sato\n");
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

	//Introducing randomness
	int I_GAP = d -1, J_GAP = d -1;
	srand( (unsigned int) time(NULL));
	int i = SHUFFLE, MOVEMENT;
	while ( i > 0 )
	{
		MOVEMENT = rand() % 4; // 0 = up       1 = right      2 = down      3 = left
		if (MOVEMENT == 0 && I_GAP != 0)//up
		{
			board[I_GAP][J_GAP] = board[I_GAP -1][J_GAP];
			board[I_GAP -1][J_GAP] = 0;
			I_GAP = I_GAP -1;
			i--;
		}
		if (MOVEMENT == 1 && J_GAP != d -1)//right
		{
			board[I_GAP][J_GAP] = board[I_GAP][J_GAP +1];
			board[I_GAP][J_GAP +1] = 0;
			J_GAP = J_GAP +1;
			i--;
		}

		if (MOVEMENT == 2 && I_GAP != d -1)//down
		{
			board[I_GAP][J_GAP] = board[I_GAP +1][J_GAP];
			board[I_GAP +1][J_GAP] = 0;
			I_GAP = I_GAP +1;
			i--;
		}
		if (MOVEMENT == 3 && J_GAP != 0)//left
		{
			board[I_GAP][J_GAP] = board[I_GAP][J_GAP -1];
			board[I_GAP][J_GAP -1] = 0;
			J_GAP = J_GAP -1;
			i--;
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

	if (I_TALE_POSITION == I_GAP)//Horizontal
	{
		int JDELTA = J_TALE_POSITION - J_GAP;
		int INCREMENT = JDELTA/abs(JDELTA);
		for (int i = 0; i < abs(JDELTA); i++)
		{
			board[I_GAP][J_GAP] = board[I_GAP][J_GAP +INCREMENT];
			board[I_GAP][J_GAP +INCREMENT] = 0;
			J_GAP = J_GAP +INCREMENT;
			clear();
			draw();
			usleep(500000);
		}

		return true;
	}


	if (J_TALE_POSITION == J_GAP)//Vertical
	{
		int IDELTA = I_TALE_POSITION - I_GAP;
		int INCREMENT = IDELTA/abs(IDELTA);
		for (int i = 0; i < abs(IDELTA); i++)
		{
			board[I_GAP][J_GAP] = board[I_GAP +INCREMENT][J_GAP];
			board[I_GAP +INCREMENT][J_GAP] = 0;
			I_GAP = I_GAP +INCREMENT;
			clear();
			draw();
			usleep(500000);
		}

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



void
god(void)
{
	printf("\n CHAMOU GOD MODE !\n");
	for(int i = 0, TALE = 1; i < d - 2; i++)//Algoritmo até a antepenúltima linha
	{
		for(int j = 0, count_first_engage = 0; j < d; j++, TALE++)
		{
			if(j == d -1 && board[i][j] != TALE)
			{
				begin_first_engage(d , i);
				count_first_engage = 1;
			}
			if(TALE != d * d && board[i][j] != TALE)
				begin_god(TALE, i, j);
			if(j == d -1 && count_first_engage == 1)
			{
				end_first_engage(d, i);
				count_first_engage = 0;
			}
		}
	}

	/*
	 *Resolvendo as duas últimas linhas
	 */
	for (int count = 0, J_GAP; count < d -2; count++)
	{
		begin_god(d * (d -2) +1 +count/*Primeiro argumento é "Tale"*/, d -1 /*Segundo argumento é i_destin ou seja a penúltima linha*/, d -1 /*d -1 é a última coluna da direita*/);
		begin_god(d * (d -1) +1 +count/*Primeiro argumento é "Tale"*/, d -2 /*Segundo argumento é i_destin ou seja a penúltima linha*/, 0 +count/*0 é a coluna da esquerda*/);
		move(board[d -1][1 +count]);
		begin_god(d * (d -2) +1 +count/*Primeiro argumento é "Tale"*/, d -2 /*Segundo argumento é i_destin ou seja a penúltima linha*/, 1 +count/*0 é a coluna da esquerda*/);
		for (int i=0; i<d; i++)//Searching GAP and "1" tale positions on the array
		{
			for (int j=0; j<d; j++)
			{
				if (board[i][j] == 0)
					J_GAP = j;
			}
		}
		move(board[d -1][J_GAP]);//Posicionando o vazio na linha de baixo
		move(board[d -1][0 +count]);//Mandando vazio para a primeira coluna da esquerda
		move(board[d -2][0 +count]);//Subindo uma casa
		move(board[d -2][1 +count]);//Jogando uma para direita
	}


	while (true)//Girar o último quadrante para a configuração correta
	{
		move(board[d -2][d -1]);
		move(board[d -1][d -1]);
		if (won())
			break;
		move(board[d -1][d -2]);
		move(board[d -2][d -2]);
	}

	return;
}

void
begin_god(int tile, int i_destin, int j_destin)
{
	int I_GAP, J_GAP, I_TALE, J_TALE;
	for (int i=0; i<d; i++)//Searching GAP and "1" tale positions on the array
	{
		for (int j=0; j<d; j++)
		{
			if (board[i][j] == 0)
			{
				I_GAP = i;
				J_GAP = j;
			}
			if (board[i][j] == tile)
			{
				I_TALE = i;
				J_TALE = j;
			}
		}
	}

	if (J_TALE != j_destin) //POSICIONANDO A PEÇA NA COLUNA "j_destin"
	{

		int TEMP = j_destin - J_TALE;
		if (TEMP != 0)
		{
			int INCREMENT = TEMP/abs(TEMP);
			for(int i = 0; i < abs(TEMP); i++)
			{
				if (I_GAP == i_destin && J_TALE < J_GAP)//Para não bagunçar quando o vazio está na primeira linha e a peça a esquerda
				{
					board[I_GAP][J_GAP] = board[I_GAP +1][J_GAP];//Swap de Gap com a peça de baixo
					board[I_GAP +1][J_GAP] = 0;
					I_GAP = I_GAP +1;
					clear();
					draw();
					usleep(500000);
				}
				if (I_GAP == I_TALE)//se o vazio está na mesma linha
				{
					if(I_TALE == d -1)//Se a peça está na última linha
					{
						board[I_GAP][J_GAP] = board[I_GAP -1][J_GAP];//Swap do Gap com a peça de cima
						board[I_GAP -1][J_GAP] = 0;
						I_GAP = I_GAP -1;
					}
					else
					{
						board[I_GAP][J_GAP] = board[I_GAP +1][J_GAP];//Swap de Gap com a peça de baixo
						board[I_GAP +1][J_GAP] = 0;
						I_GAP = I_GAP +1;
					}
					clear();
					draw();
					usleep(500000);
				}
				int JDELTA = (J_TALE +INCREMENT) - J_GAP;//Movendo horizontalmente a esquerda ou a direita da peça
				if (JDELTA != 0)
				{
					int INCREMENT1 = JDELTA/abs(JDELTA);
					for (int i = 0; i < abs(JDELTA); i++)
					{
						board[I_GAP][J_GAP] = board[I_GAP][J_GAP +INCREMENT1];
						board[I_GAP][J_GAP +INCREMENT1] = 0;
						J_GAP = J_GAP +INCREMENT1;
						clear();
						draw();
						usleep(500000);
					}
				}
				int IDELTA = I_TALE - I_GAP;//Movendo verticalmente na altura da peça
				if (IDELTA != 0)
				{
					int INCREMENT2 = IDELTA/abs(IDELTA);
					for (int i = 0; i < abs(IDELTA); i++)
					{
						board[I_GAP][J_GAP] = board[I_GAP +INCREMENT2][J_GAP];
						board[I_GAP +INCREMENT2][J_GAP] = 0;
						I_GAP = I_GAP +INCREMENT2;
						clear();
						draw();
						usleep(500000);
					}
				}
				board[I_GAP][J_GAP] = board[I_GAP][J_GAP -INCREMENT]; //Swap com a peça à direita ou à esquerda
				board[I_GAP][J_GAP -INCREMENT] = 0;
				J_TALE = J_GAP;
				J_GAP = J_GAP -INCREMENT;
				clear();
				draw();
				usleep(500000);
			}
		}
	}//FIM POSICIONANDO A PEÇA NA COLUNA "j_destin"

	if (I_TALE != i_destin) //POSICIONANDO A PEÇA NA LINHA "i_destin"
	{

		if (I_TALE == i_destin +1 && J_GAP < j_destin && j_destin != d -1)//Para não bagunçar o que já foi arrumado acima e a esquerda
		{
			board[I_GAP][J_GAP] = board[I_GAP +1][J_GAP];//Swap de Gap com a peça de baixo
			board[I_GAP +1][J_GAP] = 0;
			I_GAP++;
			clear();
			draw();
			usleep(500000);
			board[I_GAP][J_GAP] = board[I_GAP][J_GAP +1]; //Swap com a peça da direita
			board[I_GAP][J_GAP +1] = 0;
			J_GAP++ ;
			clear();
			draw();
			usleep(500000);
		}


		int TEMP = i_destin - I_TALE;
		if (TEMP != 0)
		{
			int INCREMENT = TEMP/abs(TEMP);
			for(int i = 0; i < abs(TEMP); i++)
			{
				if (J_GAP == J_TALE && I_GAP > I_TALE)//se o vazio está na abaixo da peça e na mesma coluna
				{
					if(J_TALE == d -1)//Se a peça está na última coluna
					{
						board[I_GAP][J_GAP] = board[I_GAP][J_GAP -1];//Swap do Gap com a peça da esquerda
						board[I_GAP][J_GAP -1] = 0;
						J_GAP = J_GAP -1;
					}
					else
					{
						board[I_GAP][J_GAP] = board[I_GAP][J_GAP +1];//Swap de Gap com a peça da direita
						board[I_GAP][J_GAP +1] = 0;
						J_GAP = J_GAP +1;
					}
					clear();
					draw();
					usleep(500000);
				}
				int IDELTA = (I_TALE +INCREMENT) - I_GAP;//Movendo verticalmente acima ou abaixo da peça
				if (IDELTA != 0)
				{
					int INCREMENT1 = IDELTA/abs(IDELTA);
					for (int i = 0; i < abs(IDELTA); i++)
					{
						board[I_GAP][J_GAP] = board[I_GAP +INCREMENT1][J_GAP];
						board[I_GAP +INCREMENT1][J_GAP] = 0;
						I_GAP = I_GAP +INCREMENT1;
						clear();
						draw();
						usleep(500000);
					}
				}
				int JDELTA = J_TALE - J_GAP;//Movendo horizontalmente acima da peça
				if (JDELTA != 0)
				{
					int INCREMENT2 = JDELTA/abs(JDELTA);
					for (int i = 0; i < abs(JDELTA); i++)
					{
						board[I_GAP][J_GAP] = board[I_GAP][J_GAP +INCREMENT2];
						board[I_GAP][J_GAP +INCREMENT2] = 0;
						J_GAP = J_GAP +INCREMENT2;
						clear();
						draw();
						usleep(500000);
					}
				}
				board[I_GAP][J_GAP] = board[I_GAP -INCREMENT][J_GAP]; //Swap com a peça a baixo (ou acima)
				board[I_GAP -INCREMENT][J_GAP] = 0;
				I_TALE = I_GAP;
				I_GAP = I_GAP -INCREMENT;
				clear();
				draw();
				usleep(500000);
			}
		}
	}//FIM POSICIONANDO A PEÇA NA LINHA "i_destin"
	return;
}

/*
 * Função para puxar o trem de números para a esquerda, proporcionando uma coluna de liberdade j = d -1
 */
void
begin_first_engage(int d, int i)
{
	int I_GAP, J_GAP;
	for (int i=0; i<d; i++)//Searching GAP and "1" tale positions on the array
	{
		for (int j=0; j<d; j++)
		{
			if (board[i][j] == 0)
			{
				I_GAP = i;
				J_GAP = j;
			}
		}
	}

	if (board[i +2][0] == d * (i +1))//Correção no algoritmo quando o caso da peça d*i estiver imediatamente abaixo e na coluna da esquerda
	{
		move(board[i +2][J_GAP]);//Swap com a peça de baixo
		move(d * (i +1));//Tirando o caso d*i da coluna da esquerda proporcionando assim liberdade mínima de "j = 1" para o movimento de begin_god()
	}

	if (I_GAP != i +1)
		move(board[i +1][J_GAP]);

	move(board[i +1][0]);//Swap com a peça da esquerda
	move(board[i][0]);//Swap com a peça de cima
	move(board[i][d -2]);//Swap com a peça da direita

}

/*
 * Função para puxar o trem de números para a direita, fechando a coluna de liberdade j = d -1
 */
void
end_first_engage(int d, int i)
{
	int I_GAP = i +1;
	int J_GAP = d -1;

	board[I_GAP][J_GAP] = board[I_GAP][J_GAP -1]; //Swap com a peça da esquerda
	board[I_GAP][J_GAP -1] = 0;
	J_GAP-- ;
	clear();
	draw();
	usleep(500000);

	board[I_GAP][J_GAP] = board[I_GAP -1][J_GAP]; //Swap com a peça de cima
	board[I_GAP -1][J_GAP] = 0;
	I_GAP-- ;
	clear();
	draw();
	usleep(500000);

	for (int j = 0; j < d -2; j++)
	{
		board[I_GAP][J_GAP] = board[I_GAP][J_GAP -1]; //Swap com a peça da esquerda
		board[I_GAP][J_GAP -1] = 0;
		J_GAP-- ;
		clear();
		draw();
		usleep(500000);
	}

	board[I_GAP][J_GAP] = board[I_GAP +1][J_GAP];//Swap de Gap com a peça de baixo
	board[I_GAP +1][J_GAP] = 0;
	I_GAP++;
	clear();
	draw();
	usleep(500000);

}

