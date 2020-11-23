// funções para auxiliar o jogo fifteen com o cheat GOD MODE, aluno:sato_alexandre@hotmail.com em 22/11/2020
#include <cc50.h>
#include <stdio.h>
#include "helpers.h"

void
god(int board, int d)
{
	printf("\n CHAMOU GOD MODE!\n");
	int I_GAP, J_GAP, I_ONE, J_ONE;
	for (int i=0; i<d; i++)//Searching GAP and "1" tale positions
	{
		for(int j=0; j<d; j++)
		{
			if(board[i][j] == 0)
			{
				I_GAP = i;
				J_GAP = j;
			}
			if(board[i][j] == 1)
			{
				I_ONE = i;
				J_ONE = j;
			}
		}
	}
	if (I_GAP < I_ONE)
	{
		int DELTA = J_ONE - J_GAP;//Colunas de diferença entre o vazio e a peça 1
		for(int i = 0, increment = DELTA/abs(DELTA); i < abs(DELTA); i++)
		{
			board[I_GAP][J_GAP] = board[I_GAP][J_GAP +increment];
			board[I_GAP][J_GAP +increment] = 0;
		}
	}
	GetString();
}
