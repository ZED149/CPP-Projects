/*




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "List.h"
#define MAX_LEN 500

void my_swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(int argc, char*argv[])
{
    // this is the Lex.c file
    // it only works when there are 2 command line arguments
    // counting number of arguments
    if(argc == 3)
    {
        // first argument is program name
        // we take count as 3
        // argv[0] is the name of program
        // counting number of lines in input file
        FILE *ptr = fopen("./input", "r");
        if(!ptr)
        {
            perror("File Error: Unable to open input file\n");
            exit(EXIT_FAILURE);
        }

        // if file is opened
        int n = 0;  // number of lines in input file
        char buffer[MAX_LEN];
        while(fgets(buffer, MAX_LEN, ptr) != NULL)
        {
            // loop iterations will give the number of lines in the file
            n++;
        }
        // creating a string array of size n
        char **my_string = (char**)malloc(sizeof(char*) * n);
        // this is a dummy array, in case of any operation this will be used but not the actual array(my_string)
        char **dummy_my_string = (char**) malloc(sizeof(char*) * n);
        for(int i=0; i<n; i++)
        {
            my_string[i] = malloc(sizeof(char) *  20);
        }
        for(int i=0; i<n; i++)
        {
            dummy_my_string[i] = malloc(sizeof(char) *  20);
        }
        // setting file pointer to start of the file
        fseek(ptr, 0, SEEK_SET);
        int c = 0, index = 0;
        //copying data from input file to my_string
        int *my_int_arr = (int*) malloc(sizeof(int) * n);
        while(fgets(buffer, MAX_LEN, ptr) != NULL)
        {
            // reading again and copying strings into my_string
            strcpy(my_string[c], buffer);
            strcpy(dummy_my_string[c], buffer);
            my_int_arr[c++] = index++;
        }

        // now creating an empty list
        Listptr my_list = newList();
        // as of now, the list is empty
        // now applying some logic, to indirectly sort the list
        //Sort array using the Insertion's Sort algorithm (keep in my mind that insertion sort is not used on actual list instead a dummy array of indices and my_string)
        char temp[20];
        for(int i=0; i<n; i++){
            for(int j=0; j<n-1-i; j++){
                if(strcmp(dummy_my_string[j], dummy_my_string[j+1]) > 0){
                    strcpy(temp, dummy_my_string[j]);
                    strcpy(dummy_my_string[j], dummy_my_string[j+1]);
                    strcpy(dummy_my_string[j+1], temp);
                    my_swap(&my_int_arr[j], &my_int_arr[j+1]);
                }
            }
        }
        // now as the array indices are sorted
        // we can append in list
        // appending in list
        for(int i=0; i<n; i++)
            append(my_list, my_int_arr[i]);
        // now, need to the print list to the output file
        // opening output file with reading mode
        FILE *out = fopen(argv[2], "w");
        // writing to the output file
        moveFront(my_list);
        while(Index(my_list) >= 0)
        {
            fprintf(out, "%d\n", get(my_list));
            moveNext(my_list);
        }

        // now as whole functionality is completed
        // we can close both input and output files
        // and free all heap memory
        // closing files
        // closing input file
        fclose(ptr);
        fclose(out);
        // freeing memory
        // freeing dummy my_int_arr
        free(my_int_arr);
        // freeing my_string
        for(int i=0; i<n; i++)
            free(my_string[i]);
        free(my_string);
        // freeing dummy_my_string
        for(int i=0; i<n; i++)
            free(dummy_my_string[i]);
        free(dummy_my_string);
        // we also need to freelist as it is created on heap
        // freeing list
        freeList(&my_list);
    }
    else
    {
        perror("Invalid arguments\n");
        exit(EXIT_FAILURE);
    }
}
*/
