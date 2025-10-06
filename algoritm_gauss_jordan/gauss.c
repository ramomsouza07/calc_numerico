#include <stdio.h>
#include <stdlib.h>

int main() {
    int l, c;
    printf("Insira o número de linhas da matriz: ");
    scanf("%d", &l);

    printf("Insira o número de colunas da matriz: ");
    scanf("%d", &c);

    if (l <= 0 || c <= 0) {
        printf("Dimensões inválidas!\n");
        return 1;
    }

    float m[l][c];

    // Entrada da matriz
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            printf("Insira o valor a[%d][%d]: ", i + 1, j + 1);
            scanf("%f", &m[i][j]);
        }
    }

    printf("\nMatriz Original:\n");
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            printf("%8.2f", m[i][j]);
        }
        printf("\n");
    }

    // Transformação em triangular superior
    for (int k = 0; k < l - 1; k++) {
        if (m[k][k] == 0) {
            printf("\nErro: pivô zero na linha %d! (Troca de linhas recomendada)\n", k + 1);
            return 1;
        }

        for (int i = k + 1; i < l; i++) {
            float fator = m[i][k] / m[k][k];
            for (int j = k; j < c; j++) {
                m[i][j] -= fator * m[k][j];
            }
        }
    }

    printf("\nMatriz Triangular Superior:\n");
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            printf("%8.2f", m[i][j]);
        }
        printf("\n");
    }

    return 0;
}
