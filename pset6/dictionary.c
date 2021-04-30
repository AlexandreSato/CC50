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
#include <ctype.h> //for isalpha()

#include "dictionary.h"

node *dad; // head of the dict linked list
int Size = 0; // number of words in dictionary
void movefoward(node *node); //prototype for unload()

/*
 * Returns true if word is in dictionary else false.
 */

bool
check(const char *word)
{
    // TODO
    node *node = dad;
    for (int i = 0; word[i] != '\0'; i++)
    {
        if (node->son[word[i] & 0x9f] == NULL)
            return false;
        node = node->son[word[i] & 0x9f];
    }

    if (node->end)
        return true;
    else
        return false;
}


/*
 * Loads dict into memory.  Returns true if successful else false. begin in 2021/04/27 end in 2021/04/28
 */

bool
load(const char *dict)
{
    FILE *fp = fopen(dict, "r");
    if (fp == NULL)
    {
        return false;
    }
    
    struct node *node = NULL;
    node = (struct node *) malloc(sizeof(struct node));
    node->end = false;
    dad = node;// Save the inicial address

    int index = 0;
    for (int c = fgetc(fp); c != EOF; c = fgetc(fp)) 
    {
        if(isalpha(c) || (c == '\'' && index > 0))
        {
            if  (node->son[c & 0x9f] == NULL)
                node->son[c & 0x9f] = (struct node *) malloc(sizeof(struct node));
            node = node->son[c & 0x9f]; // & 0x9f convert char A, B, C... to 1, 2, 3...
            index++;
        }
        else if (index > 0)
        {
            node->end = true;
            node = dad; // return to the begin
            Size++;
            index = 0;
        }
    }
    
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
    node *node = dad;
    for (int i = 0; i < 28; i++)
        if (node->son[i] !=NULL)
           movefoward(node->son[i]);
    
    free(node);
    return true;
}

void
movefoward(node *node)
{
    for (int i = 0; i < 28; i++)
        if (node->son[i] != NULL)
            movefoward(node->son[i]);
    
    free(node);    
}