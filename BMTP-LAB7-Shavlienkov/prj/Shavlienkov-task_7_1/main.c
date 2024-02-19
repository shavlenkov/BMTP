#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_LENGTH 1000

bool containsDeveloper(const char *sentence) {
    const char *delimiters = " .,;:!?\t\n";
    char *word = strtok(sentence, delimiters);

    while (word != NULL) {

        for (int i = 0; i < strlen(word); i++) {
            if ((word[i] >= 'A' && word[i] <= 'Z') || (word[i] >= 'А' && word[i] <= 'Я')) {
                word[i] = word[i] + 32;
            }
        }

        if (strcmp(word, "девелопер") == 0) {
            return true;
        }
        word = strtok(NULL, delimiters);
    }

    return false;
}

int main() {

    system("chcp 65001 & cls");

    char sentence[MAX_LENGTH];

    printf("Введіть речення: ");
    fgets(sentence, sizeof(sentence), stdin);

    sentence[strcspn(sentence, "\n")] = '\0';

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
