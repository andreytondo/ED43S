#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "game.h"

// Color definitions
#define VERMELHO    "\x1b[31m"
#define VERDE       "\x1b[32m"
#define AZUL        "\x1b[34m"
#define AMARELO     "\x1b[33m"
#define CIANO       "\x1b[36m"
#define MAGENTA     "\x1b[35m"
#define BRANCO      "\x1b[37m"
#define RESET       "\x1b[0m"


// Function to display the current location's details
void displayLocation(Location* location) {
    printf("\n%sVoce esta em:%s %s%s\n", AZUL, RESET, VERDE, location->name);
    printf("%s%s%s\n", BRANCO, location->description, RESET);

    printf("\n%sItens disponiveis:%s\n", AMARELO, RESET);
    for (int i = 0; i < location->numItems; i++) {
        printf("- %s%s%s: %s%s%s\n", CIANO, location->items[i].name, RESET, BRANCO, location->items[i].description, RESET);
    }

    printf("\n%sNPCs presentes:%s\n", MAGENTA, RESET);
    for (int i = 0; i < location->numNpcs; i++) {
        printf("- %s%s%s\n", VERDE, location->npcs[i].name, RESET);
    }
}

// Function to interact with NPCs
void interactWithNPC(Location* location) {
    if (location->numNpcs == 0) {
        printf("%sNao existem NPCs disponiveis para interagir.%s\n", VERMELHO, RESET);
        return;
    }

    printf("%sEscolha um NPC digitando o numero:%s\n", AMARELO, RESET);
    for (int i = 0; i < location->numNpcs; i++) {
        printf("%d. %s%s%s\n", i + 1, VERDE, location->npcs[i].name, RESET);
    }

    int choice;
    scanf("%d", &choice);

    if (choice > 0 && choice <= location->numNpcs) {
        printf("\n%s%s%s: \"%s%s%s\"\n", VERDE, location->npcs[choice - 1].name, RESET, BRANCO, location->npcs[choice - 1].dialogue, RESET);
    } else {
        printf("%sEscolha invalida.%s\n", VERMELHO, RESET);
    }
}

// Function to handle player movement
int movePlayer(Graph* graph, int currentLocation) {
    printf("\n%sPara onde voce gostaria de ir? Digite o numero da localizacao:%s\n", AZUL, RESET);

    // List all connected locations
    for (int i = 0; i < graph->numLocations; i++) {
        if (graph->adjacencyMatrix[currentLocation][i] == 1) {
            printf("%d. %s%s%s\n", i, VERDE, graph->locations[i]->name, RESET);
        }
    }

    int newLocation;
    scanf("%d", &newLocation);

    // Check if the move is valid
    if (newLocation >= 0 && newLocation < graph->numLocations && graph->adjacencyMatrix[currentLocation][newLocation] == 1) {
        return newLocation;
    } else {
        printf("%sVoce nao pode ir para essa localizacao.%s\n", VERMELHO, RESET);
        return currentLocation;
    }
}


// Function to run the game loop
void runGame(Graph* gameGraph) {
    int currentLocation = 0; // Start the game at the first location

    // Game loop
    char command[50];
    while (1) {
        displayLocation(gameGraph->locations[currentLocation]);

        printf("\n%sComandos disponiveis: 'andar', 'falar', 'sair'%s\n", AMARELO, RESET);
        printf("%sDigite um comando: %s", CIANO, RESET);
        scanf("%s", command);

        if (strcmp(command, "andar") == 0) {
            currentLocation = movePlayer(gameGraph, currentLocation);
        } else if (strcmp(command, "falar") == 0) {
            interactWithNPC(gameGraph->locations[currentLocation]);
        } else if (strcmp(command, "sair") == 0) {
            printf("%sSaindo do jogo...%s\n", VERMELHO, RESET);
            break;
        } else {
            printf("%sComando invalido.%s\n", VERMELHO, RESET);
        }
        
        printf("%s=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%s", MAGENTA, RESET);

    }
}