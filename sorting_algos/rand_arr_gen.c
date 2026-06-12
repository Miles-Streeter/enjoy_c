#include <stdlib.h>
#include <time.h>


typedef struct {
    int *arr;
    int size;
    int max;
} rarr;


void initRandArr(int sizeLimit, rarr newArr) {

    // seeding rand function
    srand(time(NULL));

    // in case you pass an array with stuff already in it
    if (newArr.arr != NULL)
        free(newArr.arr);
    
    // making array
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
}
