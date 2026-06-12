#ifndef RAND_ARR_GEN_H
#define RAND_ARR_GEN_H

typedef struct {
    int *arr;
    int size;
    int max;
} rarr;

rarr initRandArr(int sizeLimit);

#endif
