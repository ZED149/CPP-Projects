/*


#include <stdio.h>
#include "List.h"
#include "Graph.h"


int main()
{
    printf("Program starting...\n");
    printf("Checking newGraph() function\n");
    Graph g = newGraph(6);
    printf("OK: The function is working fine\n");
    printf("Checking addEdge() and print_graph_to_console() functions\n");
    addEdge(g,1, 2);
    addEdge(g,1, 3);
    addEdge(g,2, 4);
    addEdge(g,2, 5);
    addEdge(g,2, 6);
    addEdge(g,3, 4);
    addEdge(g,4, 5);
    addEdge(g,5, 6);
    print_graph_to_console(g);
    printf("OK: The functions are working fine\n");
    printf("Checking getOrder() and getSize() functions\n");
    printf("Order of Graph is: %d\n", getOrder(g));
    printf("Size of Graph is: %d\n", getSize(g));
    printf("OK: Both functions are working fine\n");
    printf("Checking addArc() function\n");
    addArc(g,6, 6);
    print_graph_to_console(g);
    printf("OK: The function is working properly\n");
    printf("Checking makeNull() function\n");
    makeNull(g);
    printf("OK: The function is working fine\n");
    printf("Checking printGraph() function\n");
    addEdge(g,1, 2);
    addEdge(g,1, 3);
    addEdge(g,2, 4);
    addEdge(g,2, 5);
    addEdge(g,2, 6);
    addEdge(g,3, 4);
    addEdge(g,4, 5);
    addEdge(g,5, 6);
    FILE *out = fopen("test", "w+");
    printGraph(out, g);
    printf("OK: This function is working properly\n");
    printf("Now testing BFS() function\n");
    Graph g2 = newGraph(7);
    addEdge(g2, 4,5);
    addEdge(g2, 4,1);
    addEdge(g2, 4,3);
    addEdge(g2, 5,3);
    addEdge(g2, 5,6);
    addEdge(g2, 5,7);
    addEdge(g2, 5,3);
    addEdge(g2, 1,3);
    addEdge(g2, 1,2);
    addEdge(g2, 3,2);
    BFS(g2, 4);
    Graph g3 = newGraph(7);
    addEdge(g3, 1, 2);
    addEdge(g3, 1, 3);
    addEdge(g3, 1, 4);
    addEdge(g3, 2, 3);
    addEdge(g3, 3, 4);
    addEdge(g3, 3, 5);
    addEdge(g3, 4, 5);
    addEdge(g3, 5, 6);
    addEdge(g3, 5, 7);
    BFS(g3, 1);
    Graph g4 = newGraph(7);
    addEdge(g4, 1, 4);
    addEdge(g4, 1, 2);
    addEdge(g4, 1, 3);
    addEdge(g4, 2, 3);
    addEdge(g4, 3, 4);
    addEdge(g4, 3, 5);
    addEdge(g4, 5, 7);
    addEdge(g4, 5, 6);
    BFS(g4, 1);
    Graph G = NULL;
    // Build graph G
    G = newGraph(35);
    for(int i=1; i<35; i++){
        if( i%7!=0 ) addEdge(G, i, i+1);
        if( i<=28  ) addEdge(G, i, i+7);
    }
    addEdge(G, 9, 31);
    addEdge(G, 17, 13);
    addEdge(G, 14, 33);
    print_graph_to_console(G);
    BFS(G, 1);
    printf("OK: The function is working properly\n");
    printf("Checking getSource() function\n");
    printf("Source vertex is: %d\n", getSource(g));
    printf("OK: The function is working fine\n");
    printf("Checking getSource(), getParent() and getDistance() functions\n");
    print_graph_to_console(g);
    printf("Source vertex before calling BFS is: %d\n", getSource(g));
    printf("Parent before calling BFS is: %d\n", getParent(g,5));
    printf("Distance before calling BFS is: %d\n", getDistance(g, 1));
    BFS(g, 3);
    printf("Source vertex after calling BFS is: %d\n", getSource(g));
    printf("Parent of %d, after calling BFS is: %d\n", 3, getParent(g, 3));
    printf("Distance of, %d to %d after calling BFS is: %d\n", 3, 6, getDistance(g, 6));
    printf("OK: These functions are working properly\n");
    Listptr temp_l = newList();
    getPath(temp_l,g,6);
    print(temp_l);
    freeGraph(&g);
    freeGraph(&g2);
    freeGraph(&g3);
    freeGraph(&g4);
    freeGraph(&G);
    freeList(&temp_l);
    fclose(out);
}
*/
