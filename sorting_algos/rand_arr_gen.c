#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "rand_arr_gen.h"


rarr initRandArr(int sizeLimit) {

    // seeding rand function
    srand(time(NULL));

    
    // making array
    rarr newArr;
    newArr.arr = malloc(sizeLimit * sizeof(int));
    newArr.size = 0;
    newArr.max = sizeLimit;

    for (int i = 0; i < sizeLimit; i++) {
        // filling up the array and incrementing the size counter
        newArr.arr[i] = i;
        newArr.size++;
    }

    // Fisher-Yates shuffle, according to google/SO
    // You ever see something and think "that makes perfect sense" while accepting that you could've never thought of it on your own ?
    for (int i = sizeLimit - 1; i > 0; i--) {

        // getting random index in array
        int j = rand() % (i + 1);

        // straight up swappin it
        int tmp = newArr.arr[i];
        newArr.arr[i] = newArr.arr[j];
        newArr.arr[j] = tmp;
    }

    return newArr;
}
