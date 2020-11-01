/**************************************************************************** 
 * helpers.c
 *
 * CC50
 * Pset 3
 *
 * Helper functions for Problem Set 3.
 *
 * Aluno: sato_alexandre@hotmail.com em 31/10/2020
 ***************************************************************************/

#include <cc50.h>
#include <stdio.h>

#include "helpers.h"


/*
 * Returns true if value is in array of n values, else false.
 */

bool
search(int value, int array[], int n)
{
    // TODO: re-implement as binary search , Start Work in 01/11/2020
/*    for (int i = 0; i < n; i++)  //linear search
        if (array[i] == value)
            return true;
    return false;*/


   //binary search
	int LEFT = 0;
	int RIGTH = n;
	int DELTA =  -LEFT  +RIGTH;
	while (DELTA != 0)
	{
		DELTA =  -LEFT  +RIGTH;
		int INCREMENT = DELTA/2 +0.5;
		int POSITION = LEFT + INCREMENT;
		if (array[POSITION] == value)
		{
			printf ("\n needle %d found in [%d] position of array\n", array[POSITION], POSITION);
			return true;
		}
		if (array[POSITION] > value)
		{
		RIGTH = POSITION;
		}
		else
		{
		LEFT = POSITION;
		}
	}
	return false;
}


/*
 * Sorts array of n values.
 */

void
sort(int values[], int n)
{
    // TODO: implement an O(n^2) sort , OK implemented in 31/10/2020
    for (int k = 0; k < n; k++)
    {
	int SMALLEST = k;
	for (int j = k; j < n; j++)  //find the smallest number of the array
        {
	   if ( values[j] < values[SMALLEST])
	   SMALLEST = j;
	}
        int SWAP = values[k]; values[k] = values[SMALLEST]; values[SMALLEST] = SWAP; //Swaping the numbers
    }
    return;
}
