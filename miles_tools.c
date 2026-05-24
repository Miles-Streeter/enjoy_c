#include <stdlib.h>
#include <stdio.h>

// TODO: make header file for this



// Dyanmic integer array structure and following helper functions
// Making this to avoid needing to keep track of array size
// From now on iDarr = Integer Dynamic Array
typedef struct {
    int *array;
    int size;
    int limit;
} iDarr;

// function used to initialize an iDarr. Creating this function to give initial values to array-
// and ideally avoid accidentally referencing an array with no values, or screwing up the limit or size
void initiDarr(iDarr *iniDarr, int startingLimit)
{
    iniDarr->array = malloc(startingLimit * sizeof(int));

    if (iniDarr->array == NULL)
    {
        printf("Failed to allocate memory to Integer Dynamic Array\n");
    }
    else
    {
        iniDarr->size = 0;
        iniDarr->limit = startingLimit;
    }
}

void freeiDarr(iDarr *inputArr)
{
    if (inputArr->array != NULL)
    {
        free(inputArr->array);
        free(inputArr);
    }
    else
    {
        free(inputArr);
    }
    
}

// TODO: make function to add new items to iDarr

// TODO: make function to change iDarr limit and realloc 


// ignore. I didn't setup a proper file to start testing.
int main(void)
{   
    iDarr *test = malloc(sizeof(iDarr));
    if (test == NULL)
    {
        printf("failed to allocate memory for Integer Dynamic Array\n");
        exit(0);
    }
       
    initiDarr(test, 1);
    printf("%d\n", test->limit);
    freeiDarr(test);
}
