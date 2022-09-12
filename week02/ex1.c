#include <stdio.h>
#include <float.h>

int main(void) {
    int integerVar = __INT_MAX__;
    unsigned short int shortIntegerVar = __INT_MAX__;
    signed long int longIntVar = __LONG_MAX__;
    float floatVar = FLT_MAX;
    double doubleVar = DBL_MAX;

    printf("%s", "=== SIZES ===\n");
    printf("%i\n", sizeof(integerVar));
    printf("%i\n", sizeof(shortIntegerVar));
    printf("%i\n", sizeof(longIntVar));
    printf("%i\n", sizeof(floatVar));
    printf("%i\n", sizeof(doubleVar));
    printf("%s\n", "======");

    printf("%s\n", "\n=== VALUES ===");
    printf("%i\n", integerVar);
    printf("%u\n", shortIntegerVar);
    printf("%ld\n", longIntVar);
    printf("%f\n", floatVar);
    printf("%lf\n", doubleVar);
    printf("%s\n", "======");

    return 0;
}