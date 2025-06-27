#include <stdio.h>
#include <stdlib.h>

/* Pilha sem cabeça

// Estruturamos o nó da pliha que usaremos
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

// Função principal para execução
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
*/

// Pilha com cabeça

#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó (cada elemento da pilha)
typedef struct Nodo {
    int valor;              // Dado armazenado
    struct Nodo *proximo;   // Ponteiro para o próximo nó
} Nodo;

// Estrutura da pilha com cabeça
typedef struct {
    Nodo *cabeca;  // Cabeça da pilha (nó sentinela, não armazena valor real)
} Pilha;

// Função para inicializar a pilha com o nó cabeça
void inicializarPilha(Pilha *p) {
    p->cabeca = malloc(sizeof(Nodo)); // Cria o nó cabeça
    p->cabeca->proximo = NULL;        // Inicialmente não há elementos
}

// Empilha um novo valor no topo da pilha
void empilhar(Pilha *p, int valor) {
    Nodo *novo = malloc(sizeof(Nodo)); // Cria novo nó com o valor
    novo->valor = valor;

    // O novo nó aponta para o antigo topo
    novo->proximo = p->cabeca->proximo;

    // A cabeça agora aponta para o novo nó como novo topo
    p->cabeca->proximo = novo;
}

// Desempilha (remove) o valor do topo da pilha
int desempilhar(Pilha *p) {
    if (p->cabeca->proximo == NULL) {
        printf("Pilha vazia!\n");
        return -1;
    }

    Nodo *remover = p->cabeca->proximo;    // Nó que será removido
    int valor = remover->valor;            // Armazena o valor antes de remover

    p->cabeca->proximo = remover->proximo; // Cabeça passa a apontar para o próximo nó
    free(remover);                         // Libera o nó da memória

    return valor;
}

// Exibe todos os elementos da pilha
void exibirPilha(Pilha p) {
    Nodo *atual = p.cabeca->proximo;  // Começa após o nó cabeça
    while (atual != NULL) {
        printf("%d\n", atual->valor);
        atual = atual->proximo;
    }
    printf("TOPO\n");
}

// Função principal
int main() {
    Pilha pilha;
    inicializarPilha(&pilha);  // Cria a pilha com cabeça

    // Empilhando alguns valores
    empilhar(&pilha, 10);
    empilhar(&pilha, 20);
    empilhar(&pilha, 30);
    empilhar(&pilha, 40);
    empilhar(&pilha, 50);
    empilhar(&pilha, 60);
    empilhar(&pilha, 70);
    empilhar(&pilha, 80);
    empilhar(&pilha, 90);
    empilhar(&pilha, 100);


    // Mostra a pilha atual
    printf("Pilha atual:\n");
    exibirPilha(pilha);

    // Remove o topo
    int removido = desempilhar(&pilha);
    printf("\nRemovido do topo: %d\n", removido);

    // Mostra novamente após remoção
    printf("Pilha após remoção:\n");
    exibirPilha(pilha);

    // Libera o nó cabeça no final (boa prática)
    free(pilha.cabeca);

    return 0;
}

/*O uso da estrutura sem cabeça deve se dar quando as estruturas são simples e menor uso de memória
Para projetos maiores, a estrutura com cabeça é mais adequada pois facilita muito em listas duplamentes encadeadas, filas circulares e listas ordenadas.
*/