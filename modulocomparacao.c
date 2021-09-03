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
    printf("Projeto EDA - CompareSort\nM�dulo de Compara��o\nMatheus Ferreira Carneiro\n\nNesse trabalho, foram selecionados 4 m�todos de ordena��o (Bubble Sort, Quick Sort, Shell Sort e Insert Sort) para serem estudados.\nDentro deste m�dulo, trabalharemos com mais de um m�todo ao mesmo tempo, com a inten��o de compar�-los em determinados casos.\n\n");
    printf("OBS: O n�mero de m�todos sendo comparados e os tipos de m�todos s� poder�o ser escolhidos uma vez no come�o, mas v�rios testes podem ser rodados posteriormente.\n\n");
    printf("Digite o n�mero de m�todos que ser�o avaliados:\n");
    while(a==0){
        scanf ("%i", &n_met);
        if(n_met>4||n_met<1)
            printf("\nERRO: Digite um n�mero entre 1 e 4.\n\n");
        else
            a++;
    }
    if(n_met==4){
        printf("\nTodos os m�todos ser�o avaliados.\n\n");
        tipo_met[0]='A';
        tipo_met[1]='B';
        tipo_met[2]='C';
        tipo_met[3]='D';
    }
    else{
        printf("\nEscolha cada um dos m�todos a serem avaliados:\n\nA - Bubble Sort\nB - Quick Sort\nC - Shell Sort\nD - Insert Sort\n\n");
        for(i=0;i<n_met;i++){
            a = 0;
            while(a==0){
                getchar();
                printf("\nDigite o pr�ximo m�todo:\n");
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
                                printf("\nERRO: Vari�vel desconhecida. Tente digitar A, B, C, ou D.\n\n");
                        }
                    }
                }
                if (a!=0){
                    for(j=i;j>0;j--){
                        if(temp[i]==tipo_met[j]){
                            printf("\nERRO: Termo repetido. Tente uma letra n�o usada antes.\n\n");
                            a--;
                        }
                    }
                }
                if(a!=0)
                    tipo_met[i]=temp[i];
            }
        }
    }
    printf("\nEnt�o, temos os seguintes m�todos escolhidos: \n");
    for(i=0;i<n_met;i++){
        tipo_to_print(tipo_met[i]);
        printf("\n");
    }
    printf("\nAgora, precisamos receber a organiza��o inicial do vetor a ser organizado.\n");
    while(tipo_org!='D'){
        printf("\nEscolha um de:\nA - Aleat�rio\nB - Crescente\nC - Decrescente\nD - (encerrar o programa)\n\n");
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
                            printf("\nERRO: Vari�vel desconhecida. Tente digitar A, B, C, ou D.\n\n");
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
