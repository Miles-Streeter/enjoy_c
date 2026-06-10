#ifndef MILES_TOOLS_H
#define MILES_TOOLS_H
#define INCREASE_ARRAY 256 // used for iDarr

#include <stddef.h>


// ###################################
// ##     DYNAMIC INTEGER ARRAY     ##
// ###################################

// Dyanmic integer array structure and following helper functions
// Making this to avoid needing to keep track of array size
// From now on iDarr = Integer Dynamic Array
typedef struct {
    int *array;
    int size; // actual size of the array. This number should always be equal to how many items are in the array
    int limit; // amount of items the array can have before needing to be resized
} iDarr;

iDarr *initiDarr(int startingLimit); 
void freeiDarr(iDarr *inputArr); 
void expandiDarr(iDarr *inputArr, int newLimit); 
void appendiDarr(iDarr *inputArr, int number);

// ###################################
// ##         Linked List!          ##
// ###################################

typedef struct SinLL_node {
    void *item;
    struct SinLL_node *next;
} SinLL_node;

typedef struct {
    SinLL_node *head; // so none of this ?
    size_t type_size;
    int isEmpty;
} SinLL_t;

SinLL_t *initSinLL(size_t size);
void push_sll_item(SinLL_t *list, void *newItem);

#endif
