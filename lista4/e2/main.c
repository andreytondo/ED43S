#include <stdio.h>
#include <stdlib.h>
#include "Grafo.c"


/**
 * Referências
 * https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/
 * https://www.javatpoint.com/kruskal-algorithm-in-c
*/ 

int main() {
    int digrafo = 0;
    Grafo* gr = cria_Grafo(5, 5, 1);

    printf("Inclusao das arestas e relacionamento entre as cidades: \n");
    insereAresta(gr, 0, 1, digrafo, 1000);
    insereAresta(gr, 1, 3, digrafo, 650);
    insereAresta(gr, 1, 2, digrafo, 467);
    insereAresta(gr, 2, 4, digrafo,  150);
    insereAresta(gr, 3, 0, digrafo, 1340);
    insereAresta(gr, 3, 4, digrafo, 100);
    insereAresta(gr, 4, 1, digrafo, 2000);

    imprime_Grafo(gr);

    int pai[5];
    printf("\n\n\n Kruskal: \n");
    kruskal(gr, 0, pai);

    libera_Grafo(gr);
    return 0;
}
