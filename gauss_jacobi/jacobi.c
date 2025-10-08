#include <stdio.h>
#include <math.h>

int main() {
    int n, i, j, iter = 0, max_iter;
    float tol;

    // Entrada do tamanho da matriz
    printf("Digite a ordem do sistema (n): ");
    scanf("%d", &n);

    float A[n][n], b[n], x[n], x_ant[n];

    // Entrada dos coeficientes da matriz A
    printf("\nDigite os coeficientes da matriz A:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("A[%d][%d]: ", i + 1, j + 1);
            scanf("%f", &A[i][j]);
        }
    }

    // Critério das linhas
    int satisfaz = 1; // começa supondo que satisfaz
    for (i = 0; i < n; i++) {
        float soma = 0.0;
        for (j = 0; j < n; j++) {
            if (j != i)
                soma += fabs(A[i][j]);
        }

        if (fabs(A[i][i]) <= soma) {
            satisfaz = 0;
            break;
        }
    }

    if (!satisfaz) {
        printf("\nERRO: A matriz NAO satisfaz o criterio das linhas.\n");
        printf("Troque as linhas da matriz para tentar torná-la diagonalmente dominante.\n");
    } else {
        printf("\nA matriz SATISFAZ o criterio das linhas. Pode prosseguir com o metodo.\n");
    }

    // Entrada do vetor b
    printf("\nDigite o vetor b:\n");
    for (i = 0; i < n; i++) {
        printf("b[%d]: ", i + 1);
        scanf("%f", &b[i]);
    }

    // Valores iniciais
    printf("\nDigite os valores iniciais de x:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d]: ", i + 1);
        scanf("%f", &x[i]);
    }

    // Tolerância e número máximo de iterações
    printf("\nDigite a tolerância (ex: 0.001): ");
    scanf("%f", &tol);
    printf("Digite o número máximo de iterações: ");
    scanf("%d", &max_iter);

    printf("\nIteração |");
    for (i = 0; i < n; i++) printf("   x%d    |", i + 1);
    printf("  Erro\n");
    printf("--------------------------------------------------------\n");

    do {
        float erro = 0.0;
        for (i = 0; i < n; i++) {
            x_ant[i] = x[i];
        }

        // Fórmula de Jacobi
        for (i = 0; i < n; i++) {
            float soma = 0.0;
            for (j = 0; j < n; j++) {
                if (j != i){
                    soma += A[i][j] * x_ant[j];
                }
            }
            x[i] = (b[i] - soma) / A[i][i];
        }

        // Cálculo do erro máximo
        for (i = 0; i < n; i++) {
            float dif = fabs(x[i] - x_ant[i]);
            if (dif > erro){
                erro = dif;
            }
        }

        iter++;
        printf("%5d    |", iter);
        for (i = 0; i < n; i++) printf(" %7.4f |", x[i]);
        printf(" %7.6f\n", erro);

        if (erro < tol) break;
    } while (iter < max_iter);

    printf("\nSolução aproximada:\n");
    for (i = 0; i < n; i++)
        printf("x[%d] = %.6f\n", i + 1, x[i]);

    printf("\nNúmero de iterações: %d\n", iter);

    return 0;
}