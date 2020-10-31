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
    // TODO: re-implement as binary search
    for (int i = 0; i < n; i++)
        if (array[i] == value)
            return true;
    return false;
}


/*
 * Sorts array of n values.
 */

void 
sort(int values[], int n)
{
    // TODO: implement an O(n^2) sort
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
