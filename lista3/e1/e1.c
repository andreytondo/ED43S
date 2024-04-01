#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "e1.h"

struct noticia {
    int chave;
    char titulo[100];
    char texto[1000];
    char tipo[20];
};

struct celula {
    Noticia noticia;
    Celula *anterior;
    Celula *proxima;
};

struct lista {
    Celula *primeira;
};

Lista* criarLista() {
    Lista *l = malloc(sizeof(Lista));
    l->primeira = NULL;
    return l;
}

void destruirLista(Lista* l) {
    Celula *c = l->primeira;
    while (c != NULL) {
        Celula *proxima = c->proxima;
        free(c);
        c = proxima;
    }
    free(l);
}

void inserirNoticia(Lista* l, Noticia* n) {
    Celula *nova = malloc(sizeof(Celula));
    nova->noticia = *n;
    nova->anterior = NULL;
    nova->proxima = l->primeira;
    if (l->primeira != NULL) {
        l->primeira->anterior = nova;
    }
    l->primeira = nova;
}

void removerNoticia(Lista* l, int chave) {
    Celula *c = l->primeira;
    while (c != NULL) {
        if (c->noticia.chave == chave) {
            if (c->anterior != NULL) {
                c->anterior->proxima = c->proxima;
            } else {
                l->primeira = c->proxima;
            }
            if (c->proxima != NULL) {
                c->proxima->anterior = c->anterior;
            }
            free(c);
            return;
        }
        c = c->proxima;
    }
}

void imprimirLista(Lista* l) {
    Celula *c = l->primeira;
    while (c != NULL) {
        imprimirNoticia(&c->noticia);
        c = c->proxima;
    }
}

void imprimirNoticia(Noticia* n) {
    printf("\n========= NOTICIA =========\n");
    printf("Chave: %d\n", n->chave);
    printf("Titulo: %s\n", n->titulo);
    printf("Texto: %s\n", n->texto);
    printf("Tipo: %s\n", n->tipo);
}

void calcularNoticias(Lista* l) {
    int esporte = 0;
    int politica = 0;
    int cultura = 0;
    int outros = 0;
    Celula *c = l->primeira;
    while (c != NULL) {
        if (strcmp(c->noticia.tipo, "Esporte") == 0) {
            esporte++;
        } else if (strcmp(c->noticia.tipo, "Política") == 0) {
            politica++;
        } else if (strcmp(c->noticia.tipo, "Cultura") == 0) {
            cultura++;
        } else {
            outros++;
        }
        c = c->proxima;
    }

    int total = esporte + politica + cultura + outros;
    printf("Esporte: %d\n", esporte);
    printf("Política: %d\n", politica);
    printf("Cultura: %d\n", cultura);
    printf("Outros: %d\n", outros);

    if (esporte > politica && esporte > cultura && esporte > outros) {
        printf("Esporte é a classificação com mais notícias (%.2f%%)\n", (float)esporte / total * 100);
    } else if (politica > cultura && politica > outros) {
        printf("Política é a classificação com mais notícias (%.2f%%)\n", (float)politica / total * 100);
    } else if (cultura > outros) {
        printf("Cultura é a classificação com mais notícias (%.2f%%)\n", (float)cultura / total * 100);
    } else if (outros > cultura || outros > politica || outros > esporte) {
        printf("Outros é a classificação com mais notícias (%.2f%%)\n", (float)outros / total * 100);
    } else {
        printf("Há mais de uma classificação com o mesmo número de notícias\n");
    }
}

int verificaListaVazia(Lista* l) {
    return l->primeira == NULL;
}