/***************************************************************************
 * generate.c
 *
 * CC50
 * Pset 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 *
 * Aluno: Alexandre Nobuharu Sato em 26/10/2020
 ***************************************************************************/
       
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIMIT 65536

int
main(int argc, char *argv[])
{
    // TODO: Test if more than two or three arguments
    if (argc != 2 && argc != 3)
    {
        printf("Usage: %s n [s]\n", argv[0]);
        return 1;
    }

    // TODO: Ensuring that the entry is transformed into an integer
    int n = atoi(argv[1]);

    /* TODO: Testing whether the seed of randomness has been reported,
    *        otherwise it will use time as seed */

    if (argc == 3)
        srand((unsigned int) atoi(argv[2]));
    else
        srand((unsigned int) time(NULL));

    // TODO: Print on the screen the numbers produced by the rest of the 
    //      of the division of the rand function by the constant LIMIT
    for (int i = 0; i < n; i++)
        printf("%d\n", rand() % LIMIT);

    // that's all folks
    return 0;
}
