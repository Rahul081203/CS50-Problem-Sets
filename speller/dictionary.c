// Implements a dictionary's functionality
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Choose number of buckets in hash table
const unsigned int N = 676;

// Declaring global word count
int word_count = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Hashing the word
    unsigned int hash_val = hash(word);
    if (table[hash_val] == NULL)
    {
        return false;
    }
    else
    {
        node *cursor = table[hash_val];
        while (cursor != NULL)
        {
            if (strcasecmp(cursor -> word, word) == 0)
            {
                return true;
            }
            cursor = cursor -> next;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int sum = 0;
    for (int i = 0 ; i < strlen(word) ; i ++)
    {
        sum += tolower(word[i]);
    }
    int hash_val = sum % N;
    return hash_val;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Loading Dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("Could not open file.\n");
        return false;
    }
    char word[LENGTH + 1];
    bool success = false;
    while (fscanf(file, "%s", word) != EOF)
    {
        node *element = malloc(sizeof(node));
        strcpy(element -> word, word);
        element -> next = NULL;
        unsigned int hash_value = hash(word);
        if (table[hash_value] == NULL)
        {
            table[hash_value] = element;
        }
        else
        {
            element -> next = table[hash_value];
            table[hash_value] = element;
        }
        success = true;
        word_count += 1;
    }
    if (success)
    {
        fclose(file);
        return true;
    }
    else
    {
        return false;
    }
}


// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    int index = 0, unload = 0;
    while(index < N)
    {
        node *head = table[index];
        node *cursor = head;
        node *tmp = head;
        while (cursor != NULL)
        {
            cursor = cursor -> next;
            free(tmp);
            tmp = cursor;
        }
        index ++;
        unload = 1;
    }
    if (unload == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
