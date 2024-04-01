

#ifndef ITEMFILE_H
#define ITEMFILE_H

typedef struct item Item;
typedef struct celula Celula;
typedef struct fila Fila;

Fila * criaFilaVazia();
int verificaFilaVazia(Fila *f);
void enfileira(Fila *f, int chave, char nome[50], float valor);
void desenfileira(Fila *f);
void imprimeFila(Fila *f);

#endif