#include <stdio.h>
#include <string.h>
#include "item.h"

Item createItem(char* name, char* description) {
    Item item;
    strncpy(item.name, name, sizeof(item.name) - 1);
    strncpy(item.description, description, sizeof(item.description) - 1);
    return item;
}
