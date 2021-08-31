#include "quicksort.h"

void quickSort(int vet[], int n){
    Qs (vet, 0, n-1);
}

void Qsort(int vet[], int left, int right){
    register int i, j;
    int x, y;
    i = left;
    j = right;
    x = vet[(left + right)/2];
    do{
        while (vet[i] < x && i < right)
            i++;
        while (x < vet[j] && j > left)
            j--;
        if (i <= j) {
            y = vet[i];
            vet[i] = vet[j];
            vet[j] = y;
            i++;
            j--;
        }
    }
    while (i <= j);
    if (left < j)
        Qsort(vet, left, j);
    if (i < right)
        Qsort(vet, i, right);
 }
