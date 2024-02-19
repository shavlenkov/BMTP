#include <stdlib.h>
#define n 15

int main()
{
    system("chcp 65001 & cls");

    int array[n];

    printf("Введіть натуральних 15 чисел:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
        if(array[i] <= 0) {
           printf("Не є натуральним числом!\n");
           i--;
        }
    }

    int summa = 0;

    for(int i = 0; i < n; i++) {
        summa += array[i];
    }

    array[4] = (summa / n);

    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}
