#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Структура для хранения информации о товаре
struct Toy {
    char name[50];
    float price;
    char shop[50];
};

// Функция для добавления записи в файл
void addRecord(FILE *file) {
    struct Toy newToy;

    printf("Введите название игрушки: ");
    scanf("%s", newToy.name);
    printf("Введите стоимость игрушки: ");
    scanf("%f", &newToy.price);
    printf("Введите название магазина: ");
    scanf("%s", newToy.shop);

    fwrite(&newToy, sizeof(struct Toy), 1, file);
}

// Функция для обработки файла
void processFile(FILE *file) {
    struct Toy toy;
    char searchName[50];
    int found = 0;

    printf("Введите название игрушки для поиска: ");
    scanf("%s", searchName);

    // Поиск и вывод информации о нужной игрушке
    while (fread(&toy, sizeof(struct Toy), 1, file)) {
        if (strcmp(toy.name, searchName) == 0) {
            printf("Название: %s\n", toy.name);
            printf("Стоимость: %.2f\n", toy.price);
            printf("Магазин: %s\n", toy.shop);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Игрушка с таким названием не найдена.\n");
    }
}

int main() {
    char choice;
    FILE *file;

    // Открытие файла для чтения и записи в режиме бинарного доступа
    file = fopen("PRICE.dat", "ab+");

    if (file == NULL) {
        printf("Ошибка открытия файла.\n");
        return 1;
    }

    do {
        printf("Выберите операцию:\n");
        printf("a) Добавить запись в файл\n");
        printf("m) Обработать файл\n");
        printf("Введите ваш выбор: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
                addRecord(file);
                break;
            case 'm':
                processFile(file);
                break;
            default:
                printf("Неверный выбор. Попробуйте еще раз.\n");
        }

        printf("Хотите продолжить (y/n)? ");
        scanf(" %c", &choice);
    } while (choice == 'y');

    fclose(file);

    return 0;
}
