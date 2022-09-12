#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool numerialSystemValidation(int numerialSystem) 
{
    if (numerialSystem >= 2 && numerialSystem <= 10) return true;
    return false; 
}

double logWithBase(double base, double x) {
    return log(x) / log(base);
}

int getDigit(long long count, int i) 
{
    if ((int) (count / pow(10, i)) == 0) return -1;

    int digit = count % (int) pow(10, i+1);
    digit = digit / pow(10, i+1-1);

    return digit;
}

bool countValidation(long long count, int numerialSystem) 
{
    int maxDigitPosition = (int)(logWithBase(numerialSystem, count)) + 1;

    for (int i = 0; i < maxDigitPosition; i++) 
    {
        if (getDigit(count, i) >= numerialSystem) return false;
    }

    return true;
}

long long convertToDecimalNumerialSystem(long long count, int source)
{
    long long result = 0;

    for (int i = 0; getDigit(count, i) > -1; i++) 
    {
        result += getDigit(count, i) * pow(source, i);
    }
    return result;
}

long long convertFromDecimalNumerialSystem(long long count, int target) 
{    
    int maxDigitPosition = (int)(logWithBase(target, count));
    
    long long result = 0;

    long long currentState = count;
    int currentDigitPosition = 0;
    while (currentState >= target) 
    {
        int currentDigit = currentState % target;
        currentState = currentState / target;
        result = result + currentDigit * pow(10, currentDigitPosition);
        currentDigitPosition++;
    }
    result = result + currentState * pow(10, maxDigitPosition);

    return result;
}

/**
 * Returns -1 if cannot convert
 * */
long long convert(long long count, int source, int target) 
{
    if (!(numerialSystemValidation(source) && numerialSystemValidation(target))) return -1;
    if (!countValidation(count, source)) return -1;

    long long result = count;

    if (source != 10) result = convertToDecimalNumerialSystem(result, source);
    if (target != 10) result = convertFromDecimalNumerialSystem(result, target);

    return result;
}

int main(void) 
{
    long long count;
    int source;
    int target;

    scanf("%lli%d%d", &count, &source, &target);

    long long result = convert(count, source, target);

    if (result == -1) {
        printf("Cannot convert!\n");
        return 0;
    }

    printf("%lli\n", result);
    return 0;
}