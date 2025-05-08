//Bubble Sort é um algoritmo de ordenação que faz a comparação dos elementos presentes no vetor e os troca de posição caso estejam fora de ordem.

#include <stdio.h>

int main(){
    int vetor[4] = {5,3,8,1};
    int i, j, aux;

    printf("Vetor original: \n");
    for(i=0; i<4;i++){
        printf("%d", vetor[i]);
    }

    for (i=0; i < 3; i++){ 
        for(j=0; j<3-i; j++){
            if (vetor[j]>vetor[j+1]){
                aux = vetor[j]; 
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;   
            }
            {
                printf("Passo i=%d j=%d ", i,j);
                for(int k=0; k<4; k++){
                    printf("%d", vetor[k]);
                }
                printf("\n");
            }
            printf("\n");
        }

        printf("\n");
    }
    printf("Vetor ordenado: \n");
    for(i=0; i<4; i++){
printf("%d", vetor[i]);
    }
    
    return 0;
}