#include "criarvetor.h"
#include <time.h>
#include <stdlib.h>

int* vetor_rand(int n){
    srand(time(NULL));
    int *vet;
    int i;
    vet = malloc(n * sizeof(int));
    for(i=0;i<n;i++)
        vet[i] = rand();
    return vet;
}

int* vetor_cresc(int n){
    int *vet;
    int i;
    vet = malloc(n * sizeof(int));
    for(i=0;i<n;i++)
        vet[i] = i;
    return vet;
}

int* vetor_decres(int n){
    int *vet;
    int i;
    vet = malloc(n * sizeof(int));
    for(i=0;i<n;i++)
        vet[i] = n-1;
    return vet;
}
