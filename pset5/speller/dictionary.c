#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "dictionary.h"


// size of hashtable
#define SIZE 1000000

// create nodes for linked list
typedef struct node
{
    char word[LENGTH+1];
    struct node* next;
}
node;

node* hashtable[SIZE] = {NULL};

int wcount = 0;

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
 int hash(const char *wor) 
{
    int len = strlen(wor);
    int hash = 0;
    char* word=malloc(sizeof(char)*LENGTH);
    for(int i = 0; i < len; i++)
    {
            word[i]=tolower(wor[i]);
            hash += word[i];
        
    }
    
    return hash % SIZE; 
}

bool load(const char* dictionary)
{
    // TODO
    FILE* fp = fopen(dictionary, "r");
    if (fp == NULL)
    {
        printf("unable to open file");
        return false;
    }
    
    char* word=malloc(sizeof(char)*LENGTH);
    
    // scan through the file, loading each word into the hash table
    while (fscanf(fp, "%s\n", word)!= EOF)
    {
        // increment dictionary size
        wcount++;
        
        // allocate memory for new word 
        node* node1 = malloc(sizeof(node));
        
        // put word in the new node
        strcpy(node1->word, word);
        
        // find what index of the array the word should go in
        int val = hash(word);
        
        // if empty insert
        if (hashtable[val] == NULL)
        {
            hashtable[val] = node1;
            node1->next = NULL;
        }
        
        // else change the next pointer to point to next node
        else
        {
            node1->next = hashtable[val];
            hashtable[val] = node1;
        }      
    }
    
    
    fclose(fp);
    return true;
}

/**
 * 
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // TODO
    int l=strlen(word);
    char *t=(char*)malloc( LENGTH*sizeof(char));
    for(int i = 0; i < l; i++)
        t[i] = tolower(word[i]);
    t[l] = '\0';
    
    int val = hash(t);
    
    if (hashtable[val] == NULL)
        return false;
    
    node* current = hashtable[val];
    while (current != NULL)
    {
        if (strcmp(t, current->word) == 0)
        return true;
        current = current->next;
    }
    free(t);
    return false;

}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    // return number of words
    return wcount;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    for(int pos=0;pos < SIZE;pos++)
    {
        if (hashtable[pos]!= NULL)
        {
            while(hashtable[pos] != NULL)
            {
                node* current = hashtable[pos];
                hashtable[pos] = current->next;
                free(current);
            }
            
        }
    }
    return true;
}