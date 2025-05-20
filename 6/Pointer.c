#include <stdio.h>
#include <stdlib.h>


/*
int main(){
    int x = 5; //Declarando uma variável normal
    int *prt = &x; //Declarando um ponteiro

    printf("Endereço apontado por prt:%d\n", prt);
    printf("Valor apontado por prt:%d\n", *prt);

    return 0;
}
*/

typedef struct /* Este bloco define a estrutura da pessoa e seus atributos*/
{
    int idade;
    float altura;
}Pessoa;

//Para não precisar ficar declarando o struct toda hora, facilitamos o processo definindo o typedef


int main(){
    Pessoa p1 = {17, 1.70};  //Declarando os valores dos atributos 
    Pessoa *prtPessoa = &p1;

    printf("Idade %d\n", prtPessoa ->idade);   //Referencia os atributos declarados e exibe na tela
    printf("Altura %.2f\n", prtPessoa ->altura); 

    return 0;
};