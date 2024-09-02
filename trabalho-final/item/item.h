#ifndef ITEM_H
#define ITEM_H

typedef struct {
    char name[50];
    char description[100];
} Item;

Item createItem(char* name, char* description);

#endif // ITEM_H