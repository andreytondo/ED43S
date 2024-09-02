#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

Graph* createGraph(int numLocations) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numLocations = numLocations;
    graph->locations = (Location**)malloc(sizeof(Location*) * numLocations);
    graph->adjacencyMatrix = (int**)malloc(sizeof(int*) * numLocations);
    for (int i = 0; i < numLocations; i++) {
        graph->adjacencyMatrix[i] = (int*)calloc(numLocations, sizeof(int));
    }
    return graph;
}

void connectLocations(Graph* graph, int origin, int destination) {
    if (origin >= 0 && origin < graph->numLocations && destination >= 0 && destination < graph->numLocations) {
        graph->adjacencyMatrix[origin][destination] = 1;
        graph->adjacencyMatrix[destination][origin] = 1;
    }
}

void freeGraph(Graph* graph) {
    if (graph) {
        for (int i = 0; i < graph->numLocations; i++) {
            freeLocation(graph->locations[i]);
            free(graph->adjacencyMatrix[i]);
        }
        free(graph->locations);
        free(graph->adjacencyMatrix);
        free(graph);
    }
}