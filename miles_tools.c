#include <stdlib.h>
#include <stdio.h>
#include "miles_tools.h"


// Function creates and returns an integer dynamic array. Allocates memory for the array as well.
// Ideally this will stop me from referencing NULL values, but I'll always find a way.
// Returns zero if any mem allocs fail
iDarr *initiDarr(int startingLimit)
{
    // Allocating the memory for the array and creating a pointer to it.
    iDarr *tmpiDarr = malloc(sizeof(iDarr));
    if (tmpiDarr == NULL)
    {
        return 0;
    }

    // Allocating the memory for the array and checking for NULL
    tmpiDarr->array = malloc(startingLimit * sizeof(int));
    if (tmpiDarr->array == NULL)
    {
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
    if (inputArr->array != NULL) // This just ensures I can call this function even if I haven't allocated memory for the array yet. Which shouldn't happen
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
        //explode
        printf("Failed to insert item. Array Full. Resize\n");
        return;
    }
    
    const int FIRST_OPEN_INDEX = inputArr->size; // size of the array should always be equal to the first open index location
    inputArr->array[FIRST_OPEN_INDEX] = number; // setting that index as the input number
    inputArr->size++; // incrementing size
}

// Takes new limit and iDarr pointer as input, allocates a new array for the input array-
// of specified size, and copies data over. Swaps arrays within iDarr and frees the old one
// TODO: check to see if newLimit is smaller and the old limit, then figure out what to do in that scenario
void expandiDarr(iDarr *inputArr, int newLimit)
{
    int *newArr = malloc(newLimit * sizeof(int)); // allocating new array
    if (newArr == NULL) // Checking for NULL, duh
    {
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
