#include <stdio.h>
#include <stdlib.h>

float Integral (float f[], float h, int n){
    float sum, area;
    sum = 0;
    
    for(int i = 1; i < n - 1; i++){
        sum += f[i];
    }
    sum *= 2;
    sum += f[0] + f[n - 1];
    
    area = (h/2) * sum;

    return area;
}

int main (){
    int n = 0;
    float h, a, b, *f;
    
    printf("Insira o valor (a) do intervalo: ");
    scanf("%f", &a);
    
    printf("Insira o valor (b) do intervalo: ");
    scanf("%f", &b);
    
    printf("Insira a quantidade de pontos de f(x) usaremos: ");
    scanf("%d", &n);
    
    f = (float*) malloc(n * sizeof(float));
        
    if (f == NULL) {
        printf("Erro de alocacao de memoria.\n");
        return 1;
    }

    printf("Memoria alocada com sucesso.\n");
    
    for(int i = 0; i < n; i++){
        printf("Insira o valor %d: ", i );
        scanf("%f", &f[i]);
    }
    
    h = (b - a)/(n - 1);
    
    printf("O valor da integral aproximada é de: %f", Integral(f, h, n));
}