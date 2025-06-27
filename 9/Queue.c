#include <stdio.h>
#include <stdlib.h>

// Criando a estrutura do nó da fila
typedef struct Nodo {
    int valor;
    struct Nodo *proximo;
} Nodo;

// Essa é a estrutura da fila (com ponteiro para início e fim)
typedef struct {
    Nodo *inicio;
    Nodo *fim;
} Fila;

// Função onde nós inicializamos a fila
void inicializarFila(Fila *f) {
    f->inicio = NULL;
    f->fim = NULL;
}

// Enfileiramos e inserimos o elemento no final da fila
void enfileirar(Fila *f, int valor) {
    Nodo *novo = malloc(sizeof(Nodo));
    novo->valor = valor;
    novo->proximo = NULL;

    if (f->fim == NULL) {
        // Fila está vazia
        f->inicio = novo;
    } else {
        f->fim->proximo = novo;
    }

    f->fim = novo;
}

// Desenfileirar: remove o elemento do início da fila
int desenfileirar(Fila *f) {
    if (f->inicio == NULL) {
        printf("Fila vazia!\n");
        return -1; // Valor de erro
    }

    Nodo *temp = f->inicio;
    int valor = temp->valor;

    f->inicio = f->inicio->proximo;

    if (f->inicio == NULL) {
        f->fim = NULL; // Fila ficou vazia
    }

    free(temp);
    return valor;
}

// Exibe todos os elementos da fila
void exibirFila(Fila f) {
    Nodo *atual = f.inicio;
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

// Função principal
int main() {
    Fila fila;
    inicializarFila(&fila);

    // Inserções na fila
    enfileirar(&fila, 19);
    enfileirar(&fila, 28);
    enfileirar(&fila, 37);
    enfileirar(&fila, 46);
    enfileirar(&fila, 55);
    enfileirar(&fila, 64);
    enfileirar(&fila, 73);
    enfileirar(&fila, 82);
    enfileirar(&fila, 91);
    enfileirar(&fila, 100);
    

    // Exibe a fila
    printf("Fila atual:\n");
    exibirFila(fila);

    // Remove um item da fila
    int removido = desenfileirar(&fila);
    printf("\nRemovido: %d\n", removido);

    // Exibe novamente
    printf("Fila após remoção:\n");
    exibirFila(fila);

    return 0;
}
