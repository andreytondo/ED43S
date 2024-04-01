/*
Utilize uma estrutura de deque encadeada para armazenar dados de jogos para uma determinada 
faixa etária. A struct a ser
utilizada deve ter os seguintes campos: nome do jogo, descrição, faixa etária e link para
acesso.
Adapte um dos TAD utilizados em aula para trabalhar com o item acima, e também faça o
que é pedido:
a) A função insere() deve inserir elementos de forma que estes permaneçam ordenados em
ordem crescente de faixa etária;
b) A função remove(char nome[]) deve apagar elementos baseado no nome do jogo;
c) Uma função imprime_contato(char nome[]) deve encontrar um jogo permitindo busca
parcial por nome, imprimindo seus dados na tela, ou mostrando mensagem de que o jogo
não foi encontrado.
*/

#ifndef E2_H_INCLUDED
#define E2_H_INCLUDED

typedef struct jogo Jogo;
typedef struct deque Deque;

Jogo* criarJogo(char* nome, char* descricao, int faixa_etaria, char* link);
void apagarJogo(Jogo* jogo);
void imprimirJogo(Jogo* jogo);

Deque* criarDeque();
void apagarDeque(Deque* deque);
void insere(Deque* deque, Jogo* jogo);
void imprimeJogo(Deque* deque, char* nome);
void removeJogo(Deque* deque, char* nome);
void imprimeJogo(Deque* deque, char* nome);

#endif