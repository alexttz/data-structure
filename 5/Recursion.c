#include <stdio.h>

//Criado a função fatorial que será usada no cálculo 
int fatorial(int n){
    printf("Calcular fatorial: (%d)\n", n);  
    //Este aqui é o caso base, sem ele o programa executa em loop infinito
    if (n == 0 || n == 1)
    {
        return 1;
    }

    //Agora o metodo recursivo que faz o calculo acontecer
    else
    {
        int resultado = n * fatorial(n - 1);  
        return resultado;
    }
}

/* O primeiro bloco define o calculo que vai ser feito, agora será colocado em prática.
   Neste exemplo o usuário digitará o numero que será calculado. */

int main(){
    int numero;

    printf("Digite o numero a ser calculado: \n");  
    scanf("%d", &numero);

    if(numero < 0){
        printf("Numero invalido! \n");  
    }
    else{
        int resultado = fatorial(numero);  
        printf("O resultado de %d! e: %d \n", numero, resultado);
    }
    return 0;
}