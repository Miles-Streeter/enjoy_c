#include <stdio.h>
#include <stdlib.h>



int main(int argc, char *argv[]) {
    if (argc > 2) {
        printf("too many args\n");
        return 1;
    }

    int number = atoi(argv[1]);

    for (int i = 2; i < number; i++) {
        if (number % i == 0) {
            printf("not prime\n");
            return 0;
        }
    }

    printf("%d is prime\n", number);
    return 0;
}
