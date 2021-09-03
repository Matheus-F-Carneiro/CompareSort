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
    printf("Projeto EDA - CompareSort\nM�dulo de aprendizagem\nMatheus Ferreira Carneiro\n\nNesse trabalho, foram selecionados 4 m�todos de ordena��o (Bubble Sort, Quick Sort, Shell Sort e Insert Sort) para serem estudados.\nDentro deste m�dulo, iremos trabalhar com cada m�todo independentemente, vendo certas caracter�sticas de cada um.\nEspecificamente, veremos o pr�ncipio do m�todo, o seu pseudoc�digo e uma an�lise de complexidade.\n\n");
    printf("OBS: A escolha de qual m�todo est� sendo estudado � feita apenas uma vez. Para ver os outros, ser� necess�rio abrir o programa de novo, em parte, por causa das limita��es da linguagem C.\n\n");
    printf("A primeira escolha que deve ser feita � em respeito ao m�todo que ser� estudado. Digite a letra associada ao m�todo que quer escolher:\n\nA - Bubble Sort\nB - Quick Sort\nC - Shell Sort\nD - Insertion Sort\n");
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
                        printf("ERRO: Vari�vel desconhecida. Tente digitar A, B, C, ou D.\n");
                }
            }
        }
    }
    if(tipo=='A'||tipo=='a'){
        printf("\nIniciando estudo de Bubble Sort.\n");
        printf("Como dito anteriormente, temos 3 caracter�sticas de cada m�todo que podem ser estudadas.\n Como na etapa anterior, digite a letra referente a caracter�stica que deseja explorar (nesse caso, ser� poss�vel escolher outra op��o depois):\n\n");
        printf("A - Princ�pio do M�todo\nB - Pseudoc�digo\nC - An�lise de Complexidade (mais op��es ap�s ser escolhida)\nD - (encerrar o programa)\n");
        while(tipo1!='D'&&tipo1!='d'){
            printf("Digite A, B, C ou D para continuar:\n");
            scanf("%c", &tipo1);
            if(tipo1=='A'||tipo1=='a'){
                getchar();
                printf("\nBubble Sort (tamb�m conhecido como 'ordena��o por bolha'), � o m�todo mais simples de ordena��o, aonde uma compara��o � feita entre dois elementos consecutivos e troca eles se estiverem na ordem errada.\n\n");
            }
            else{
                if(tipo1=='B'||tipo1=='b'){
                    getchar();
                    printf("\nAlgoritmo Bubble Sort Pseudoc�digo:\n\nEntrada:\nv: Vetor de numeros a ser ordenado.\ni: �ndice do primeiro elemento de v.\nn: �ndice do �ltimo elemento de v.\n\nSa�da:\nv: ordenado.\n\nIn�cio:\nPara i = 0 at� n-i-1:\n  Para j=i at� n-i-2:\n    Se v[j]>v[j+1]\n      Troca v[j] e v[j+1]\n\n");
                }
                else{
                    if(tipo1=='C'||tipo1=='c'){
                        printf("\nPara an�lise de complexidade, iremos receber o n�mero de elementos em cada vetor, da� o tipo de ordem inicial do vetor, e ent�o o n�mero de ordena��es que dever�o ser feitas. Deve ser retornada o tempo de cada um e a m�dia.\n");
                        printf("\nEnt�o, digite o n�mero de elementos:\n");
                        scanf("%d", &n);
                        getchar();
                        a = 0;
                        printf("\nTipo de ordena��o inicial (digite a letra correspondente a sua escolha):\nA - Aleat�rio\nB - Crescente\nC - Decrescente\n");
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
                                        printf("ERRO: Vari�vel desconhecida. Tente digitar A, B ou C.\n");
                                }
                            }
                        }
                        printf("\nEnt�o, agora digite a quantidade de vezes que a pesquisa dever� ser feita:\n");
                        scanf("%d", &q);
                        getchar();
                        if(tipo2=='A'||tipo2=='a'){
                            printf("\nN�mero de elementos: %i\nTipo de ordena��o inicial: Aleat�ria\nN�mero de ordena��es: %i\n", n, q);
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
                            printf("\nN�mero de elementos: %i\nTipo de ordena��o inicial: Crescente\nN�mero de ordena��es: %i\n", n, q);
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
                            printf("\nN�mero de elementos: %i\nTipo de ordena��o inicial: Decrescente\nN�mero de ordena��es: %i\n", n, q);
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
                            printf("ERRO: Vari�vel desconhecida. Tente digitar A, B, C, ou D.\n");
                        }
                    }
                }
            }
        }
    }
    if(tipo=='B'||tipo=='b'){
        printf("\nIniciando estudo de Quick Sort.\n");
        printf("Como dito anteriormente, temos 3 caracter�sticas de cada m�todo que podem ser estudadas.\n Como na etapa anterior, digite a letra referente a caracter�stica que deseja explorar (nesse caso, ser� poss�vel escolher outra op��o depois):\n\n");
        printf("A - Princ�pio do M�todo\nB - Pseudoc�digo\nC - An�lise de Complexidade (mais op��es ap�s ser escolhida)\nD - (encerrar o programa)\n");
        while(tipo1!='D'&&tipo1!='d'){
            printf("Digite A, B, C ou D para continuar:\n");
            scanf("%c", &tipo1);
            if(tipo1=='A'||tipo1=='a'){
                getchar();
                printf("\nQuick Sort (tamb�m conhecido como 'ordena��o por parti��o'), � um m�todo de ordena��o baseado no conceito de dividir e conquistar. Ele pega um piv� (nesse trabalho, o piv� � sempre o elemento no centro), e divide eles em duas partes, ordenando primeiro os n�meros que vem antes dele, e depois, os n�meros que vem depois dele, e, de forma recursiva, separa novos piv�s para serem ordenados depois.\n\n");
            }
            else{
                if(tipo1=='B'||tipo1=='b'){
                    getchar();
                    printf("\nAlgoritmo Quick Sort Pseudoc�digo:\n\nEntrada:\nv: Vetor de numeros a ser ordenado.\nleft: �ndice do primeiro elemento de v que ser� usado na fun��o. (importante por causa da recurs�o)\nright: �ndice do �ltimo elemento de v que ser� usado na fun��o.\n\nSa�da:\nv: ordenado.\n\nIn�cio:\nx = vet [left + right)/2]\nEnquanto i menor ou igual a j:\n  Enquanto vet[i] menor que x e i menor que right:\n    i = i + 1\n  Enquanto x menor que vet[j] e j maior que left:\n    j = j - 1\n  Se i menor ou igual a j:\n    Troca vet[i] e vet[j]\n    i = i + 1\n    j = j + 1\nSe left menor que j:\n  quicksort(vet, left, j)\nSe i menor que right:\n  quicksort(vet, i, right)\n\n");
                }
                else{
                    if(tipo1=='C'||tipo1=='c'){
                        printf("\nPara an�lise de complexidade, iremos receber o n�mero de elementos em cada vetor, da� o tipo de ordem inicial do vetor, e ent�o o n�mero de ordena��es que dever�o ser feitas. Deve ser retornada o tempo de cada um e a m�dia.\n");
                        printf("\nEnt�o, digite o n�mero de elementos:\n");
                        scanf("%d", &n);
                        getchar();
                        a = 0;
                        printf("\nTipo de ordena��o inicial (digite a letra correspondente a sua escolha):\nA - Aleat�rio\nB - Crescente\nC - Decrescente\n");
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
                                        printf("ERRO: Vari�vel desconhecida. Tente digitar A, B ou C.\n");
                                }
                            }
                        }
                        printf("\nEnt�o, agora digite a quantidade de vezes que a pesquisa dever� ser feita:\n");
                        scanf("%d", &q);
                        getchar();
                        if(tipo2=='A'||tipo2=='a'){
                            printf("\nN�mero de elementos: %i\nTipo de ordena��o inicial: Aleat�ria\nN�mero de ordena��es: %i\n", n, q);
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
                            printf("\nN�mero de elementos: %i\nTipo de ordena��o inicial: Crescente\nN�mero de ordena��es: %i\n", n, q);
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
                            printf("\nN�mero de elementos: %i\nTipo de ordena��o inicial: Decrescente\nN�mero de ordena��es: %i\n", n, q);
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
                            printf("ERRO: Vari�vel desconhecida. Tente digitar A, B, C, ou D.\n");
                        }
                    }
                }
            }
        }
    }
    if(tipo=='C'||tipo=='c'){
        printf("\nIniciando estudo de Shell Sort.\n");
        printf("Como dito anteriormente, temos 3 caracter�sticas de cada m�todo que podem ser estudadas.\n Como na etapa anterior, digite a letra referente a caracter�stica que deseja explorar (nesse caso, ser� poss�vel escolher outra op��o depois):\n\n");
        printf("A - Princ�pio do M�todo\nB - Pseudoc�digo\nC - An�lise de Complexidade (mais op��es ap�s ser escolhida)\nD - (encerrar o programa)\n");
        while(tipo1!='D'&&tipo1!='d'){
            printf("Digite A, B, C ou D para continuar:\n");
            scanf("%c", &tipo1);
            if(tipo1=='A'||tipo1=='a'){
                getchar();
                printf("\nShell Sort � um m�todo que adiciona mais nuance ao Insertion Sort. Especificamente, em vez de fazermos compara��es 1 para 1, pegamos o primeiro n�mero dentro de um espa�o (chamado gap), e a partir da�, diminu�mos esse gap at� encontrar a posi��o certa. Pode n�o parecer muita diferen�a, mas isso tende a acelerar o programa bastante.\n\n");
            }
            else{
                if(tipo1=='B'||tipo1=='b'){
                    getchar();
                    printf("\nAlgoritmo Shell Sort Pseudoc�digo:\n\nEntrada:\nv: Vetor de numeros a ser ordenado.\ni: �ndice do primeiro elemento de v.\nn: �ndice do �ltimo elemento de v.\n\nSa�da:\nv: ordenado.\n\nIn�cio:\nEnquanto gap = 1 menor que n:\n  gap = 3 * gap + 1 // Definindo o gap\nEnquano gap maior que 1:\n  gap = gap / 3\n  Para i=gap at� n:\n    valor = vet[i]\n    j = i - gap\n    enquanto j maior ou igual a 0 e valor menor que vet[j]\n      vet[j+gap] = vet[j]\n      j -= gap\n    vet[j+gap] = valor\n\n");
                }
                else{
                    if(tipo1=='C'||tipo1=='c'){
                        printf("\nPara an�lise de complexidade, iremos receber o n�mero de elementos em cada vetor, da� o tipo de ordem inicial do vetor, e ent�o o n�mero de ordena��es que dever�o ser feitas. Deve ser retornada o tempo de cada um e a m�dia.\n");
                        printf("\nEnt�o, digite o n�mero de elementos:\n");
                        scanf("%d", &n);
                        getchar();
                        a = 0;
                        printf("\nTipo de ordena��o inicial (digite a letra correspondente a sua escolha):\nA - Aleat�rio\nB - Crescente\nC - Decrescente\n");
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
                                        printf("ERRO: Vari�vel desconhecida. Tente digitar A, B ou C.\n");
                                }
                            }
                        }
                        printf("\nEnt�o, agora digite a quantidade de vezes que a pesquisa dever� ser feita:\n");
                        scanf("%d", &q);
                        getchar();
                        if(tipo2=='A'||tipo2=='a'){
                            printf("\nN�mero de elementos: %i\nTipo de ordena��o inicial: Aleat�ria\nN�mero de ordena��es: %i\n", n, q);
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
                            printf("\nN�mero de elementos: %i\nTipo de ordena��o inicial: Crescente\nN�mero de ordena��es: %i\n", n, q);
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
                            printf("\nN�mero de elementos: %i\nTipo de ordena��o inicial: Decrescente\nN�mero de ordena��es: %i\n", n, q);
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
                            printf("ERRO: Vari�vel desconhecida. Tente digitar A, B, C, ou D.\n");
                        }
                    }
                }
            }
        }
    }
    if(tipo=='D'||tipo=='d'){
        printf("\nIniciando estudo de Insert Sort.\n");
        printf("Como dito anteriormente, temos 3 caracter�sticas de cada m�todo que podem ser estudadas.\n Como na etapa anterior, digite a letra referente a caracter�stica que deseja explorar (nesse caso, ser� poss�vel escolher outra op��o depois):\n\n");
        printf("A - Princ�pio do M�todo\nB - Pseudoc�digo\nC - An�lise de Complexidade (mais op��es ap�s ser escolhida)\nD - (encerrar o programa)\n");
        while(tipo1!='D'&&tipo1!='d'){
            printf("Digite A, B, C ou D para continuar:\n");
            scanf("%c", &tipo1);
            if(tipo1=='A'||tipo1=='a'){
                getchar();
                printf("\nInsertion Sort (tamb�m conhecido como 'ordena��o por inser��o') � um m�todo um tanto simples, que consiste em ir um termo de cada vez e posicionar eles atr�s do primeiro s�mbolo a ser menor que ele. � consistemente comparado com organizar uma m�o de cartas de baralho.\n\n");
            }
            else{
                if(tipo1=='B'||tipo1=='b'){
                    getchar();
                    printf("\nAlgoritmo Insertion Sort Pseudoc�digo:\n\nEntrada:\nv: Vetor de numeros a ser ordenado.\ni: �ndice do primeiro elemento de v.\nn: �ndice do �ltimo elemento de v.\n\nSa�da:\nv: ordenado.\n\nIn�cio:\nPara i=1 at� n:\n  chave = vet[i]\n  j = i - 1\n  Enquanto j maior ou igual a 0 e vet[j] maior que chave:\n    vet [j+1] = vet[j]\n    j = j - 1\n  vet [j+1] = chave\n\n");
                }
                else{
                    if(tipo1=='C'||tipo1=='c'){
                        printf("\nPara an�lise de complexidade, iremos receber o n�mero de elementos em cada vetor, da� o tipo de ordem inicial do vetor, e ent�o o n�mero de ordena��es que dever�o ser feitas. Deve ser retornada o tempo de cada um e a m�dia.\n");
                        printf("\nEnt�o, digite o n�mero de elementos:\n");
                        scanf("%d", &n);
                        getchar();
                        a = 0;
                        printf("\nTipo de ordena��o inicial (digite a letra correspondente a sua escolha):\nA - Aleat�rio\nB - Crescente\nC - Decrescente\n");
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
                                        printf("ERRO: Vari�vel desconhecida. Tente digitar A, B ou C.\n");
                                }
                            }
                        }
                        printf("\nEnt�o, agora digite a quantidade de vezes que a pesquisa dever� ser feita:\n");
                        scanf("%d", &q);
                        getchar();
                        if(tipo2=='A'||tipo2=='a'){
                            printf("\nN�mero de elementos: %i\nTipo de ordena��o inicial: Aleat�ria\nN�mero de ordena��es: %i\n", n, q);
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
                            printf("\nN�mero de elementos: %i\nTipo de ordena��o inicial: Crescente\nN�mero de ordena��es: %i\n", n, q);
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
                            printf("\nN�mero de elementos: %i\nTipo de ordena��o inicial: Decrescente\nN�mero de ordena��es: %i\n", n, q);
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
                            printf("ERRO: Vari�vel desconhecida. Tente digitar A, B, C, ou D.\n");
                        }
                    }
                }
            }
        }
    }
    return 0;
}
