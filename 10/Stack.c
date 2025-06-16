#include <stdio.h>
#include <stdlib.h>

// Estruturamos o nó da pliha
typedef struct Nodo {
    int valor;
    struct Nodo *proximo;
} Nodo;

// Em seguida estruturamos a pliha completa
typedef struct {
    Nodo *topo;
} Pilha;

// Inicializamos a pliha vazia
void inicializarPilha(Pilha *p) {
    p->topo = NULL;
}

// Emplihamos e inserimos os valores no topo da pliha
void empilhar(Pilha *p, int valor) {
    Nodo *novo = malloc(sizeof(Nodo));
    novo->valor = valor;
    novo->proximo = p->topo; // Aponta pro antigo topo
    p->topo = novo;          // Agora é o novo topo
}

// Desempilhar: remove o elemento do topo
int desempilhar(Pilha *p) {
    if (p->topo == NULL) {
        printf("Pilha vazia!\n");
        return -1;
    }

    Nodo *temp = p->topo;
    int valor = temp->valor;
    p->topo = temp->proximo;
    free(temp);

    return valor;
}

// Exibe os elementos da pilha
void exibirPilha(Pilha p) {
    Nodo *atual = p.topo;
    while (atual != NULL) {
        printf("%d\n", atual->valor);
        atual = atual->proximo;
    }
    printf("TOPO\n");
}

// Função principal
int main() {
    Pilha pilha;
    inicializarPilha(&pilha);

    empilhar(&pilha, 10);
    empilhar(&pilha, 20);
    empilhar(&pilha, 30);

    printf("Pilha atual:\n");
    exibirPilha(pilha);

    int removido = desempilhar(&pilha);
    printf("\nRemovido do topo: %d\n", removido);

    printf("Pilha após remoção:\n");
    exibirPilha(pilha);

    return 0;
}
