#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Definir cota e número máximo de iteração*/
#define erro 0.0001
#define Nmax 50

/*função f(x)*/
float f(float x){
    return (x * x * x) + ((-4) * x) + 1;
}

int main() {
    /*Intervalo*/
    float a = 1, b = 2;
    
    if (f(a) * f(b) < 0){
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
        printf("O valor aproximado é de: %.6f\n", y);        
    }else{
        printf("Não irá convergir\n");
    }
}