#include <stdio.h>
#include <stdlib.h>

//Aqui fica a definição do nó da estrutura com o nome de Nodo
typedef struct Nodo {
    int valor;
    struct Nodo *proximo;
} Nodo;

//Definida a função que aponta para o inicio da lista e permite modificar o ponteiro original
void inserirInicio(Nodo **inicio, int valor) {
    Nodo *novo = malloc(sizeof(Nodo)); //Alocando dinamicamente no espaço da memória para um nodo
    novo->valor = valor;
    novo->proximo = *inicio;
    *inicio = novo; //Retornando o endereço do novo espaço guardando num novo ponteiro
}

// Percorremos a lista sem alterar o valor do ponteiro atual 
void exibir(Nodo *inicio) {
    Nodo *atual = inicio;
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

//Enquanto o ponteiro atual não for NULL ele imprime o valor do nó atual e avança para o proximo

// Função principal que cria o ponteiro principal começando como NULL
int main() {
    Nodo *lista = NULL;

    inserirInicio(&lista, 1);
    inserirInicio(&lista, 2);
    inserirInicio(&lista, 3);
    inserirInicio(&lista, 4);
    inserirInicio(&lista, 5);
    inserirInicio(&lista, 6);


    //Mostramos a lista
    exibir(lista);

    return 0;
}
