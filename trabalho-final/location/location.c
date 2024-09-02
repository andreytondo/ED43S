#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "location.h"

Location* createLocation(char* name, char* description) {
    Location* location = (Location*)malloc(sizeof(Location));
    strncpy(location->name, name, sizeof(location->name) - 1);
    strncpy(location->description, description, sizeof(location->description) - 1);
    location->items = NULL;
    location->npcs = NULL;
    location->numItems = 0;
    location->numNpcs = 0;
    return location;
}

void addItemToLocation(Location* location, Item item) {
    location->items = realloc(location->items, sizeof(Item) * (location->numItems + 1));
    location->items[location->numItems++] = item;
}

void addNPCToLocation(Location* location, NPC npc) {
    location->npcs = realloc(location->npcs, sizeof(NPC) * (location->numNpcs + 1));
    location->npcs[location->numNpcs++] = npc;
}

void freeLocation(Location* location) {
    if (location) {
        free(location->items);
        free(location->npcs);
        free(location);
    }
}