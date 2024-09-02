#ifndef LOCATION_H
#define LOCATION_H

#include "../item/item.h"
#include "../npc/npc.h"

typedef struct {
    char name[50];
    char description[200];
    Item* items;
    NPC* npcs;
    int numItems;
    int numNpcs;
} Location;

Location* createLocation(char* name, char* description);
void addItemToLocation(Location* location, Item item);
void addNPCToLocation(Location* location, NPC npc);
void freeLocation(Location* location);

#endif // LOCATION_H