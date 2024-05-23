#include <math.h>
#include <stdio.h>
#define E 0.001
float rec(int n){
    float x=1.5;
    float result=0;
    float f=(pow(-1, (n+1)))*((pow((x-1),n)/n));
    if (fabs(f)>=E){
        result+=f;
    return result +rec(n+1);
    }
    else{
        return f;
    }
}
int main ()
{
    int n=1;
    printf("%.6f \n", rec(n));
}