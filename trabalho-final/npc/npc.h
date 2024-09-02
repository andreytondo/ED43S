#ifndef NPC_H
#define NPC_H

typedef struct {
    char name[50];
    char dialogue[200];
} NPC;

NPC createNPC(char* name, char* dialogue);

#endif // NPC_H