#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int valor;
    struct Nodo *proximo;

    /*
        Essa estrutura define o nó da lista onde recebe o endereço do ponteiro e o valor que queremos inserir
    */
};

// Função usada para inserir no início da lista onde recebe o ponteiro e o valor que queremos inserir

void inserirInicio(struct Nodo **inicio, int valor) {
// Cria um novo nó e define com o malloc o tamanho que será usado na memoria para guarda-lo
    struct Nodo *novo = (struct Nodo *) malloc(sizeof(struct Nodo));
// Define o dado do novo nó
    novo->valor = valor;
    novo->proximo = *inicio;
//Aponta para o nó atual levando ele para o inicio da lista
    *inicio = novo;
}

// Função usada para exibir a lista 
void exibirLista(struct Nodo *inicio) {

//Percorre a lista e imprime os valores 
    struct Nodo *atual = inicio;
//Criamos um ponteiro atual para percorrer a lista sem mudar no original
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->proximo;
    }
//Enquanto o valor não for NULL ele percorre até o final da lista
    printf("NULL\n");
}

//Função principal para exibir os dados
int main() {
    struct Nodo *lista = NULL;

    inserirInicio(&lista, 10);
    inserirInicio(&lista, 20);
    inserirInicio(&lista, 30);
    inserirInicio(&lista, 40);
    inserirInicio(&lista, 50);

    exibirLista(lista);

    return 0;
}
