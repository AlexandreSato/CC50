/****************************************************************************
 * dictionary.c
 *
 * CC50
 * Pset 6
 *
 * Implements a dictionary's functionality.
 * By: Alexandre Nobuharu Sato, Ribeirão Pires-SP 27 de abril de 2021
 ***************************************************************************/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h> //for malloc

#include "dictionary.h"

int Size = 0; //number of words in dictionary

/*
 * Returns true if word is in dictionary else false.
 */

bool
check(const char *word)
{
    // TODO
    return false;
}


/*
 * Loads dict into memory.  Returns true if successful else false. Begins 2021/04/27
 */

bool
load(const char *dict)
{
    FILE *fp = fopen(dict, "r");
    if (fp == NULL)
    {
        unload();
        return false;
    }
    
    struct node *dad = NULL;
    dad = (struct  node *) malloc(sizeof(struct node));

    dad->end = true;
    
    return true;
}


/*
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */

unsigned int
size(void)
{
    if (Size != 0) 
        return Size;
    return 0;
}


/*
 * Unloads dictionary from memory.  Returns true if successful else false.
 */

bool
unload(void)
{
    // TODO
    return false;
}
