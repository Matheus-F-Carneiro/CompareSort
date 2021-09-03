#include "bubblesort.c"
#include "insertionsort.c"
#include "quicksort.c"
#include "shellsort.c"
#include "criarvetor.c"
#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void){
    setlocale(LC_ALL, "Portuguese");
    clock_t ini, fim;
    double tempo;
    char tipo;
    char tipo1 = 'F';
    char tipo2;
    int n;
    int q;
    int i;
    float media=0;
    int *vet;
    int a = 0;
    printf("Projeto EDA - CompareSort\nMódulo de aprendizagem\nMatheus Ferreira Carneiro\n\nNesse trabalho, foram selecionados 4 métodos de ordenação (Bubble Sort, Quick Sort, Shell Sort e Insert Sort) para serem estudados.\nDentro deste módulo, iremos trabalhar com cada método independentemente, vendo certas características de cada um.\nEspecificamente, veremos o príncipio do método, o seu pseudocódigo e uma análise de complexidade.\n\n");
    printf("OBS: A escolha de qual método está sendo estudado é feita apenas uma vez. Para ver os outros, será necessário abrir o programa de novo, em parte, por causa das limitações da linguagem C.\n\n");
    printf("A primeira escolha que deve ser feita é em respeito ao método que será estudado. Digite a letra associada ao método que quer escolher:\n\nA - Bubble Sort\nB - Quick Sort\nC - Shell Sort\nD - Insertion Sort\n");
    while(a==0){
        scanf("%c", &tipo);
        getchar();
        if(tipo=='A'||tipo=='a')
            a++;
        else{
            if(tipo=='B'||tipo=='b')
                a++;
            else{
                if(tipo=='C'||tipo=='c')
                    a++;
                else{
                    if(tipo=='D'||tipo=='d')
                        a++;
                    else
                        printf("ERRO: Variável desconhecida. Tente digitar A, B, C, ou D.\n");
                }
            }
        }
    }
    if(tipo=='A'||tipo=='a'){
        printf("\nIniciando estudo de Bubble Sort.\n");
        printf("Como dito anteriormente, temos 3 características de cada método que podem ser estudadas.\n Como na etapa anterior, digite a letra referente a característica que deseja explorar (nesse caso, será possível escolher outra opção depois):\n\n");
        printf("A - Princípio do Método\nB - Pseudocódigo\nC - Análise de Complexidade (mais opções após ser escolhida)\nD - (encerrar o programa)\n");
        while(tipo1!='D'&&tipo1!='d'){
            printf("Digite A, B, C ou D para continuar:\n");
            scanf("%c", &tipo1);
            if(tipo1=='A'||tipo1=='a'){
                getchar();
                printf("\nBubble Sort (também conhecido como 'ordenação por bolha'), é o método mais simples de ordenação, aonde uma comparação é feita entre dois elementos consecutivos e troca eles se estiverem na ordem errada.\n\n");
            }
            else{
                if(tipo1=='B'||tipo1=='b'){
                    getchar();
                    printf("\nAlgoritmo Bubble Sort Pseudocódigo:\n\nEntrada:\nv: Vetor de numeros a ser ordenado.\ni: Índice do primeiro elemento de v.\nn: Índice do último elemento de v.\n\nSaída:\nv: ordenado.\n\nInício:\nPara i = 0 até n-i-1:\n  Para j=i até n-i-2:\n    Se v[j]>v[j+1]\n      Troca v[j] e v[j+1]\n\n");
                }
                else{
                    if(tipo1=='C'||tipo1=='c'){
                        printf("\nPara análise de complexidade, iremos receber o número de elementos em cada vetor, daí o tipo de ordem inicial do vetor, e então o número de ordenações que deverão ser feitas. Deve ser retornada o tempo de cada um e a média.\n");
                        printf("\nEntão, digite o número de elementos:\n");
                        scanf("%d", &n);
                        getchar();
                        a = 0;
                        printf("\nTipo de ordenação inicial (digite a letra correspondente a sua escolha):\nA - Aleatório\nB - Crescente\nC - Decrescente\n");
                        while (a==0){
                            scanf("%c", &tipo2);
                            getchar();
                            if(tipo2=='A'||tipo2=='a')
                                a++;
                            else{
                                if(tipo2=='B'||tipo2=='b')
                                    a++;
                                else{
                                    if(tipo2=='C'||tipo2=='c')
                                        a++;
                                    else
                                        printf("ERRO: Variável desconhecida. Tente digitar A, B ou C.\n");
                                }
                            }
                        }
                        printf("\nEntão, agora digite a quantidade de vezes que a pesquisa deverá ser feita:\n");
                        scanf("%d", &q);
                        getchar();
                        if(tipo2=='A'||tipo2=='a'){
                            printf("\nNúmero de elementos: %i\nTipo de ordenação inicial: Aleatória\nNúmero de ordenações: %i\n", n, q);
                            for(i=0;i<q;i++){
                                vet = vetor_rand(n);
                                ini = clock();
                                bubbleSort(vet, n);
                                fim = clock();
                                tempo = 1000 * ((double) (fim - ini)) / CLOCKS_PER_SEC;
                                printf("\ntempo%i levou: %lf ms", i + 1, tempo);
                                media += tempo;
                                free(vet);
                            }
                            printf("\n\nmedia final: %lf ms\n\n", media/q);
                            media = 0;
                        }
                        if(tipo2=='B'||tipo2=='b'){
                            printf("\nNúmero de elementos: %i\nTipo de ordenação inicial: Crescente\nNúmero de ordenações: %i\n", n, q);
                            for(i=0;i<q;i++){
                                vet = vetor_cresc(n);
                                ini = clock();
                                bubbleSort(vet, n);
                                fim = clock();
                                tempo = 1000 * ((double) (fim - ini)) / CLOCKS_PER_SEC;
                                printf("\ntempo%i levou: %lf ms", i + 1, tempo);
                                media += tempo;
                                free(vet);
                            }
                            printf("\n\nmedia final: %lf ms\n\n", media/q);
                            media = 0;
                        }
                        if(tipo2=='C'||tipo2=='c'){
                            printf("\nNúmero de elementos: %i\nTipo de ordenação inicial: Decrescente\nNúmero de ordenações: %i\n", n, q);
                            for(i=0;i<q;i++){
                                vet = vetor_decres(n);
                                ini = clock();
                                bubbleSort(vet, n);
                                fim = clock();
                                tempo = 1000 * ((double) (fim - ini)) / CLOCKS_PER_SEC;
                                printf("\ntempo%i levou: %lf ms", i + 1, tempo);
                                media += tempo;
                                free(vet);
                            }
                            printf("\n\nmedia final: %lf ms\n\n", media/q);
                            media = 0;
                        }
                    }
                    else{
                        if(tipo1=='D'||tipo1=='d');
                        else{
                            printf("ERRO: Variável desconhecida. Tente digitar A, B, C, ou D.\n");
                        }
                    }
                }
            }
        }
    }
    if(tipo=='B'||tipo=='b'){
        printf("\nIniciando estudo de Quick Sort.\n");
        printf("Como dito anteriormente, temos 3 características de cada método que podem ser estudadas.\n Como na etapa anterior, digite a letra referente a característica que deseja explorar (nesse caso, será possível escolher outra opção depois):\n\n");
        printf("A - Princípio do Método\nB - Pseudocódigo\nC - Análise de Complexidade (mais opções após ser escolhida)\nD - (encerrar o programa)\n");
        while(tipo1!='D'&&tipo1!='d'){
            printf("Digite A, B, C ou D para continuar:\n");
            scanf("%c", &tipo1);
            if(tipo1=='A'||tipo1=='a'){
                getchar();
                printf("\nQuick Sort (também conhecido como 'ordenação por partição'), é um método de ordenação baseado no conceito de dividir e conquistar. Ele pega um pivô (nesse trabalho, o pivô é sempre o elemento no centro), e divide eles em duas partes, ordenando primeiro os números que vem antes dele, e depois, os números que vem depois dele, e, de forma recursiva, separa novos pivôs para serem ordenados depois.\n\n");
            }
            else{
                if(tipo1=='B'||tipo1=='b'){
                    getchar();
                    printf("\nAlgoritmo Quick Sort Pseudocódigo:\n\nEntrada:\nv: Vetor de numeros a ser ordenado.\nleft: Índice do primeiro elemento de v que será usado na função. (importante por causa da recursão)\nright: Índice do último elemento de v que será usado na função.\n\nSaída:\nv: ordenado.\n\nInício:\nx = vet [left + right)/2]\nEnquanto i menor ou igual a j:\n  Enquanto vet[i] menor que x e i menor que right:\n    i = i + 1\n  Enquanto x menor que vet[j] e j maior que left:\n    j = j - 1\n  Se i menor ou igual a j:\n    Troca vet[i] e vet[j]\n    i = i + 1\n    j = j + 1\nSe left menor que j:\n  quicksort(vet, left, j)\nSe i menor que right:\n  quicksort(vet, i, right)\n\n");
                }
                else{
                    if(tipo1=='C'||tipo1=='c'){
                        printf("\nPara análise de complexidade, iremos receber o número de elementos em cada vetor, daí o tipo de ordem inicial do vetor, e então o número de ordenações que deverão ser feitas. Deve ser retornada o tempo de cada um e a média.\n");
                        printf("\nEntão, digite o número de elementos:\n");
                        scanf("%d", &n);
                        getchar();
                        a = 0;
                        printf("\nTipo de ordenação inicial (digite a letra correspondente a sua escolha):\nA - Aleatório\nB - Crescente\nC - Decrescente\n");
                        while (a==0){
                            scanf("%c", &tipo2);
                            getchar();
                            if(tipo2=='A'||tipo2=='a')
                                a++;
                            else{
                                if(tipo2=='B'||tipo2=='b')
                                    a++;
                                else{
                                    if(tipo2=='C'||tipo2=='c')
                                        a++;
                                    else
                                        printf("ERRO: Variável desconhecida. Tente digitar A, B ou C.\n");
                                }
                            }
                        }
                        printf("\nEntão, agora digite a quantidade de vezes que a pesquisa deverá ser feita:\n");
                        scanf("%d", &q);
                        getchar();
                        if(tipo2=='A'||tipo2=='a'){
                            printf("\nNúmero de elementos: %i\nTipo de ordenação inicial: Aleatória\nNúmero de ordenações: %i\n", n, q);
                            for(i=0;i<q;i++){
                                vet = vetor_rand(n);
                                ini = clock();
                                quickSort(vet, n);
                                fim = clock();
                                tempo = 1000 * ((double) (fim - ini)) / CLOCKS_PER_SEC;
                                printf("\ntempo%i levou: %lf ms", i + 1, tempo);
                                media += tempo;
                                free(vet);
                            }
                            printf("\n\nmedia final: %lf ms\n\n", media/q);
                            media = 0;
                        }
                        if(tipo2=='B'||tipo2=='b'){
                            printf("\nNúmero de elementos: %i\nTipo de ordenação inicial: Crescente\nNúmero de ordenações: %i\n", n, q);
                            for(i=0;i<q;i++){
                                vet = vetor_cresc(n);
                                ini = clock();
                                quickSort(vet, n);
                                fim = clock();
                                tempo = 1000 * ((double) (fim - ini)) / CLOCKS_PER_SEC;
                                printf("\ntempo%i levou: %lf ms", i + 1, tempo);
                                media += tempo;
                                free(vet);
                            }
                            printf("\n\nmedia final: %lf ms\n\n", media/q);
                            media = 0;
                        }
                        if(tipo2=='C'||tipo2=='c'){
                            printf("\nNúmero de elementos: %i\nTipo de ordenação inicial: Decrescente\nNúmero de ordenações: %i\n", n, q);
                            for(i=0;i<q;i++){
                                vet = vetor_decres(n);
                                ini = clock();
                                quickSort(vet, n);
                                fim = clock();
                                tempo = 1000 * ((double) (fim - ini)) / CLOCKS_PER_SEC;
                                printf("\ntempo%i levou: %lf ms", i + 1, tempo);
                                media += tempo;
                                free(vet);
                            }
                            printf("\n\nmedia final: %lf ms\n\n", media/q);
                            media = 0;
                        }
                    }
                    else{
                        if(tipo1=='D'||tipo1=='d');
                        else{
                            getchar();
                            printf("ERRO: Variável desconhecida. Tente digitar A, B, C, ou D.\n");
                        }
                    }
                }
            }
        }
    }
    if(tipo=='C'||tipo=='c'){
        printf("\nIniciando estudo de Shell Sort.\n");
        printf("Como dito anteriormente, temos 3 características de cada método que podem ser estudadas.\n Como na etapa anterior, digite a letra referente a característica que deseja explorar (nesse caso, será possível escolher outra opção depois):\n\n");
        printf("A - Princípio do Método\nB - Pseudocódigo\nC - Análise de Complexidade (mais opções após ser escolhida)\nD - (encerrar o programa)\n");
        while(tipo1!='D'&&tipo1!='d'){
            printf("Digite A, B, C ou D para continuar:\n");
            scanf("%c", &tipo1);
            if(tipo1=='A'||tipo1=='a'){
                getchar();
                printf("\nShell Sort é um método que adiciona mais nuance ao Insertion Sort. Especificamente, em vez de fazermos comparações 1 para 1, pegamos o primeiro número dentro de um espaço (chamado gap), e a partir daí, diminuímos esse gap até encontrar a posição certa. Pode não parecer muita diferença, mas isso tende a acelerar o programa bastante.\n\n");
            }
            else{
                if(tipo1=='B'||tipo1=='b'){
                    getchar();
                    printf("\nAlgoritmo Shell Sort Pseudocódigo:\n\nEntrada:\nv: Vetor de numeros a ser ordenado.\ni: Índice do primeiro elemento de v.\nn: Índice do último elemento de v.\n\nSaída:\nv: ordenado.\n\nInício:\nEnquanto gap = 1 menor que n:\n  gap = 3 * gap + 1 // Definindo o gap\nEnquano gap maior que 1:\n  gap = gap / 3\n  Para i=gap até n:\n    valor = vet[i]\n    j = i - gap\n    enquanto j maior ou igual a 0 e valor menor que vet[j]\n      vet[j+gap] = vet[j]\n      j -= gap\n    vet[j+gap] = valor\n\n");
                }
                else{
                    if(tipo1=='C'||tipo1=='c'){
                        printf("\nPara análise de complexidade, iremos receber o número de elementos em cada vetor, daí o tipo de ordem inicial do vetor, e então o número de ordenações que deverão ser feitas. Deve ser retornada o tempo de cada um e a média.\n");
                        printf("\nEntão, digite o número de elementos:\n");
                        scanf("%d", &n);
                        getchar();
                        a = 0;
                        printf("\nTipo de ordenação inicial (digite a letra correspondente a sua escolha):\nA - Aleatório\nB - Crescente\nC - Decrescente\n");
                        while (a==0){
                            scanf("%c", &tipo2);
                            getchar();
                            if(tipo2=='A'||tipo2=='a')
                                a++;
                            else{
                                if(tipo2=='B'||tipo2=='b')
                                    a++;
                                else{
                                    if(tipo2=='C'||tipo2=='c')
                                        a++;
                                    else
                                        printf("ERRO: Variável desconhecida. Tente digitar A, B ou C.\n");
                                }
                            }
                        }
                        printf("\nEntão, agora digite a quantidade de vezes que a pesquisa deverá ser feita:\n");
                        scanf("%d", &q);
                        getchar();
                        if(tipo2=='A'||tipo2=='a'){
                            printf("\nNúmero de elementos: %i\nTipo de ordenação inicial: Aleatória\nNúmero de ordenações: %i\n", n, q);
                            for(i=0;i<q;i++){
                                vet = vetor_rand(n);
                                ini = clock();
                                shellSort(vet, n);
                                fim = clock();
                                tempo = 1000 * ((double) (fim - ini)) / CLOCKS_PER_SEC;
                                printf("\ntempo%i levou: %lf ms", i+1, tempo);
                                media += tempo;
                                free(vet);
                            }
                            printf("\n\nmedia final: %lf ms\n\n", media/q);
                            media = 0;
                        }
                        if(tipo2=='B'||tipo2=='b'){
                            printf("\nNúmero de elementos: %i\nTipo de ordenação inicial: Crescente\nNúmero de ordenações: %i\n", n, q);
                            for(i=0;i<q;i++){
                                vet = vetor_cresc(n);
                                ini = clock();
                                shellSort(vet, n);
                                fim = clock();
                                tempo = 1000 * ((double) (fim - ini)) / CLOCKS_PER_SEC;
                                printf("\ntempo%i levou: %lf ms", i + 1, tempo);
                                media += tempo;
                                free(vet);
                            }
                            printf("\n\nmedia final: %lf ms\n\n", media/q);
                            media = 0;
                        }
                        if(tipo2=='C'||tipo2=='c'){
                            printf("\nNúmero de elementos: %i\nTipo de ordenação inicial: Decrescente\nNúmero de ordenações: %i\n", n, q);
                            for(i=0;i<q;i++){
                                vet = vetor_decres(n);
                                ini = clock();
                                shellSort(vet, n);
                                fim = clock();
                                tempo = 1000 * ((double) (fim - ini)) / CLOCKS_PER_SEC;
                                printf("\ntempo%i levou: %lf ms", i + 1, tempo);
                                media += tempo;
                                free(vet);
                            }
                            printf("\n\nmedia final: %lf ms\n\n", media/q);
                            media = 0;
                        }
                    }
                    else{
                        if(tipo1=='D'||tipo1=='d');
                        else{
                            getchar();
                            printf("ERRO: Variável desconhecida. Tente digitar A, B, C, ou D.\n");
                        }
                    }
                }
            }
        }
    }
    if(tipo=='D'||tipo=='d'){
        printf("\nIniciando estudo de Insert Sort.\n");
        printf("Como dito anteriormente, temos 3 características de cada método que podem ser estudadas.\n Como na etapa anterior, digite a letra referente a característica que deseja explorar (nesse caso, será possível escolher outra opção depois):\n\n");
        printf("A - Princípio do Método\nB - Pseudocódigo\nC - Análise de Complexidade (mais opções após ser escolhida)\nD - (encerrar o programa)\n");
        while(tipo1!='D'&&tipo1!='d'){
            printf("Digite A, B, C ou D para continuar:\n");
            scanf("%c", &tipo1);
            if(tipo1=='A'||tipo1=='a'){
                getchar();
                printf("\nInsertion Sort (também conhecido como 'ordenação por inserção') é um método um tanto simples, que consiste em ir um termo de cada vez e posicionar eles atrás do primeiro símbolo a ser menor que ele. É consistemente comparado com organizar uma mão de cartas de baralho.\n\n");
            }
            else{
                if(tipo1=='B'||tipo1=='b'){
                    getchar();
                    printf("\nAlgoritmo Insertion Sort Pseudocódigo:\n\nEntrada:\nv: Vetor de numeros a ser ordenado.\ni: Índice do primeiro elemento de v.\nn: Índice do último elemento de v.\n\nSaída:\nv: ordenado.\n\nInício:\nPara i=1 até n:\n  chave = vet[i]\n  j = i - 1\n  Enquanto j maior ou igual a 0 e vet[j] maior que chave:\n    vet [j+1] = vet[j]\n    j = j - 1\n  vet [j+1] = chave\n\n");
                }
                else{
                    if(tipo1=='C'||tipo1=='c'){
                        printf("\nPara análise de complexidade, iremos receber o número de elementos em cada vetor, daí o tipo de ordem inicial do vetor, e então o número de ordenações que deverão ser feitas. Deve ser retornada o tempo de cada um e a média.\n");
                        printf("\nEntão, digite o número de elementos:\n");
                        scanf("%d", &n);
                        getchar();
                        a = 0;
                        printf("\nTipo de ordenação inicial (digite a letra correspondente a sua escolha):\nA - Aleatório\nB - Crescente\nC - Decrescente\n");
                        while (a==0){
                            scanf("%c", &tipo2);
                            getchar();
                            if(tipo2=='A'||tipo2=='a')
                                a++;
                            else{
                                if(tipo2=='B'||tipo2=='b')
                                    a++;
                                else{
                                    if(tipo2=='C'||tipo2=='c')
                                        a++;
                                    else
                                        printf("ERRO: Variável desconhecida. Tente digitar A, B ou C.\n");
                                }
                            }
                        }
                        printf("\nEntão, agora digite a quantidade de vezes que a pesquisa deverá ser feita:\n");
                        scanf("%d", &q);
                        getchar();
                        if(tipo2=='A'||tipo2=='a'){
                            printf("\nNúmero de elementos: %i\nTipo de ordenação inicial: Aleatória\nNúmero de ordenações: %i\n", n, q);
                            for(i=0;i<q;i++){
                                vet = vetor_rand(n);
                                ini = clock();
                                insertionSort(vet, n);
                                fim = clock();
                                tempo = 1000 * ((double) (fim - ini)) / CLOCKS_PER_SEC;
                                printf("\ntempo%i levou: %lf ms", i+1, tempo);
                                media += tempo;
                                free(vet);
                            }
                            printf("\n\nmedia final: %lf ms\n\n", media/q);
                            media = 0;
                        }
                        if(tipo2=='B'||tipo2=='b'){
                            printf("\nNúmero de elementos: %i\nTipo de ordenação inicial: Crescente\nNúmero de ordenações: %i\n", n, q);
                            for(i=0;i<q;i++){
                                vet = vetor_cresc(n);
                                ini = clock();
                                insertionSort(vet, n);
                                fim = clock();
                                tempo = 1000 * ((double) (fim - ini)) / CLOCKS_PER_SEC;
                                printf("\ntempo%i levou: %lf ms", i + 1, tempo);
                                media += tempo;
                                free(vet);
                            }
                            printf("\n\nmedia final: %lf ms\n\n", media/q);
                            media = 0;
                        }
                        if(tipo2=='C'||tipo2=='c'){
                            printf("\nNúmero de elementos: %i\nTipo de ordenação inicial: Decrescente\nNúmero de ordenações: %i\n", n, q);
                            for(i=0;i<q;i++){
                                vet = vetor_decres(n);
                                ini = clock();
                                insertionSort(vet, n);
                                fim = clock();
                                tempo = 1000 * ((double) (fim - ini)) / CLOCKS_PER_SEC;
                                printf("\ntempo%i levou: %lf ms", i + 1, tempo);
                                media += tempo;
                                free(vet);
                            }
                            printf("\n\nmedia final: %lf ms\n\n", media/q);
                            media = 0;
                        }
                    }
                    else{
                        if(tipo1=='D'||tipo1=='d');
                        else{
                            getchar();
                            printf("ERRO: Variável desconhecida. Tente digitar A, B, C, ou D.\n");
                        }
                    }
                }
            }
        }
    }
    return 0;
}
