#include <stdlib.h>
#include <stdio.h>
#include "miles_tools.h"


// function used to initialize an iDarr. Creating this function to give initial values to array-
// and ideally avoid accidentally referencing an array with no values, or screwing up the limit or size
void initiDarr(iDarr *iniDarr, int startingLimit)
{
    iniDarr->array = malloc(startingLimit * sizeof(int));

    if (iniDarr->array == NULL)
    {
        printf("Failed to allocate memory to Integer Dynamic Array\n");
        return;
    }
    else
    {
        iniDarr->size = 0;
        iniDarr->limit = startingLimit;
    }
}

// free function for iDarrs so I hopefully don't ever forget to free both the array and the struct
void freeiDarr(iDarr *inputArr)
{
    if (inputArr->array != NULL) // This just ensures I can call this function even if I haven't allocated memory for the array yet
    {
        free(inputArr->array);
        free(inputArr);
    }
    else
    {
        free(inputArr);
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
    int *newArr = malloc(newLimit * sizeof(int));
    if (newArr == NULL) // Checking for NULL, duh
    {
        printf("Unable to allocate memory for new iDarr\n");
        return;
    }
    else if (inputArr->size == 0) // Making sure the input array isn't zero
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
    free(tmpArr);
}
