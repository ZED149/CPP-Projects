

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Graph.h"
#include "List.h"
#include "stdbool.h"

#define NILL 100
#define INF 100


// private definition of Graph class
typedef struct GraphObj
{
    int size;   // size of Graph, number of nodes present in it
    int source_vertex;  // most recent vertex on which BFS was performed
    Listptr *my_list;
    int *parents_of_vertices;
    int *distance_of_vertices;
    int *visited_array_of_vertices;
}GraphObj;

// Graph functions start here
// *** Constructors and Destructors ***
// Constructor
// newGraph
Graph newGraph(const int number_of_vertices)
{
    // dynamically creating a new Graph
    GraphObj *g;
    g = (Graph) malloc(sizeof(GraphObj));
    // asserting
    assert(g != NULL);
    // setting up size
    g->size  = number_of_vertices;
    // setting up list
    // as we are sacrificing 0'th index
    // so, we run this loop number_of_vertices + 1 times
    // but, first I need to initialize 2-D pointer List
    // Initializing 2-D pointer List
    g->my_list = malloc(sizeof(Listptr) * (number_of_vertices + 1));

    for (int i = 0; i < number_of_vertices + 1; i++)
    {
        // now I can initialize indexes
        g->my_list[i] = newList();
    }
    // setting source vertex
    g->source_vertex = -1;
    // setting parent
    g->parents_of_vertices = (int*) malloc(sizeof(int) * (number_of_vertices + 1));
    // initializing distance array
    g->distance_of_vertices = (int*) malloc(sizeof(int) * (number_of_vertices + 1));
    // initializing visited array
    g->visited_array_of_vertices = (int*)malloc(sizeof(int) * (number_of_vertices + 1));
    // time to return
    return g;
}

// Destructor
// freeGraph
void freeGraph(Graph *pG)
{
    if(pG!=NULL && *pG!=NULL) {
        while (!isEmptyGraph(*pG)) {
            deleteGraph(*pG);
        }
        // setting size to 0
        (*pG)->size = 0;
        // freeing parents
        free((*pG)->parents_of_vertices);
        // freeing array of distances
        free((*pG)->distance_of_vertices);
        // freeing visited array
        free((*pG)->visited_array_of_vertices);
        // freeing Graph itself
        free(*pG);
        // setting Graph to NULL
        *pG = NULL;
    }
}

// getOrder
int getOrder(Graph g)
{
    if(g == NULL)
    {
        perror("Graph Error: Calling getOrder() on a NULL graph\n");
        exit(EXIT_FAILURE);
    }

    // returns the number of vertices
    return g->size;
}

// *** Access Functions ***
int getSize(Graph g)
{
    if(g == NULL)
    {
        perror("Graph Error: Calling getSize() on a NULL Graph\n");
        exit(EXIT_FAILURE);
    }

    // returns the number of edges
    // adding size of all lists
    int total_number_of_edges = 0;
    for(int i=0; i<g->size + 1; i++)
    {
        total_number_of_edges += length(g->my_list[i]);
    }
    total_number_of_edges /= 2;
    return total_number_of_edges;
}

// getSource
int getSource(Graph g)
{
    // if g is NULL
    if(g == NULL)
    {
        perror("Graph Error: Calling getSource() on a NULL graph\n");
        exit(EXIT_FAILURE);
    }
    // if BFS has not yet been called
    if(g->source_vertex == -1)
    {
        // it means BFS has not been called
        return NILL;
    }

    // if graph is not NULL
    return g->source_vertex;
}

// getParent
int getParent(Graph g, int u)
{
    // if graph is NULL
    if(g == NULL)
    {
        perror("Graph Error: Calling getParent() on a NULL graph\n");
        exit(EXIT_FAILURE);
    }

    // if BFS has not been yet called
    if(g->source_vertex == -1)
    {
        // it means BFS has not been called a single time
        return NILL;
    }

    // checking range of u
    if(!(u >= 1 && u <= getOrder(g)))
    {
        perror("Graph Error: Calling getParent() on out of bound 'u'\n");
        exit(EXIT_FAILURE);
    }

    return g->parents_of_vertices[u];
}

// getDistance
int getDistance(Graph g, int u)
{
    // if graph is NULL
    if(g == NULL)
    {
        perror("Graph Error: Calling getDistance() on a NULL graph\n");
        exit(EXIT_FAILURE);
    }

    // if BFS has not yet been called
    if(g->source_vertex == -1)
    {
        // it means BFS has not yet been called
        return INF;
    }

    // if everything is OK
    return g->distance_of_vertices[u];
}

// getPath
void getPath(Listptr l, Graph g, int u)
{
    // if g is NULL
    if(g == NULL)
    {
        perror("Graph Error: Calling getPath() on a NULL graph\n");
        exit(EXIT_FAILURE);
    }

    // dont run if getSource() == NILL
    if(getSource(g) == NILL)
    {
        perror("Graph Error: Calling getPath() before getSource() is called\n");
        exit(EXIT_FAILURE);
    }



    // finding path
    if(g->visited_array_of_vertices[u] == 0)
    {
        // appending NILL to l
        append(l,NILL);
    }
    else
    {
        // calculating path
        int x = u;
        while(x!=-0)
        {
            // prepending paths to l
            prepend(l,x);
            x = g->parents_of_vertices[x];
        }
    }
}

// makeNull
void makeNull(Graph g)
{
    // if graph is already NULL
    if(g == NULL)
    {
        perror("Graph Error: Calling makeNull() on a NULL graph\n");
        exit(EXIT_FAILURE);
    }

    // making graph NULL
    // deleting all edges of 'g'
    // it means reduce my_list[0 - n] lengths to zero
    for(int i=0; i<g->size + 1; i++)
    {
        clear(g->my_list[i]);
    }
}

// *** Manipulation Procedures ***
// addEdge
void addEdge(Graph g, int u, int v)
{
    // if graph is NULL
    if(g == NULL)
    {
        perror("Graph Error: Calling addArc() on a NULL graph\n");
        exit(EXIT_FAILURE);
    }
    // need to check range of both u and v
    // checking range of u
    if(!checkRange(g, u))
    {
        perror("Graph Error: Calling addEdge() in which 'u' is not in range\n");
        exit(EXIT_FAILURE);
    }
    // checking range of v
    if(!checkRange(g, v))
    {
        perror("Graph Error: Calling addEdge() in which 'v' is not in range\n");
        exit(EXIT_FAILURE);
    }

    // v is added to the adjacency list of u
    append(g->my_list[u],v);
    // u is added to the adjacency list of v
    append(g->my_list[v],u);
}

// addArc
void addArc(Graph g, int u, int v)
{
    // if graph is NULL
    if(g == NULL)
    {
        perror("Graph Error: Calling addArc() on a NULL graph\n");
        exit(EXIT_FAILURE);
    }
    // need to check range of both u and v
    // checking range of u
    if(!checkRange(g, u))
    {
        perror("Graph Error: Calling addArc() in which 'u' is not in range\n");
        exit(EXIT_FAILURE);
    }
    // checking range of v
    if(!checkRange(g, v))
    {
        perror("Graph Error: Calling addArc() in which 'v' is not in range\n");
        exit(EXIT_FAILURE);
    }

    // v is added to the adjacency list of u
    append(g->my_list[u],v);
}

// BFS
void BFS(Graph g, int i)
{
    // if graph is NULL
    if(g == NULL)
    {
        perror("Graph Error: Calling BFS() on a NULL graph\n");
        exit(EXIT_FAILURE);
    }
    // initializing all arrays to 0 for a fresh and accurate BFS
    itz(g,g->visited_array_of_vertices);
    itz(g,g->parents_of_vertices);
    itz(g,g->distance_of_vertices);
    // first assigning source vertex
    g->source_vertex = i;

    // if graph is not NULL
    // starting BFS traversal
   // int *visited = (int*) malloc(sizeof(int) * (g->size + 1));
    Listptr queue = newList((g->size + 1));
    int u = 0;
    g->visited_array_of_vertices[i] = 1;
    append(queue,i);
    //printf("BFS: --> ");
    //printf("%d ", i);
    while(!isEmpty(queue))
    {
        u = deleteFrontAndReturn(queue);
        int my_loop_size = length(g->my_list[u]);
        for(int v = 1; v<=my_loop_size; v++)
        {
            bool temp = isNull(g->my_list[u]);
            int mt_v = getAtIndex(g->my_list[u], v);
            if(!temp && g->visited_array_of_vertices[mt_v] == 0)
            {
                //printf("%d ", getAtIndex(g->my_list[u],v));
                // marking as visited
                g->visited_array_of_vertices[mt_v] = 1;
                // assigning parents
                g->parents_of_vertices[mt_v] = u;
                // calculating distances
                g->distance_of_vertices[mt_v] = g->distance_of_vertices[u] + 1;
                // appending to Queue
                int a = getAtIndex(g->my_list[u], v);
                append(queue,a);
            }
        }
    }
    //printf("\n");
    // freeing queue
    freeList(&queue);
}

// *** Other Operations ***
// printGraph
void printGraph(FILE *out, Graph g)
{
    // if graphs is NULL
    if(g == NULL)
    {
        perror("Graph Error: Calling printGraph() on a NULL graph\n");
        exit(EXIT_FAILURE);
    }

    // printing it to file
    // assuming that file is already opened in the main
    // and will be closed by the caller function itself
    // fprintf(out, "%d, \n", g->size);
    for(int i=0; i<g->size + 1; i++)
    {
        if(i == 0)
            continue;
        fprintf(out, "%d: ", i);
        printList(out, g->my_list[i]);
        fprintf(out, "\n");
    }
}

// print_graph_to_console
void print_graph_to_console(Graph g)
{
    if(g == NULL)
    {
        perror("Graph Error: Calling print_graph_to_console() on a NULL graph\n");
        exit(EXIT_FAILURE);
    }

    // printing size to console
    printf("Size is: %d\n", g->size);
    // now, printing adjacency list to console
    for( int i=0; i<g->size + 1; i++)
    {
        if(i == 0)
            continue;
        printf("%d: ", i);
        print(g->my_list[i]);
    }
}

// *** Other Functions ***
// isEmptyGraph
bool isEmptyGraph(Graph g)
{
    if(g == NULL)
    {
        perror("Graph Error: Calling isEmptyGraph() on a null Graph\n");
        exit(EXIT_FAILURE);
    }
    return (g->size == 0);
}

// deleteGraph
void deleteGraph(Graph g)
{
    if (g == NULL)
    {
        perror("Graph Error: Calling deleteGraph() on a NULL graph\n");
        exit(EXIT_FAILURE);
    }

    // freeing my_list
    for(int i=0; i<g->size+1; i++)
    {
        // freeing edges
        freeList(&(*(g->my_list + i)));
    }
    // freeing vertices
    free(g->my_list);
    // setting size to 0
    g->size = 0;
}

// checkRange
bool checkRange(Graph g, int val)
{
    if(g == NULL)
    {
        perror("Graph Error: Calling checkRange() on a NULL graph\n");
        exit(EXIT_FAILURE);
    }

    // returns true if val is in range
    return (val >= 1 && val <= g->size);
}

// printParents
void printParents(Graph g)
{
    // if g is NULL
    if(g == NULL)
    {
        perror("Graph Error: Calling printParents() on a NULL graph\n");
        exit(EXIT_FAILURE);
    }

    // printing parents
    for(int i=1; i<=g->size; i++)
    {
        printf("Parent of: %d is --> %d\n", i, g->parents_of_vertices[i]);
    }
}

// initializeToZero
void itz(Graph g, int* arr)
{
    for(int i = 0; i<g->size + 1; i++)
        arr[i] = 0;
}