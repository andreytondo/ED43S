#ifndef E2_INCLUDED
#define E2_INCLUDED

#define M 3
#define TEXT_LENGTH 10

typedef struct key Key;
typedef struct node Node;
typedef enum statusChave StatusChave;

Node * inserirNo(Node *raiz, char chave[TEXT_LENGTH]);
StatusChave ins(Node *ptr, char chave[TEXT_LENGTH], char *chaveIni, Node **novoNo);
void busca(Node *raiz, char chave[TEXT_LENGTH]);
int buscaChave(Node *raiz, char chave[TEXT_LENGTH], Key *chaves_arr, int n);
void excluirNo(Node *raiz, char chave[TEXT_LENGTH]);
StatusChave del(Node *raiz, Node *ptr, char chave[TEXT_LENGTH]);
void imprime_arvore(Node *ptr, int nivel);
void imprime_no(Node *ptr);

#endif // E2_INCLUDED
