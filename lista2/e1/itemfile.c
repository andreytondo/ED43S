#include <stdio.h>
#include <stdlib.h>
#include "itemfile.h"

struct item {
    int chave;
    char nome[50];
    float valor;
};

struct celula {
    Item item;
    Celula *prox;
};

struct fila {
    Celula *inicio;
    Celula *fim;
};

Fila * criaFilaVazia() {
    Fila *f = (Fila*) malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

int verificaFilaVazia(Fila *f) {
    return f->inicio == NULL;
}

void enfileira(Fila *f, int chave, char nome[50], float valor) {
    Item novo;
    novo.chave = chave;
    strcpy(novo.nome, nome);
    novo.valor = valor;

    Celula *nova = (Celula*) malloc(sizeof(Celula));
    nova->item = novo;
    nova->prox = NULL;

    if (verificaFilaVazia(f)) {
        f->inicio = nova;
    } else {
        f->fim->prox = nova;
    }
    f->fim = nova;
}

void desenfileira(Fila *f) {
    if (verificaFilaVazia(f)) {
        printf("Fila vazia\n");
        return;
    }
    Celula *remover = f->inicio;
    f->inicio = f->inicio->prox;
    free(remover);
    if (f->inicio == NULL) {
        f->fim = NULL;
    }
}

void imprimeFila(Fila *f) {
    if (verificaFilaVazia(f)) {
        printf("Fila vazia\n");
        return;
    }
    Celula *celula = f->inicio;
    while (celula != NULL) {
        printf("Chave: %d\n", celula->item.chave);
        printf("Nome: %s\n", celula->item.nome);
        printf("Valor: %.2f\n", celula->item.valor);
        printf("\n");
        celula = celula->prox;
    }
}

void main() {
    Fila *f = criaFilaVazia();
    enfileira(f, 1, "Item 1", 10.0);
    enfileira(f, 2, "Item 2", 20.0);
    enfileira(f, 3, "Item 3", 30.0);
    enfileira(f, 4, "Item 4", 40.0);
    enfileira(f, 5, "Item 5", 50.0);
    imprimeFila(f);

    desenfileira(f);
    desenfileira(f);
    imprimeFila(f);
}