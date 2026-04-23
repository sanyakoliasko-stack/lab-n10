#include <stdio.h>

int main() {
    int choice, number;
    char *filename = "numbers.txt";

    while (1) {
        printf("\n--- МЕНЮ ---\n1. Квадрати непарних\n2. Різниця Max/Min\n3. Створити файл\n0. Вихід\nВаш вибір: ");
        scanf("%d", &choice);

        if (choice == 0) break;

        // Пункт 3: Створюємо файл, щоб програма точно його бачила
        if (choice == 3) {
            FILE *f = fopen(filename, "w");
            fprintf(f, "9 4 16 7 25 10 3 1");
            fclose(f);
            printf("Готово! Файл numbers.txt створено.\n");
            continue;
        }

        FILE *f = fopen(filename, "r");
        if (!f) {
            printf("Файлу немає! Натисніть спочатку 3.\n");
            continue;
        }

        if (choice == 1) {
            int count = 0;
            while (fscanf(f, "%d", &number) == 1) {
                // Перевірка: чи непарне і чи є квадратом (просто перебором)
                if (number % 2 != 0) {
                    for (int i = 1; i * i <= number; i++) {
                        if (i * i == number) count++;
                    }
                }
            }
            printf("Кількість квадратів непарних чисел: %d\n", count);
        } 
        else if (choice == 2) {
            int maxEven = -999999, minOdd = 999999;
            int foundEven = 0, foundOdd = 0;

            while (fscanf(f, "%d", &number) == 1) {
                if (number % 2 == 0) {
                    if (number > maxEven) { maxEven = number; foundEven = 1; }
                } else {
                    if (number < minOdd) { minOdd = number; foundOdd = 1; }
                }
            }
            if (foundEven && foundOdd) {
                printf("Max парне: %d, Min непарне: %d\n", maxEven, minOdd);
                printf("Різниця: %d\n", maxEven - minOdd);
            } else {
                printf("У файлі бракує чисел!\n");
            }
        }
        fclose(f);
    }
    return 0;
}