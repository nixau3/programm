#ifndef DROB_H
#define DROB_H


struct Drob {
    int a;  
    int b;  
};


struct Drob addDrobs(struct Drob d1, struct Drob d2);


struct Drob subtractDrobs(struct Drob d1, struct Drob d2);


void printDrob(struct Drob d);

#endif
