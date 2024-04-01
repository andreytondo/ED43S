#include "e1.c"

int main() {
    Lista *l = criarLista();
    int opcao;
    do {
        printf("1. Inserir notícia\n");
        printf("2. Remover notícia\n");
        printf("3. Imprimir notícias\n");
        printf("4. Calcular notícias\n");
        printf("0. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1: {
                Noticia n;
                printf("Chave: ");
                scanf("%d", &n.chave);
                printf("Título: ");
                scanf(" %[^\n]", n.titulo);
                printf("Texto: ");
                scanf(" %[^\n]", n.texto);
                printf("Tipo: (Esporte, Política, Cultura, Outros) ");
                scanf(" %[^\n]", n.tipo);
                inserirNoticia(l, &n);
                break;
            }
            case 2: {
                if (verificaListaVazia(l)) {
                    printf("Lista vazia.\n");
                    break;
                }
                int chave;
                printf("Chave: ");
                scanf("%d", &chave);
                removerNoticia(l, chave);
                break;
            }
            case 3:
                if (verificaListaVazia(l)) {
                    printf("Lista vazia.\n");
                    break;
                }
                imprimirLista(l);
                break;
            case 4:
                if (verificaListaVazia(l)) {
                    printf("Lista vazia.\n");
                    break;
                }
                calcularNoticias(l);
                break;
        }
    } while (opcao != 0);
    destruirLista(l);
    return 0;
}