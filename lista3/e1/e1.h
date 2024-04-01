#ifndef E1_H_INCLUDED
#define E1_H_INCLUDED

typedef struct noticia Noticia;
typedef struct lista Lista;
typedef struct celula Celula;

Lista* criarLista();
void destruirLista(Lista* l);
void inserirNoticia(Lista* l, Noticia* n);
void removerNoticia(Lista* l, int chave);
void imprimirLista(Lista* l);
void imprimirNoticia(Noticia* n);
void calcularNoticias(Lista* l);
int verificaListaVazia(Lista* l);

#endif