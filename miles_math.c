#include <stdlib.h>
#include <stdio.h>
#include "miles_tools.h"
#include "miles_math.h"

// returns factors in the form of a dynamic integer array
iDarr *returnFactors(int inpNum) 
{
    const int MAX_ARR = 256; // limiting how big the array can be
    
    int arrInt[MAX_ARR]; // temp array to hold the factors of the input number
    int arrCount = 0; // Counter for indexes of array

    // Loops through and tests each number that is less than/equals half of the input number and adds adds any factors to the array
    for (int i = 1; i <= (int)inpNum / 2; i++)
    {
        if (inpNum % i == 0)
        {
            arrInt[arrCount] = i;
            arrCount++;
        }
    }

    // Appends the input number to the end of the array since it doesn't get grabbed at the start.
    // Probably should just add 1 and the input number to the array to begin with and skip one
    arrInt[arrCount] = inpNum;
    arrCount++;

    // Create the iDarr that will be returned
    const int IDARR_START = arrCount;
    iDarr *tmpiDarr = initiDarr(IDARR_START);

    // copy the array from in here to the iDarr
    for (int i = 0; i < arrCount; i++)
    {
        appendiDarr(tmpiDarr, arrInt[i]);
    }

    return tmpiDarr;
}
