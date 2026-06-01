#ifndef MILES_TOOLS_H
#define MILES_TOOLS_H
#define INCREASE_ARRAY 256 // used for iDarr



// ###################################
// ##     DYNAMIC INTEGER ARRAY     ##
// ###################################

// Dyanmic integer array structure and following helper functions
// Making this to avoid needing to keep track of array size
// From now on iDarr = Integer Dynamic Array
typedef struct {
    int *array;
    int size;
    int limit;
} iDarr;

iDarr *initiDarr(int startingLimit); 
void freeiDarr(iDarr *inputArr); 
void expandiDarr(iDarr *inputArr, int newLimit); 
void appendiDarr(iDarr *inputArr, int number);

// ###################################
// ##         Linked List!          ##
// ###################################

// typedef struct NODE {
//     
// }

#endif
