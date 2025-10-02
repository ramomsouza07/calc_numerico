#include <stdio.h>
#include <stdlib.h>

int main() {
    float m[3][3];
    
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("Insira o valor a[%d][%d]: ", i+1, j+1);
            scanf("%f", &m[i][j]);
        }
    }printf("\n");

    float fator;

    printf("Matriz Original:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%.2f\t", m[i][j]);
        }
        printf("\n");
    }

    for (int k = 0; k < 2; k++) {
        for (int i = k + 1; i < 3; i++) {
            if (m[k][k] == 0) {
                printf("Erro: Pivô é zero! Divisão por zero.\n");
                return 1;
            }
            fator = m[i][k] / m[k][k];

            for (int j = k; j < 3; j++) {
                m[i][j] = m[i][j] - (fator * m[k][j]);
            }
        }
    }

    printf("\nMatriz Triangular Superior:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%.2f\t", m[i][j]);
        }
        printf("\n");
    }

    return 0;
}