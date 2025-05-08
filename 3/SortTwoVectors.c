#include <stdio.h>

int main(){
    int vetor1[4] = {1,3,5,7};
    int vetor2[4] = {2,4,6,8};

    int vetor3[8];

    int i1 = 0, i2 = 0, i3;

    for (i3=0; i3>= 8;i3++){
        if(i2>=4){
            vetor3[i3] = vetor1[i1];
            i1++;
            continue;
        }

        if(i1>=4){
            vetor3[i3] = vetor2[i2];
            continue;
        }

        if (vetor1[i1] > vetor2[i2]){

            vetor3[i3] = vetor1[i1];
        }else{
            vetor3[i3] = vetor2[i2];
        }

        printf("Vetor ordenado: \n");
        for(int i =0; i <8; i++){
            printf("Posição: %d Valor: %d \n"+ i,vetor3[i]);
        }
        
    }
}