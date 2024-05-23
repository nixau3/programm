#include <stdio.h>
#include <stdlib.h>

int calculateProduct(int* array, int size, int index, int currentProduct) {
    if (index == size) {
        return currentProduct;
    }

    if (array[index] > 0 && array[index] < 4) {
        currentProduct *= array[index];
    }

    return calculateProduct(array, size, index + 1, currentProduct);
}

int main() {
    int size;
    printf("Введите размер массива: ");
    scanf("%d", &size);

    int* array = (int*)malloc(size * sizeof(int));

    for (int i = 0; i < size; ++i) {
        array[i] = rand() % 10;
    }

    printf("Массив: ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");

    int product = calculateProduct(array, size, 0, 1);

    printf("Произведение положительных чисел, меньших 4: %d\n", product);

    free(array);

    return 0;
}