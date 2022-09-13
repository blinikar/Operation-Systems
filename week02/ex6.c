#include <stdio.h>


void print1(int n) {
    for (int i = 0; i < n; i++) {
        int stairLength = i + 1;
        for (int j = 0; j < stairLength; j++) {
            printf("*");
        }
        printf("\n");
    }
    printf("\n\n");
}


void print2(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("*");
        }
        printf("\n");
    }
    printf("\n\n");
}

void print3(int n) {
    for (int i = 0; i < n; i++) {
        int stairLength;

        if(i > n/2) stairLength = n - i;
        else stairLength = i+1;

        for (int j = 0; j < stairLength; j++) {
            printf("*");
        }
        printf("\n");
    }
    printf("\n\n");
}

int main(void) {

    print1(7);
    print2(7);
    print3(7);
    return 0;
}