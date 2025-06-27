#include <stdio.h>
#include <stdlib.h>

void shellSort(int *v, int n){
    int gaps[] = {4, 1}; // Pode trocar por {701, 301, 132, 57, 23, 10, 4, 1} se n >= 701
    int gapJumps = sizeof(gaps) / sizeof(int);

    for(int g = 0; g < gapJumps; g++){
        int gap = gaps[g];

        for(int i = gap; i < n; i++){
            int insert = v[i];
            int j = i;

            while(j >= gap && v[j-gap] > insert){
                v[j] = v[j-gap];
                j -= gap;
            }

            v[j] = insert;
        }
    }
}

void printVector(int *v, int n){
    for (int i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main(){
    int n;
    printf("Tamanho do vetor: ");
    scanf("%d", &n);

    int *v = (int *)malloc(n * sizeof(int));
    if (v == NULL){
        printf("Erro ao alocar memória\n");
        return 1;
    }

    printf("Digite %d números:\n", n);
    for (int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }

    shellSort(v, n);
    printf("Vetor ordenado:\n");
    printVector(v, n);

    free(v);
    return 0;
}
