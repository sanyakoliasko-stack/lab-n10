#include <stdio.h>

int main() {
    FILE *file;
    float number, sum = 0;
    int count = 0;

    // 1. Відкриваємо файл для читання
    file = fopen("numbers.txt", "r");

    if (file == NULL) {
        printf("Помилка: Не вдалося знайти файл numbers.txt\n");
        return 1;
    }

    // 2. Читаємо числа по черзі до кінця файлу
    // fscanf повертає кількість успішно зчитаних елементів
    while (fscanf(file, "%f", &number) == 1) {
        sum += number;
        count++;
    }

    // 3. Закриваємо файл
    fclose(file);

    // 4. Виводимо результат
    if (count > 0) {
        float average = sum / count;
        printf("Зчитано чисел: %d\n", count);
        printf("Сума: %.2f\n", sum);
        printf("Середнє арифметичне: %.2f\n", average);
    } else {
        printf("Файл порожній або не містить чисел.\n");
    }

    return 0;
}