#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "e2.h"

struct jogo {
    char nome[50];
    char descricao[100];
    int faixaEtaria;
    char link[100];
    Jogo* prox;
    Jogo* ant;
};

struct deque {
    Jogo* frente;
    Jogo* tras;
};

Jogo* criarJogo(char* nome, char* descricao, int faixaEtaria, char* link) {
    Jogo* jogo = (Jogo*) malloc(sizeof(Jogo));
    strcpy(jogo->nome, nome);
    strcpy(jogo->descricao, descricao);
    jogo->faixaEtaria = faixaEtaria;
    strcpy(jogo->link, link);
    jogo->prox = NULL;
    jogo->ant = NULL;
    return jogo;
}

void apagarJogo(Jogo* jogo) {
    free(jogo);
}

void imprimirJogo(Jogo* jogo) {
    printf("Nome: %s\n", jogo->nome);
    printf("Descrição: %s\n", jogo->descricao);
    printf("Faixa etária: %d\n", jogo->faixaEtaria);
    printf("Link: %s\n", jogo->link);
}

Deque* criarDeque() {
    Deque* deque = (Deque*) malloc(sizeof(Deque));
    deque->frente = NULL;
    deque->tras = NULL;
    return deque;
}

void apagarDeque(Deque* deque) {
    Jogo* aux = deque->frente;
    Jogo* aux2;
    while (aux != NULL) {
        aux2 = aux->prox;
        apagarJogo(aux);
        aux = aux2;
    }
    free(deque);
}

void insere(Deque* deque, Jogo* jogo) {
    Jogo* aux = deque->frente;
    if (aux == NULL) {
        deque->frente = jogo;
        deque->tras = jogo;
    } else {
        while (aux != NULL && aux->faixaEtaria < jogo->faixaEtaria) {
            aux = aux->prox;
        }
        if (aux == NULL) {
            deque->tras->prox = jogo;
            jogo->ant = deque->tras;
            deque->tras = jogo;
        } else {
            if (aux->ant == NULL) {
                jogo->prox = aux;
                aux->ant = jogo;
                deque->frente = jogo;
            } else {
                jogo->prox = aux;
                jogo->ant = aux->ant;
                aux->ant->prox = jogo;
                aux->ant = jogo;
            }
        }
    }
}

void removeJogo(Deque* deque, char* nome) {
    Jogo* aux = deque->frente;
    Jogo* aux2;
    while (aux != NULL) {
        if (strstr(aux->nome, nome) != NULL) {
            if (aux->ant == NULL) {
                deque->frente = aux->prox;
                if (deque->frente != NULL) {
                    deque->frente->ant = NULL;
                }
            } else if (aux->prox == NULL) {
                deque->tras = aux->ant;
                if (deque->tras != NULL) {
                    deque->tras->prox = NULL;
                }
            } else {
                aux->ant->prox = aux->prox;
                aux->prox->ant = aux->ant;
            }
            aux2 = aux->prox;
            apagarJogo(aux);
            aux = aux2;
        } else {
            aux = aux->prox;
        }
    }
}

void imprimeJogo(Deque* deque, char* nome) {
    Jogo* aux = deque->frente;
    int encontrou = 0;
    while (aux != NULL) {
        if (strstr(aux->nome, nome) != NULL) {
            printf("Nome: %s\n", aux->nome);
            printf("Descrição: %s\n", aux->descricao);
            printf("Faixa etária: %d\n", aux->faixaEtaria);
            printf("Link: %s\n", aux->link);
            encontrou = 1;
        }
        aux = aux->prox;
    }
    if (!encontrou) {
        printf("Jogo não encontrado.\n");
    }
    printf("\n");
}