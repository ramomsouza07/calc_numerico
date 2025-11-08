#include <stdio.h>
#include <stdlib.h>
int TwoSum(int a[], int alvo, int n){
    int sum[2], i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(j != i){
                if(a[i] + a[j] == alvo){
                    sum[0] = a[i];
                    sum[1] = a[j];
                    break;
                }
                
            }
        }
        if(a[i] + a[j] == alvo){
            break;
        }
    }
    printf("[%d, %d]", sum[0], sum[1]);
}

int main(){
    int *a, n, target;

    printf("Insira a quantidade de valores do vetor: ");
    scanf("%d", &n);

    printf("Insira o valor alvo: ");
    scanf("%d", &target);

    a = (int*) malloc(n * sizeof(int));

    for(int i = 0; i < n; i++){
        printf("Insira o valor %d: ", i);
        scanf("%d", &a[i]);
    }
    
    TwoSum(a, target, n);
}