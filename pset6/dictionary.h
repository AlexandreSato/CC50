/****************************************************************************
 * dictionary.h
 *
 * CC50
 * Pset 6
 *
 * Declares a dictionary's functionality.
 * 
 * Alexandre Nobuharu Sato, Ribeirão Pires - SP 27 de abril de 2021
 ***************************************************************************/

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>


// maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45


/*
 * LINKED LIST NODE STRUCT FOR LOAD DICT IN TO MEMORY
 */

typedef struct node
{
    bool end;
    struct node *son[27];    
}node;


/*
 * Returns true if word is in dictionary else false.
 */

bool check(const char *word);


/*
 * Loads dict into memory.  Returns true if successful else false.
 */

bool load(const char *dict);


/*
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */

unsigned int size(void);


/*
 * Unloads dictionary from memory.  Returns true if successful else false.
 */

bool unload(void);


#endif // DICTIONARY_H
