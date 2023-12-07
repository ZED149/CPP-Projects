

#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"
#include "List.h"


int main(int argc, char* argv[])
{
    // this is main client code for this program
    // it will use functionality of Graph and List to perform some operations on a given file
    // Don't run the program if arguments are less than 3
    // argument[0] is the program name
    // checking program arguments
    if(argc < 3 || argc > 3)
    {
        perror("Invalid Syntax\n");
        exit(EXIT_FAILURE);
    }

    // If arguments are proper
    char *filename = argv[1];
    // opening the file
    FILE *file = fopen(filename, "r+");
    // checking for error
    if(!file)
    {
        perror("File Error: Error opening input file\n");
        exit(EXIT_FAILURE);
    }
    // if file is successfully opened
    int v = 0, e = 0;
    // read data from it until input = 0, 0
    // first read number_of_nodes from the file
    int number_of_nodes = 0;
    fscanf(file, "%d", &number_of_nodes);
    // now creating a Graph of extracted data
    // creates a graph of n = number_of_nodes
    Graph g = newGraph(number_of_nodes);
    // below defined loop will give us the vertices and edges
    while((fscanf(file, "%d %d", &v, &e) != 0))
    {
        if(v == 0 && e == 0)
            break;
        addEdge(g, v, e);
    }
    // print adjacency lists to the output file
    // opening output file
    char* output_filename = argv[2];
    FILE *out = fopen(output_filename, "w+");
    //print_graph_to_console(g);
    // checking for errors
    if(!out)
    {
        perror("File Error: Unable to open file for output\n");
        exit(EXIT_FAILURE);
    }
    // printing graph to the file
    printGraph(out, g);
    // now for 2nd part, read again from input file from where the cursor left
    v = 0, e = 0;
    while((fscanf(file, "%d %d", &v, &e) != 0))
    {
        Listptr l = newList();
        if(v == 0 && e == 0)
            break;
        // initiating BFS algorithm
        BFS(g, v);
        fprintf(out, "\nThe distance from %d to %d is %d\n", v, e, getDistance(g, e));
        fprintf(out, "A shortest %d-%d is: ", v ,e);
        getPath(l, g, e);
        printList(out, l);
        freeList(&l);
    }
    fprintf(out, "\n");
    // freeing graph
    freeGraph(&g);
    // closing files
    fclose(file);
    fclose(out);
}
