#include <stdio.h>
#include <string.h>

int main(void) {
    char inputString[1000];
    gets(inputString);

    char resultString[1000];
    for (int i = 0; i < strlen(inputString); i++) {
        if (i == strlen(inputString) - 1 && inputString[i] != '.') return 0;
        
        if (inputString[i] == '.') break;
        else resultString[i] = inputString[i];
    }

    printf("\"");
    for (int i = strlen(resultString); i >= 0; i--) {
        printf("%c", resultString[i]);
    }
    printf("\"\n");

    return 0;
}