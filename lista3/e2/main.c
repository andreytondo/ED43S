#include "e2.c"

int main() {
    Deque* deque = criarDeque();
    Jogo* jogo1 = criarJogo("Stardew Valley", "Descricao1", 10, "Link1");
    Jogo* jogo2 = criarJogo("The Legend of Zelda: Breath of the Wild", "Descricao2", 12, "Link2");
    Jogo* jogo3 = criarJogo("Red Dead Redemption 2", "Descricao3", 14, "Link3");
    Jogo* jogo4 = criarJogo("Dark Souls 3", "Descricao4", 16, "Link4");
    Jogo* jogo5 = criarJogo("Portal 2", "Descricao5", 18, "Link5");
    insere(deque, jogo3);
    insere(deque, jogo1);
    insere(deque, jogo5);
    insere(deque, jogo2);
    insere(deque, jogo4);
    imprimeJogo(deque, "Stardew");
    imprimeJogo(deque, "The Legend");
    imprimeJogo(deque, "Red");
    imprimeJogo(deque, "Dark");
    imprimeJogo(deque, "Portal");
    imprimeJogo(deque, "Jogo6");
    apagarDeque(deque);
    return 0;
}