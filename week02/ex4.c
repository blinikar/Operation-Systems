#include <stdio.h>
#include <string.h>

int count(char character, char str[1000]) {   
    int result = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == character || str[i] == character-32 || str[i] == character+32) result++;
    }

    return result;
}

void countAll(char str[1000]) {
    
    for (int i = 0; i < strlen(str); i++) {
        char character = str[i];
        int characterCount = count(str[i], str);
        
        if (character >= 65 && character <= 90) character = character + 32;

        if (i == 0) printf("%c:%i", character, characterCount);
        else printf(", %c:%i", character, characterCount);
    }
    printf("\n");
}

int main(void) {
    char input[1000];
    gets(input);

    char str[1000];
    char characterToCount;
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == ',') {
            characterToCount = input[i+2];
            break;
        }
        str[i] = input[i];
    }

    printf("%c:%i\n", characterToCount, count(characterToCount, str));
    countAll(str);
    return 0;
}