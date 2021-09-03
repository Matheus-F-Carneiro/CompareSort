#include "bubblesort.c"
#include "insertionsort.c"
#include "quicksort.c"
#include "shellsort.c"
#include "criarvetor.c"
#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void tipo_to_print(char c);
void rodar_um_met(char c, char ord);

int main (void){
    setlocale(LC_ALL, "Portuguese");
    int a = 0;
    int n_met;
    char tipo_org = 'F';
    char tipo_met[4];
    char temp[4];
    int i;
    int j;
    printf("Projeto EDA - CompareSort\nMódulo de Comparação\nMatheus Ferreira Carneiro\n\nNesse trabalho, foram selecionados 4 métodos de ordenação (Bubble Sort, Quick Sort, Shell Sort e Insert Sort) para serem estudados.\nDentro deste módulo, trabalharemos com mais de um método ao mesmo tempo, com a intenção de compará-los em determinados casos.\n\n");
    printf("OBS: O número de métodos sendo comparados e os tipos de métodos só poderão ser escolhidos uma vez no começo, mas vários testes podem ser rodados posteriormente.\n\n");
    printf("Digite o número de métodos que serão avaliados:\n");
    while(a==0){
        scanf ("%i", &n_met);
        if(n_met>4||n_met<1)
            printf("\nERRO: Digite um número entre 1 e 4.\n\n");
        else
            a++;
    }
    if(n_met==4){
        printf("\nTodos os métodos serão avaliados.\n\n");
        tipo_met[0]='A';
        tipo_met[1]='B';
        tipo_met[2]='C';
        tipo_met[3]='D';
    }
    else{
        printf("\nEscolha cada um dos métodos a serem avaliados:\n\nA - Bubble Sort\nB - Quick Sort\nC - Shell Sort\nD - Insert Sort\n\n");
        for(i=0;i<n_met;i++){
            a = 0;
            while(a==0){
                getchar();
                printf("\nDigite o próximo método:\n");
                scanf("%c", &temp[i]);
                if(temp[i]=='A'||temp[i]=='a')
                    a++;
                else{
                    if(temp[i]=='B'||temp[i]=='b')
                        a++;
                    else{
                        if(temp[i]=='C'||temp[i]=='c')
                            a++;
                        else{
                            if(temp[i]=='D'||temp[i]=='d')
                                a++;
                            else
                                printf("\nERRO: Variável desconhecida. Tente digitar A, B, C, ou D.\n\n");
                        }
                    }
                }
                if (a!=0){
                    for(j=i;j>0;j--){
                        if(temp[i]==tipo_met[j]){
                            printf("\nERRO: Termo repetido. Tente uma letra não usada antes.\n\n");
                            a--;
                        }
                    }
                }
                if(a!=0)
                    tipo_met[i]=temp[i];
            }
        }
    }
    printf("\nEntão, temos os seguintes métodos escolhidos: \n");
    for(i=0;i<n_met;i++){
        tipo_to_print(tipo_met[i]);
        printf("\n");
    }
    printf("\nAgora, precisamos receber a organização inicial do vetor a ser organizado.\n");
    while(tipo_org!='D'){
        printf("\nEscolha um de:\nA - Aleatório\nB - Crescente\nC - Decrescente\nD - (encerrar o programa)\n\n");
        a = 0;
        while(a==0){
            getchar();
            scanf("%c", &tipo_org);
            if(tipo_org=='A'||tipo_org=='a')
                a++;
            else{
                if(tipo_org=='B'||tipo_org=='b')
                    a++;
                else{
                    if(tipo_org=='C'||tipo_org=='c')
                        a++;
                    else{
                        if(tipo_org=='D'||tipo_org=='d')
                            a++;
                        else
                            printf("\nERRO: Variável desconhecida. Tente digitar A, B, C, ou D.\n\n");
                    }
                }
            }
        }
        if(tipo_org!='D'&&tipo_org!='d'){
            for(i=0;i<n_met;i++){
                printf("\n");
                rodar_um_met(tipo_met[i], tipo_org);
            }
        }
    }
    return 0;
}

void tipo_to_print(char c){
    if(c=='A'||c=='a')
        printf("Bubble Sort");
    if(c=='B'||c=='b')
        printf("Quick Sort");
    if(c=='C'||c=='c')
        printf("Shell Sort");
    if(c=='D'||c=='d')
        printf("Insertion Sort");
}

void rodar_um_met(char c, char ord){
    int* vet;
    clock_t ini, fim;
    double tempo;
    double media;
    int n[] = {1000, 5000, 10000, 20000, 30000};
    int i;
    if(c=='A'||c=='a'){
        printf("Bubble Sort:");
        for(i=0;i<5;i++){
            if(ord='A'||ord=='a')
                vet = vetor_rand(n[i]);
            if(ord='B'||ord=='b')
                vet = vetor_cresc(n[i]);
            if(ord='C'||ord=='c')
                vet = vetor_decres(n[i]);
            ini = clock();
            bubbleSort(vet, n[i]);
            fim = clock();
            tempo = 1000 * ((double) (fim - ini)) / CLOCKS_PER_SEC;
            printf("\nCom %i elementos levou: %lf ms", n[i], tempo);
            free(vet);
        }
    }
    if(c=='B'||c=='b'){
        printf("Quick Sort:");
        for(i=0;i<5;i++){
            if(ord='A'||ord=='a')
                vet = vetor_rand(n[i]);
            if(ord='B'||ord=='b')
                vet = vetor_cresc(n[i]);
            if(ord='C'||ord=='c')
                vet = vetor_decres(n[i]);
            ini = clock();
            quickSort(vet, n[i]);
            fim = clock();
            tempo = 1000 * ((double) (fim - ini)) / CLOCKS_PER_SEC;
            printf("\nCom %i elementos levou: %lf ms", n[i], tempo);
            free(vet);
        }
    }
    if(c=='C'||c=='c'){
        printf("Shell Sort:");
        for(i=0;i<5;i++){
            if(ord='A'||ord=='a')
                vet = vetor_rand(n[i]);
            if(ord='B'||ord=='b')
                vet = vetor_cresc(n[i]);
            if(ord='C'||ord=='c')
                vet = vetor_decres(n[i]);
            ini = clock();
            shellSort(vet, n[i]);
            fim = clock();
            tempo = 1000 * ((double) (fim - ini)) / CLOCKS_PER_SEC;
            printf("\nCom %i elementos levou: %lf ms", n[i], tempo);
            free(vet);
        }
    }
    if(c=='D'||c=='d'){
        printf("Insertion Sort:");
        for(i=0;i<5;i++){
            if(ord='A'||ord=='a')
                vet = vetor_rand(n[i]);
            if(ord='B'||ord=='b')
                vet = vetor_cresc(n[i]);
            if(ord='C'||ord=='c')
                vet = vetor_decres(n[i]);
            ini = clock();
            insertionSort(vet, n[i]);
            fim = clock();
            tempo = 1000 * ((double) (fim - ini)) / CLOCKS_PER_SEC;
            printf("\nCom %i elementos levou: %lf ms", n[i], tempo);
            free(vet);
        }
    }
}
