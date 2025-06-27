#include <stdio.h>


void insertionSortDesc(int v[], int n){
    for (int i = 1; i < n; i++){
        int insert = v[i];   // valor a ser inserido
        int j = i - 1;

        // mudamos o sinal: agora comparamos se v[j] < insert
        while(j >= 0 && v[j] < insert){
            v[j + 1] = v[j]; // empurra os menores pra direita
            j--;
        }

        v[j + 1] = insert;   // insere no lugar certo
    }
}

void printVector(int v[], int n){
    for (int i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main(){
    int vetor[] = {14,15,55,39,70,38,33,45,40,63,36,75,19};

    insertionSortDesc(vetor, 13);
    printf("Vetor em ordem decrescente:\n");
    printVector(vetor, 13);

    return 0;
}
