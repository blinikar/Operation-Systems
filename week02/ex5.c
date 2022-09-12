#include <stdio.h>

int tribonacci(int n) 
{
    int first = 0;
    int second = 1;
    int third = 1;

    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;

    int result = 0;
    for (int i = 3; i <= n; i++) 
    {
        result = first + second + third;
        first = second;
        second = third;
        third = result;
    }

    return result;
}


int main(void) 
{
    printf("%d\n", tribonacci(4));
    printf("%d\n", tribonacci(36));
    return 0;
}