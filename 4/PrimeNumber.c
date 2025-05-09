#include <stdio.h>

int main(){
    int vetor[8] = {4, 7, 10, 13, 17, 20, 23, 29}; 
    int i, j, quanti=0;

    printf("Analisando o vetor... \n");

    for(i=0;i<8;i++){
        int primo = 1;

        if(vetor[i] <= 1){
            primo=0;
        }else{
            for(j=2;j*j<=vetor[i];j++){
                if (vetor[i]%j==0){
                    primo=0;
                    break;
                }
            }
        }
        if(primo==1){
            printf("O número %d na posição %d é primo! \n",vetor[i],i);
            quanti++;
        }
    }
    printf("Total de números primos encontrados %d \n",quanti);

}