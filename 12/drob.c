#include "drob.h"
#include <stdio.h>


struct Drob addDrobs(struct Drob d1, struct Drob d2) {
    struct Drob result;
    result.a = d1.a * d2.b + d2.a * d1.b;
    result.b = d1.b * d2.b;
    return result;
}


struct Drob subtractDrobs(struct Drob d1, struct Drob d2) {
    struct Drob result;
    result.a = d1.a * d2.b - d2.a * d1.b;
    result.b = d1.b * d2.b;
    return result;
}
// .a .so
// github
// eios
void printDrob(struct Drob d) {
    printf("%d/%d\n", d.a, d.b);
}
