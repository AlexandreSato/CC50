/**************************************************************************** 
 * helpers.c
 *
 * CC50
 * Pset 3
 *
 * Helper functions for Problem Set 3.
 *
 * Aluno: sato_alexandre@hotmail.com em 30/10/2020
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
    for ( int i = 0; i < n; i++) { //printing the numbers before sort
	printf ("%d\n", values[i]);
    }

    //sorting the numbers
    int SMALLEST = values[0];
    for (int j = 0; j < (n - 1); j++) { //find the smallest number of the array
    	if ( values[j] < SMALLEST ) {
	SMALLEST = values[j];
	}
    }
    printf ("\nSMALLEST: %d\n", SMALLEST);
    return;
}
