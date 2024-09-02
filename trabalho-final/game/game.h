#ifndef GAME_H
#define GAME_H

#include "../item/item.h"
#include "../npc/npc.h"
#include "../location/location.h"
#include "../graph/graph.h"

void displayLocation(Location* location);
void interactWithNPC(Location* location);
int movePlayer(Graph* graph, int currentLocation);
void runGame(Graph* gameGraph);

#endif // GAME_H