/*
Utilize o exemplo de implementação de árvore B apresentado em aula, e faça:

a) Ajuste o projeto de árvore B disponibilizado em aula, e ajuste-o para trabalhar 
com nós cuja informação armazenada é textual, permitindo armazenar de forma fixa até 
3 chaves em cada nó. (Peso 1,5)

b) Faça uso dessa estrutura de dados para armazenar dados referentes a nomes de músicas 
de uma playlist. A cada nova música informada pelo usuário, uma nova inserção deve ser 
feita na árvore (Peso 1,0). 

c) O campo do tipo texto criado para armazenar o nome da música, deve se chamar musica_SeuNome, 
considerando que SeuNome, é o primeiro nome do aluno que está realizando a avaliação (Peso 0,5). 

d) Crie uma nova função de impressão, e use-a na função main, para que após o usuário indicar 
que não deseja mais inserir dados, as músicas armazenadas na árvore sejam apresentadas, uma em 
cada linha, em ordem alfabética reversa (decrescente). (Peso 1,0)

Exemplo: 

Playlist armazenada na Arvore-B de ordem X em ordem reversa:
. Musica ttt
. Musica eeee
. Musica ddd
. Musica aaa
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "e2.h"

int main() {
        char chave[100];
        int opcao;
        char *ptr;
        int valor;

        Node *raiz = NULL;

        while (1) {
                printf("\n1.Inserir\n");
                printf("2.Remover\n");
                printf("3.Buscar\n");
                printf("4.Imprimir arvore\n");
                printf("5.Imprimir arvore de maneira reversa\n");
                printf("6.Sair do programa\n");
                printf("\nEscolha uma das opcoes do menu: ");
                scanf("%d", &opcao);

                switch (opcao) {
                case 1:
                        strcpy(chave, "");
                        while(strcmp(chave, "0") != 0){
                            printf("\nDigite o nome da musica a ser inserida (0 para sair) \n");
                            setbuf(stdin, NULL);
                            scanf("%[^\n]s", chave);

                            if(strcmp(chave, "0") == 0) {
                                break;
                            }

                            raiz = inserirNo(raiz, chave);
                        }
                        break;
                case 2:
                        printf("Informe a musica a ser removida: ");
                        setbuf(stdin, NULL);
                        scanf("%[^\n]s", chave);
                        excluirNo(raiz, chave);
                        break;
                case 3:
                        printf("Informe a musica a ser procurada: ");
                        setbuf(stdin, NULL);
                        scanf("%[^\n]s", chave);
                        busca(raiz, chave);
                        break;
                case 4:
                        printf("Impressao da Arvore-B de ordem %d:\n", M);
                        imprime_arvore(raiz, 0);
                        break;
                case 5:
                        printf("Músicas armazenadas na árvore sejam apresentadas, uma em cada linha, em ordem alfabética reversa \n");
                        imprime_arvore_reversa(raiz);
                        
                case 6:
                        exit(1);
                default:
                        printf("Opcao invalida.\n");
                        break;
                }
        }
        return 0;
}