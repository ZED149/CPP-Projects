//
// Created by salman on 4/17/23.
//

#ifndef PA2_GRAPH_H
#define PA2_GRAPH_H

// including some important files
#include "List.h"
// this file includes the class Graph

// starting from here
typedef struct GraphObj* Graph;

// *** Constructors and Destructors ***
// Constructor
Graph newGraph(int number_of_vertices);

// Destructor
void freeGraph(Graph *pG);

// *** Access Functions ***
// getOrder
int getOrder(Graph g);

// getSize
int getSize(Graph g);

// getSource
int getSource(Graph g);

// getParent
int getParent(Graph g, int u);

// getDistance
int getDistance(Graph g, int u);

// getPath
void getPath(Listptr l, Graph g, int u);

// *** Manipulation Procedures ***
// makeNull
void makeNull(Graph g);

// addEdge
void addEdge(Graph g, int u, int v);

// addArc
void addArc(Graph g, int u, int v);

// BFS
void BFS(Graph g, int s);

// *** Other Operations ***
// printGraph
void printGraph(FILE *out, Graph g);

// print
void print_graph_to_console(Graph g);

// deleteGraph
void deleteGraph(Graph g);

// isEmptyGraph
bool isEmptyGraph(Graph g);

// checkRange
bool checkRange(Graph g, int val);

// printParents
void printParents(Graph g);

// initializeToZero
void itz(Graph g, int *arr);


#endif //PA2_GRAPH_H
