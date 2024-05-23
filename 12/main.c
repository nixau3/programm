#include "drob.h"
#include <stdio.h>

int main() {
  
    struct Drob drob1 = {25, 34}; // 2/3
    struct Drob drob2 = {1, 4}; // 1/4
    struct Drob sum = addDrobs(drob1, drob2);
    struct Drob difference = subtractDrobs(drob1, drob2);
    
    printf("Сумма дробей: ");
    printDrob(sum);
    printf("Разность дробей: ");
    printDrob(difference);
    
    return 0;
}
