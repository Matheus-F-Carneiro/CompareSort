#include "shellsort.h"

void shellSort(int *vet, int n){
    int i , j , value;
    int gap = 1;
    while(gap < n)
        gap = 3*gap+1;
    while (gap > 1) {
        gap/=3;
        for(i = gap; i < n; i++) {
            value = vet[i];
            j = i - gap;
            while (j >= 0 && value < vet[j]) {
                vet [j + gap] = vet[j];
                j -= gap;
            }
            vet[j + gap] = value;
        }
    }
 }
