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


   //binary search, DONE in 01/11/2020
	int LEFT = 0;
	int RIGTH = n;
	int DELTA =  -LEFT  +RIGTH;
	while (DELTA > 1)
	{
		DELTA =  -LEFT  +RIGTH;
		int INCREMENT = DELTA/2 ;
		int POSITION = LEFT + INCREMENT;
		printf ("\n[%d] %d", POSITION, array[POSITION]);
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
  // TODO: implement an O(n) sort, algorithm Counting Sort , Ok in 10/11/2020
	#define ARRAY_MAX_SIZE  100000
	int VECTOR[ARRAY_MAX_SIZE];
	for (int i=0; i<ARRAY_MAX_SIZE; i++)
	{
		VECTOR[i] = 0;//Zeroing all the elements of VECTOR the suport array
	}

	for (int i=0; i<n; i++)
	{
		VECTOR[values[i]]= VECTOR[values[i]] +1;//Counting repetions
	}
/*
	printf ("\n\nSupport Vector\n");
	for (int i=0; i<ARRAY_MAX_SIZE; i++)
	{
		printf ("[%d]%d  ", i, VECTOR[i]);//printing result in the support vector
	}
	printf ("\nSupport Vector\n\n");
*/
	int k = 0;
	for (int i=0; i<ARRAY_MAX_SIZE; i++)//outputing sort in the "values" array
	{
		if (VECTOR[i] !=0)
		{
			for(int j=0; j<VECTOR[i]; j++)
			{
				values[k] = i ;
				k++ ;
			}
		}
	}
	return;
}
