#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Coeficiente do polinômio*/
#define c1 1
#define c2 6
#define c3 -5

/*Definir cota e número máximo de iteração*/
#define erro 0.025
#define Nmax 50

/*função f(x)*/
float f(float x){
    return (c1 * x * x) + (c2 * x) + c3;
}

int main() {
    float b = -6, a = -7;

    if (f(a) * f(b) > 0){
        printf("Não irá convergir\n");
    }
    float y = (a + b)/2;
    int k = 0;
    while (fabs(b - a) > erro){
        k++;
        y = (a + b)/2;
        if (f(y) * f(a) > 0){
            a = y;
        } else {
            b = y;
        }
        if(k >= Nmax){
            break;
        }
    }
    printf("O valor aproximado é de: %f\n", y);
}
