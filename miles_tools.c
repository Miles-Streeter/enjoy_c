#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include "miles_tools.h"


// ###################################
// ##     DYNAMIC INTEGER ARRAY     ##
// ###################################

// Function creates and returns an integer dynamic array. Allocates memory for the array as well.
// Ideally this will stop me from referencing NULL values, but I'm sure there's a way.
// Returns zero if any mem allocs fail
iDarr *initiDarr(int startingLimit)
{
    // Allocating the memory for the array and creating a pointer to it.
    iDarr *tmpiDarr = malloc(sizeof(iDarr));
    if (tmpiDarr == NULL)
    {
        free(tmpiDarr);
        return 0;
    }

    // Allocating the memory for the array and checking for NULL
    tmpiDarr->array = malloc(startingLimit * sizeof(int));
    if (tmpiDarr->array == NULL)
    {
        free(tmpiDarr);
        printf("Failed to allocate memory to Integer Dynamic Array\n");
        return 0;
    }
    else
    {
        tmpiDarr->size = 0;
        tmpiDarr->limit = startingLimit;
    }

    return tmpiDarr;
}

// free function for iDarrs so I hopefully don't ever forget to free both the array and the struct
void freeiDarr(iDarr *inputArr)
{
    // This just ensures I can call this function even if I haven't allocated memory for the array yet. Which shouldn't happen
    if (inputArr->array != NULL)
    {
        free(inputArr->array);
        free(inputArr);
    }
    else
    {
        free(inputArr); // frees just the pointer if the array is NULL
    }
    
}

// Safe(?) function to append a number onto an iDarr Array.
// This exists so I don't forget to increment the size, or try to add data outside of the limit
// I should probably try to make a deletion function that shifts the data around so I can remove items
// TODO: above
void appendiDarr(iDarr *inputArr, int number)
{
    // need to make this resize the array. Whoops.
    if (inputArr->size == inputArr->limit)
    {
        // doubles limit if the limit is hit. Find a better way. Also might fail. Should have it return a 1 or 0, and force me to check if it worked or not.
        expandiDarr(inputArr, inputArr->limit + INCREASE_ARRAY);
    }
    
    const int FIRST_OPEN_INDEX = inputArr->size; // size of the array should always be equal to the first open index location
    inputArr->array[FIRST_OPEN_INDEX] = number; // setting that index as the input number
    inputArr->size++; // incrementing size
}

// Takes new limit and iDarr pointer as input, allocates a new array for the input array-
// of specified size, and copies data over. Swaps arrays within iDarr and frees the old one
void expandiDarr(iDarr *inputArr, int newLimit)
{   
    // Making sure the new limit is bigger than the old one
    if (newLimit <= inputArr->size)
    {
        printf("Cannot decrease array size with array expansion function\n");
        return;
    }

    // I want to find the newLimit easier and know where it's being referenced easier. 
    const int NEW_SIZE = newLimit;

    int *newArr = malloc(NEW_SIZE * sizeof(int)); // allocating new array
    if (newArr == NULL) // Checking for NULL, duh
    {
        free(newArr);
        printf("Unable to allocate memory for new iDarr\n");
        return;
    }
    else if (inputArr->size == 0) // Making sure the input array isn't zero. Remove this eventually maybe
    {
        printf("Input iDarr size equals zero. Nothing to resize\n");
        return;
    }

    // Copying data over
    for (int i = 0; i < inputArr->size; i++)
    {
        newArr[i] = inputArr->array[i];
    }

    // swap and free
    int *tmpArr = inputArr->array;
    inputArr->array = newArr;
    inputArr->limit = newLimit; // also update the limit
        
    free(tmpArr);
}

// ###################################
// ###################################
// ###################################


// ###################################
// ##         Linked List!          ##
// ###################################

SinLL_t *initSinLL(size_t size)
{
    SinLL_t *list = malloc(sizeof(SinLL_t));
    if (list == NULL)
    {
        free(list);
    }

    if (size > 0)
    {
        list->type_size = size;
        list->head = NULL;
        list->isEmpty = 1;
    }

    return list;
}

void push_sll_item(SinLL_t *list, void *newItem)
{
    SinLL_node *new_node = malloc(sizeof(SinLL_node));
    if (new_node == NULL)
    {
        printf("unable to create LL node\n"); // TODO: learn about proper error handling
        free(new_node);
    }

    if (list->isEmpty)
    {
        list->head = new_node;
        new_node->next = NULL;
        memcpy(&new_node->item, &newItem, list->type_size);
    }
    else
    {
        new_node->next = list->head;
        list->head = new_node;
        memcpy(&new_node->item, &newItem, list->type_size);
    }
}
