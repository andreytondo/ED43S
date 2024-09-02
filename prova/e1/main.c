/*
Utilize o exemplo de implementação de grafo apresentado em aula, o qual usa lista de adjacência, 
para modelar os vértices e arestas apresentados no grafo a seguir, que representa os tópicos de 
interesses de cada usuário em uma rede social, com o respectivo nível de interesse descrito nas 
arestas, que pode variar de 1 a 10.

Serão avaliados:

a)  Correta criação do grafo, considerando o fato dele ser dígrafo ou não, valorado ou não, com 
grau máximo correspondente ao apresentado na imagem, e informação dos vértices apresentada na 
forma de texto. (Peso 2,0)

b)  Correta impressão do grafo apresentando todos os vértices e arestas solicitados. (Peso 1,0)

c)   Escolha um vértice inicial, e execute uma busca pelo menor caminho até chegar ao vértice 
"Fulano" (Peso 1,0).
*/

#include <stdio.h>
#include <stdlib.h>
#include "e1.h"

int main() {
    int digrafo = 0;
    Grafo* gr = cria_Grafo(9, 3, 1);

    printf("Inclusao das arestas e relacionamento entre os topicos e usuarios: \n");

    // Maria
    insereAresta(gr, 5, 2, digrafo, 5); // viagens = 5
    insereAresta(gr, 5, 1, digrafo, 3); // tecnologia = 3
    insereAresta(gr, 5, 0, digrafo, 1); // investimentos = 1

    // Beltrano
    insereAresta(gr, 8, 2, digrafo, 5); // viagens = 5
    insereAresta(gr, 8, 1, digrafo, 7); // tecnologia = 7

    // Fulano
    insereAresta(gr, 7, 0, digrafo, 1); // investimentos = 1
    insereAresta(gr, 7, 4, digrafo, 7); // futebol = 7

    // Joao
    insereAresta(gr, 6, 0, digrafo, 5); // investimentos = 5
    insereAresta(gr, 6, 4, digrafo, 5); // futebol = 5
    insereAresta(gr, 6, 3, digrafo, 5); // negocios = 3

    imprime_Grafo(gr);
    libera_Grafo(gr);
    return 0;
}