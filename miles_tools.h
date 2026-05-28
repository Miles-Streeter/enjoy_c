#ifndef MILES_TOOLS_H
#define MILES_TOOLS_H


// Dyanmic integer array structure and following helper functions
// Making this to avoid needing to keep track of array size
// From now on iDarr = Integer Dynamic Array
typedef struct {
    int *array;
    int size;
    int limit;
} iDarr;

void initiDarr(iDarr *iniDarr, int startingLimit);
void freeiDarr(iDarr *inputArr);
void expandiDarr(iDarr *inputArr, int newLimit);
void expandiDarr(iDarr *inputArr, int newLimit);

#endif
