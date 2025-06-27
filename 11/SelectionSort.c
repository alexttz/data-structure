#include <stdio.h>

/*O programa abaixo tem como intuito realizar a ordeção dos números em ordem decrescente*/

// Está é unção que vai ordenar o vetor em ordem decrescente usando Selection Sort
void selectionSortDecrescente(int v[], int n) {
    for (int i = 0; i < n; i++) {
        int maior = i; // Assume o valor que o maior está na posição atual
        for (int j = i + 1; j < n; j++) {
            if (v[j] > v[maior]) { // Se achar um valor maior, atualiza o índice
                maior = j;
            }
        }
        // Se encontrou um valor maior em outra posição, troca
        if (maior != i) {
            int aux = v[i];
            v[i] = v[maior];
            v[maior] = aux;
        }
    }
}

// Função para imprimir o vetor
void printVector(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main() {
    // Vetor com 10 elementos
    int vetor[] = {3, 0, 1, 8, 7, 2, 5, 4, 9, 6};

    // Ordena em ordem decrescente
    selectionSortDecrescente(vetor, 10);

    // Exibe o vetor ordenado
    printVector(vetor, 10);
    return 0;
}
