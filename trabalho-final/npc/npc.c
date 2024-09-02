#include <stdio.h>
#include <string.h>
#include "npc.h"

NPC createNPC(char* name, char* dialogue) {
    NPC npc;
    strncpy(npc.name, name, sizeof(npc.name) - 1);
    strncpy(npc.dialogue, dialogue, sizeof(npc.dialogue) - 1);
    return npc;
}