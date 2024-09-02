#!/bin/bash

gcc -o jogo main.c game/game.c item/item.c npc/npc.c location/location.c graph/graph.c -Iitem -Inpc -Ilocation -Igraph
./jogo