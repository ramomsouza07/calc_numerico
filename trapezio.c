#include <stdio.h>

float AreaTrapezio (float x0, float x1, float h){
    return h/2 * (x0 + x1);
}

int main (){
    float f0, f1;
    float h, a, b;
    
    printf("Insira o valor (a) do intervalo: ");
    scanf("%f", &a);
    
    printf("Insira o valor (b) do intervalo: ");
    scanf("%f", &b);
    
    h = (b - a);
    
    printf("Insira o valor de f(0): ");
    scanf("%f", &f0);
    
    printf("Insira o valor de f(1): ");
    scanf("%f", &f1);
    
    printf("O valor da integral aproximada é de: %f", AreaTrapezio(f0, f1, h));
}