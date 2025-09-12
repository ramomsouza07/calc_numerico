#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float f (float x){
    return (x*x*x) - (9 * x) + 3;
}

float df (float x){
    return (3*x*x) - 9;
}

int main(){
    float e = 0.01;
    int Nmax = 50;
    float zeta = 0;
    float x = 1;
    int k = 0;

    if (f(x) == 0 || Nmax == 0){
        zeta = x;
    } else {
        while (fabs(f(x)) > e && k < Nmax){
            x = x - f(x)/df(x);
            k++;
        }
        zeta = x;
    }

    printf("Raiz aproximada: %.7f em %d iteracoes\n", zeta, k);
    return 0;
}
