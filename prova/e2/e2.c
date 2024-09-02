#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "e2.h"

struct key {
        char   musica_Andrey[TEXT_LENGTH];
};

struct node {
        int    n; /* n < M No. de chaves no n� sempre � menor que a ordem da �rvore B*/
        struct key    chaves[M - 1]; /*array de chaves*/
        struct node *p[M]; /* array de ponteiros */
};

enum statusChave {
        Duplicado,
        NaoEncontrado,
        Sucesso,
        Inseriu,
        PoucasChaves,
};


/*
 * Compare two strings
 * returns
 * 0: if they are equal
 * >0: if (int) key1[0] > (int) key2[0]
 * <0: if condition above is false
 * */
int compare(char key1[], char key2[]) {
  return strcmp(key1, key2);
}

int equals(char key1[], char key2[]) {
  return compare(key1, key2) == 0;
}

int isGreater(char key1[], char key2[]) {
  return compare(key1, key2) > 0;
}

Node * inserirNo(Node *raiz, char chave[]) {
        Node *novoNo;
        char chaveIni[TEXT_LENGTH];
        StatusChave status;
        status = ins(raiz, chave, chaveIni, &novoNo);
        if (status == Duplicado)
                printf("Chave ja inserida.\n");
        if (status == Inseriu) {
                Node *raizIni = raiz;
                raiz = (Node*)malloc(sizeof(Node));
                raiz->n = 1;
                strcpy(raiz->chaves[0].musica_Andrey, chaveIni);
                raiz->p[0] = raizIni;
                raiz->p[1] = novoNo;
        }/*Fim if */
        return raiz;
}/*Fim inserir()*/

StatusChave ins(Node *ptr, char chave[], char *chaveIni, Node **novoNo) {
        Node *novoPtr, *ultPtr;
        int pos, i, n, splitPos;
        char novaChave[TEXT_LENGTH], ultChave[TEXT_LENGTH];
        StatusChave status;
        if (ptr == NULL) {
                *novoNo = NULL;
                strcpy(chaveIni, chave);
                return Inseriu;
        }
        n = ptr->n;
        pos = buscaChave(ptr, chave, ptr->chaves, n);
        if (pos < n && equals(chave, ptr->chaves[pos].musica_Andrey))
                return Duplicado;
        status = ins(ptr->p[pos], chave, novaChave, &novoPtr);
        if (status != Inseriu)
                return status;
        /*If chaves in node is less than M-1 where M is order of B tree*/
        if (n < M - 1) {
                pos = buscaChave(ptr, novaChave, ptr->chaves, n);
                /*Shifting the chave and pointer right for inserting the new chave*/
                for (i = n; i>pos; i--) {
                        ptr->chaves[i] = ptr->chaves[i - 1];
                        ptr->p[i + 1] = ptr->p[i];
                }
                /*chave is inserted at exact location*/
                strcpy(ptr->chaves[pos].musica_Andrey, novaChave);
                ptr->p[pos + 1] = novoPtr;
                ++ptr->n; /*incrementing the number of chaves in node*/
                return Sucesso;
        }/*Fim if */
         /*If chaves in nodes are maximum and position of node to be inserted is last*/
        if (pos == M - 1) {
                strcpy(ultChave, novaChave);
                ultPtr = novoPtr;
        }
        else { /*If chaves in node are maximum and position of node to be inserted is not last*/
                strcpy(ultChave, ptr->chaves[M - 2].musica_Andrey);
                ultPtr = ptr->p[M - 1];
                for (i = M - 2; i>pos; i--) {
                        ptr->chaves[i] = ptr->chaves[i - 1];
                        ptr->p[i + 1] = ptr->p[i];
                }
                strcpy(ptr->chaves[pos].musica_Andrey, novaChave);
                ptr->p[pos + 1] = novoPtr;
        }
        splitPos = (M - 1) / 2;
        strcpy(chaveIni, ptr->chaves[splitPos].musica_Andrey);

        (*novoNo) = (Node*)malloc(sizeof(Node));/*Right node after split*/
        ptr->n = splitPos; /*No. of chaves for left splitted node*/
        (*novoNo)->n = M - 1 - splitPos;/*No. of chaves for right splitted node*/
        for (i = 0; i < (*novoNo)->n; i++) {
                (*novoNo)->p[i] = ptr->p[i + splitPos + 1];
                if (i < (*novoNo)->n - 1)
                        (*novoNo)->chaves[i] = ptr->chaves[i + splitPos + 1];
                else
                        strcpy((*novoNo)->chaves[i].musica_Andrey, ultChave);
        }
        (*novoNo)->p[(*novoNo)->n] = ultPtr;
        return Inseriu;
}/*Fim ins()*/

void busca(Node *raiz, char chave[]) {
        int pos, i, n;
        Node *ptr = raiz;
        printf("Caminho de busca:\n");
        while (ptr) {
                n = ptr->n;
                for (i = 0; i < ptr->n; i++)
                        printf(" %s", ptr->chaves[i].musica_Andrey);
                printf("\n");
                pos = buscaChave(raiz, chave, ptr->chaves, n);
                if (pos < n && equals(chave, ptr->chaves[pos].musica_Andrey)) {
                        printf("Chave %s encontrada na posicao %d do ultimo no apresentado.\n", chave, pos);
                        return;
                }
                ptr = ptr->p[pos];
        }
        printf("Chave %s nao encontrada.\n", chave);
}/*Fim busca()*/

int buscaChave(Node *raiz, char chave[], Key *chaves_arr, int n) {
        int pos = 0;
        while (pos < n && isGreater(chave, chaves_arr[pos].musica_Andrey))
                pos++;
        return pos;
}/*Fim buscaChave()*/

void excluirNo(Node *raiz, char chave[]) {
        Node *raizIni;
        StatusChave status;
        status = del(raiz, raiz, chave);
        switch (status) {
        case NaoEncontrado:
                printf("Chave %s nao encontrada.\n", chave);
                break;
        case PoucasChaves:
                raizIni = raiz;
                raiz = raiz->p[0];
                free(raizIni);
                break;
        default:
                return;
        }/*Fim switch*/
}/*Fim excluirNo()*/

StatusChave del(Node *raiz, Node *ptr, char chave[]) {
        int pos, i, pivot, n, min;
        Key *chaves_arr;
        StatusChave status;
        Node **p, *esq_ptr, *dir_ptr;

        if (ptr == NULL)
                return NaoEncontrado;
        /*Atribui status do no*/
        n = ptr->n;
        chaves_arr = ptr->chaves;
        p = ptr->p;
        min = (M - 1) / 2;/*Numero minimode chaves*/

        //Busca pela chave a ser removida
        pos = buscaChave(raiz, chave, chaves_arr, n);
        // p � uma folha
        if (p[0] == NULL) {
                if (pos == n || !isGreater(chave, chaves_arr[pos].musica_Andrey))
                        return NaoEncontrado;
                /*Desloca chaves e ponteiros para a esquerda*/
                for (i = pos + 1; i < n; i++)
                {
                        chaves_arr[i - 1] = chaves_arr[i];
                        p[i] = p[i + 1];
                }
                return --ptr->n >= (ptr == raiz ? 1 : min) ? Sucesso : PoucasChaves;
        }/*Fim if */

         //Se chave encontrada mas p nao � folha
        if (pos < n && equals(chave, chaves_arr[pos].musica_Andrey)) {
                Node *qp = p[pos], *qp1;
                int nkey;
                while (1) {
                        nkey = qp->n;
                        qp1 = qp->p[nkey];
                        if (qp1 == NULL)
                                break;
                        qp = qp1;
                }/*Fim while*/
                chaves_arr[pos] = qp->chaves[nkey - 1];
                strcpy(qp->chaves[nkey - 1].musica_Andrey, chave);
        }/*Fim if */
        status = del(raiz, p[pos], chave);
        if (status != PoucasChaves)
                return status;

        if (pos > 0 && p[pos - 1]->n > min) {
                pivot = pos - 1; /*pivo para n�s esquerdo e direito*/
                esq_ptr = p[pivot];
                dir_ptr = p[pos];
                /*Atribui status para n� da direita*/
                dir_ptr->p[dir_ptr->n + 1] = dir_ptr->p[dir_ptr->n];
                for (i = dir_ptr->n; i>0; i--) {
                        dir_ptr->chaves[i] = dir_ptr->chaves[i - 1];
                        dir_ptr->p[i] = dir_ptr->p[i - 1];
                }
                dir_ptr->n++;
                dir_ptr->chaves[0] = chaves_arr[pivot];
                dir_ptr->p[0] = esq_ptr->p[esq_ptr->n];
                chaves_arr[pivot] = esq_ptr->chaves[--esq_ptr->n];
                return Sucesso;
        }/*Fim if */
        if (pos < n && p[pos + 1]->n > min) {
                pivot = pos; /*pivo para n�s esquerdo e direito*/
                esq_ptr = p[pivot];
                dir_ptr = p[pivot + 1];
                /*Atribui status para n�s da esquerda*/
                esq_ptr->chaves[esq_ptr->n] = chaves_arr[pivot];
                esq_ptr->p[esq_ptr->n + 1] = dir_ptr->p[0];
                chaves_arr[pivot] = dir_ptr->chaves[0];
                esq_ptr->n++;
                dir_ptr->n--;
                for (i = 0; i < dir_ptr->n; i++) {
                        dir_ptr->chaves[i] = dir_ptr->chaves[i + 1];
                        dir_ptr->p[i] = dir_ptr->p[i + 1];
                }/*Fim for*/
                dir_ptr->p[dir_ptr->n] = dir_ptr->p[dir_ptr->n + 1];
                return Sucesso;
        }/*Fim if */

        if (pos == n)
                pivot = pos - 1;
        else
                pivot = pos;

        esq_ptr = p[pivot];
        dir_ptr = p[pivot + 1];
        /*realiza fus�o (merge) dos n�s da direita e esquerda*/
        esq_ptr->chaves[esq_ptr->n] = chaves_arr[pivot];
        esq_ptr->p[esq_ptr->n + 1] = dir_ptr->p[0];
        for (i = 0; i < dir_ptr->n; i++) {
                esq_ptr->chaves[esq_ptr->n + 1 + i] = dir_ptr->chaves[i];
                esq_ptr->p[esq_ptr->n + 2 + i] = dir_ptr->p[i + 1];
        }
        esq_ptr->n = esq_ptr->n + dir_ptr->n + 1;
        free(dir_ptr); /*Remove n� da direita*/
        for (i = pos + 1; i < n; i++) {
                chaves_arr[i - 1] = chaves_arr[i];
                p[i] = p[i + 1];
        }
        return --ptr->n >= (ptr == raiz ? 1 : min) ? Sucesso : PoucasChaves;
}/*Fim del()*/

/*
 * A impressao da �rvore � feita como se ela estivesse na vertical ao inv�s da horizontal, portanto cada n� � impresso na vertical,
 * com a menor chave do n� na parte inferior do n�
 */
void imprime_arvore(Node *ptr, int nivel) {
    if (ptr != NULL) {
        char indent[10] = "";
        for (int i = 0; i < nivel; i++) {
            strcat(indent, "\t");
        }

        for (int i = ptr->n; i > 0; i--) {
            imprime_arvore(ptr->p[i], nivel + 1);
            printf("%s", indent);
            printf("%s\n", ptr->chaves[i - 1].musica_Andrey);
        }
        imprime_arvore(ptr->p[0], nivel + 1);
    }
}

void imprime_no(Node *ptr) {
    if (ptr != NULL) {
        for (int i = 0; i < ptr->n; i++) {
            printf("%s", ptr->chaves[i].musica_Andrey);
        }
        printf("\n");
    }
}

// Músicas armazenadas na árvore sejam apresentadas, uma em cada linha, em ordem alfabética reversa
// precisa percorrer toda a arvore para pegar todas as chaves, apos isso deve ordenar as chaves em ordem reversa
void imprime_arvore_reversa(Node *ptr) {
        if (ptr != NULL) {
                char *musicas[100];
                int i = 0;
                imprime_arvore_reversa(ptr->p[ptr->n]);
                for (i = 0; i < ptr->n; i++) {
                       musicas[i] = ptr->chaves[i].musica_Andrey;
                }
                imprime_arvore_reversa(ptr->p[0]);
                sort_array(musicas, i);
                for (int j = 0; j < i; j++) {
                        printf("%s\n", musicas[j]);
                }
        }
}

void sort_array(char *arr[], int n) {
        int i, j;
        char *temp;
        for (i = 0; i < n - 1; i++) {
                for (j = i + 1; j < n; j++) {
                        if (strcmp(arr[i], arr[j]) < 0) {
                                temp = arr[i];
                                arr[i] = arr[j];
                                arr[j] = temp;
                        }
                }
        }
}