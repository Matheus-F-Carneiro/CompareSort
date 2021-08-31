#include "insertionsort.h"

void insertionSort(int vet[], int n){
    int i, chave, j;
    for (i = 1; i < n; i++){
        chave = vet[i];
        j = i - 1;
        /* Move elementos de vet[0..i-1], que s�o
          maiores que a chave , para uma posi��o um
          maior do que sua posi��o atual.*/
        while (j >= 0 && vet[j] > chave){
            vet[j + 1] = vet[j];
            j = j - 1;
        }
        vet[j + 1] = chave;
    }
}
