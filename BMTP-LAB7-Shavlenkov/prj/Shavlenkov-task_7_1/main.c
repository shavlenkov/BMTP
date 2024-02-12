#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 1000

bool containsDeveloper(const char *sentence) {
    const char *delimiters = " .,;:!?\t\n";
    char *word = strtok(sentence, delimiters);

    while (word != NULL) {
        if (strcmp(word, "девелопер") == 0 || strcmp(word, "Девелопер") == 0) {
            return true;
        }
        word = strtok(NULL, delimiters);
    }

    return false;
}

int main() {

    system("chcp 1251 & cls");

    char sentence[MAX_LENGTH];

    printf("Введіть речення: ");
    fgets(sentence, sizeof(sentence), stdin);

    sentence[strlen(sentence) - 1] = '\0';

    if (sentence[strlen(sentence) - 1] == '.') {
         if (containsDeveloper(sentence)) {
              printf("Слово 'девелопер' присутнє у введеному реченні.\n");
        } else {
            printf("Слово 'девелопер' відсутнє у введеному реченні.\n");
        }
    } else {
        printf("Речення не закінчується на крапку.\n");
    }

    return 0;
}
