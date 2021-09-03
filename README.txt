Update 30.08.21:
Escolhendo os métodos de ordenação a serem usados:
1 - Bubble Sort: Escolhido pela sua simplicidade, e tendência a ser mais lento para um grande número de elementos. Dessa forma, pode ser o melhor candidato para por em contraste os métodos mais complexos e mais rápidos.
2 - Quick Sort: Escolhido por já cobrir alguns elementos do método Merge Sort, mas possuir o pivô, o que pode ser visto como uma aproximação diferente à ideia de dividir para conquistar.
3 - Shell Sort: Similarmente ao método Quick Sort, esse método apresenta semelhanças e diferenças com outro método. Especificamente, o Shell Sort é comparável ao método Insertion Sort, mas com a adição de um gap, ele tende a ter uma aproximação diferente, além de ser mais rápido na maioria dos casos.
4 - Insertion Sort: Escolhido especificamente na intenção de provar, ou confirmar, que ele é mais lento que o Shell Sort, e se sim, em que casos.

Update 02.09.21:
(OBS: Tecnimicamente, eu comecei a trabalhar nos programas "criarvetor.c" e "moduloaprendizagem.c" no dia 31, mas eu decidi que só iria por eles quando todo estivessem prontos.)
3 programas novos:
"moduloaprendizagem.c" é aonde está o módulo de aprendizagem. Existem nele opções para checar informações em cada um dos métodos de ordenação escolhidos, e fazer testes com um número qualquer de elementos.
"criarvetor.c" está incluso simplesmente para não precisar de um longo processo para criar vetores aleatórios, crescentes, e decrescentes. É utilizado nos dois módulos.
"modulocomparacao.c" é o último dos programas a ser feito, todo no dia 02. Ele contém o módulo de comparação. Para rodar, o programa só precisa receber o número de métodos sendo avaliados de cada vez, o tipo de cada método, e a organização inicial. Ele ira imprimir o tempo de cada método tentando ordenar vetores de 1000, 5000, 10000, 20000 e 30000 elementos.


SORTING ALGORITHMS. Geeks for Geeks, 2021. Disponível em: <https://www.geeksforgeeks.org/sorting-algorithms/>. Acesso em: 30 ago 2021.
BUBBLE SORT. Geeks for Geeks, 2021. Disponível em: <https://www.geeksforgeeks.org/bubble-sort/>. Acesso em: 30 ago 2021.
PEDAMKAR, Priya. Sorting in C. EDUCBA, 2020. Disponível em: <https://www.educba.com/sorting-in-c/>. Acesso em: 30 ago 2021.
INSERTION SORT. Geeks for Geeks, 2021. Disponível em: <https://www.geeksforgeeks.org/insertion-sort/>. Acesso em: 30 ago 2021.
SOUZA, J. É. G.; RICARTE, J. V. G.; LIMA, N. C. A. Algoritmos de Ordenação: Um Estudo Comparativo. Universidade Federal Rural do Semi-Árido, Curso de Ciência e Tecnologia. Anais do Encontro de Computação do Oeste Potiguar ECOP/UFERSA 2017 ISSN 2526-7574 – Pau dos Ferros/RN, v. 1, p. 166-173, jun. 2017. Disponível em: <https://periodicos.ufersa.edu.br/index.php/ecop>. Acesso em: 30 ago 2021.
