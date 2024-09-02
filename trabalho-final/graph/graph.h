#ifndef GRAPH_H
#define GRAPH_H

#include "../location/location.h"

typedef struct {
    Location** locations;
    int** adjacencyMatrix;
    int numLocations;
} Graph;

Graph* createGraph(int numLocations);
void connectLocations(Graph* graph, int origin, int destination);
void freeGraph(Graph* graph);

#endif // GRAPH_H