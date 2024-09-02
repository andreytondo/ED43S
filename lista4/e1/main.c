#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArvoreB.c"

int main() {
        char chave[100];
        int opcao;
        char *ptr;
        int valor;

        Node *raiz = NULL;

        printf("Criacao de Arvore-B de ordem %d, ou seja, nos com %d filhos, e no maximo %d chaves:\n", M, M, M - 1);
        while (1) {
                printf("\n1.Inserir\n");
                printf("2.Remover\n");
                printf("3.Buscar\n");
                printf("4.Imprimir arvore\n");
                printf("5.Sair do programa\n");
                printf("\nEscolha uma das opcoes do menu: ");
                scanf("%d", &opcao);

                switch (opcao) {
                case 1:
                        strcpy(chave, "");
                        while(strcmp(chave, "0") != 0){
                            printf("\nDigite o nome da pessoa a ser inserida (0 para sair) \n");
                            setbuf(stdin, NULL);
                            scanf("%[^\n]s", chave);

                            if(strcmp(chave, "0") == 0) {
                                break;
                            }

                            raiz = inserirNo(raiz, chave);
                        }
                        break;
                case 2:
                        printf("Informe a pessoa a ser removida: ");
                        setbuf(stdin, NULL);
                        scanf("%[^\n]s", chave);
                        excluirNo(raiz, chave);
                        break;
                case 3:
                        printf("Informe a pessoa a ser procurada: ");
                        setbuf(stdin, NULL);
                        scanf("%[^\n]s", chave);
                        busca(raiz, chave);
                        break;
                case 4:
                        printf("Impressao da Arvore-B de ordem %d:\n", M);
                        imprime_arvore(raiz, 0);
                        break;
                case 5:
                        exit(1);
                default:
                        printf("Opcao invalida.\n");
                        break;
                }
        }
        return 0;
}
