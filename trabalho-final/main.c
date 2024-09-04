#include <stdio.h>
#include <stdlib.h>
#include "game/game.h"
#include "item/item.h"
#include "npc/npc.h"
#include "location/location.h"
#include "graph/graph.h"

void createLocations(Graph* gameGraph) {
    gameGraph->locations[0] = createLocation("Vila", "Uma vila pacifica com habitantes amigaveis.");
    gameGraph->locations[1] = createLocation("Floresta", "Uma floresta densa cheia de misterios.");
    gameGraph->locations[2] = createLocation("Castelo", "Um castelo antigo com muitos segredos.");
    gameGraph->locations[3] = createLocation("Caverna", "Uma caverna escura e assustadora.");
    gameGraph->locations[4] = createLocation("Lago", "Um lago sereno com aguas cristalinas.");

    connectLocations(gameGraph, 0, 1); // Vila -> Floresta
    connectLocations(gameGraph, 1, 2); // Floresta -> Castelo
    connectLocations(gameGraph, 1, 3); // Floresta -> Caverna
    connectLocations(gameGraph, 2, 4); // Castelo -> Lago
    connectLocations(gameGraph, 3, 4); // Caverna -> Lago
}

void createItems(Graph* gameGraph) {
    Item sword = createItem("Espada", "Uma lamina afiada usada para lutar.");
    Item shield = createItem("Escudo", "Um escudo resistente para protecao.");
    Item potion = createItem("Pocao de Cura", "Uma pocao que restaura sua saude.");
    Item key = createItem("Chave", "Uma chave que pode abrir portas misteriosas.");
    Item map = createItem("Mapa", "Um mapa que revela todas as localizacoes do reino.");

    addItemToLocation(gameGraph->locations[0], sword);
    addItemToLocation(gameGraph->locations[0], potion);
    addItemToLocation(gameGraph->locations[2], shield);
    addItemToLocation(gameGraph->locations[3], key);
    addItemToLocation(gameGraph->locations[4], map);
}

void createNPCs(Graph* gameGraph) {
    NPC villager = createNPC("Aldeao", "Bem-vindo a nossa vila!");
    NPC knight = createNPC("Cavaleiro", "Estou em uma missao para proteger o reino.");
    NPC wizard = createNPC("Mago", "Posso te ensinar magias poderosas.");
    NPC dragon = createNPC("Dragao", "Eu guardo os segredos da caverna.");
    NPC fisherman = createNPC("Pescador", "O lago e um lugar de paz e tranquilidade.");

    addNPCToLocation(gameGraph->locations[0], villager);
    addNPCToLocation(gameGraph->locations[2], knight);
    addNPCToLocation(gameGraph->locations[2], wizard);
    addNPCToLocation(gameGraph->locations[3], dragon);
    addNPCToLocation(gameGraph->locations[4], fisherman);
}

int main() {
    // Create graph with 5 locations
    Graph* gameGraph = createGraph(5);

    createLocations(gameGraph);
    createItems(gameGraph);
    createNPCs(gameGraph);

    // Print the game graph
    printGraph(gameGraph);

    printf("\n\n");

    // Run the game
    runGame(gameGraph);

    freeGraph(gameGraph);
    return 0;
}