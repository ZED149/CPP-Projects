


#include <stdio.h>
#include <string.h>
#include "List.h"


int main()
{
    Listptr A = newList();
    Listptr B = newList();
    Listptr C = NULL;
    int i;

    for(i=1; i<=20; i++){
        append(A,i);
        prepend(B,i);
    }

    printList(stdout,A);
    printf("\n");
    printList(stdout,B);
    printf("\n");

    for(moveFront(A); Index(A)>=0; moveNext(A)){
        printf("%d ", get(A));
    }
    printf("\n");
    for(moveBack(B); Index(B)>=0; movePrev(B)){
        printf("%d ", get(B));
    }
    printf("\n");

    C = copyList(A);
    printf("%s\n", equals(A,B)?"true":"false");
    printf("%s\n", equals(B,C)?"true":"false");
    printf("%s\n", equals(C,A)?"true":"false");


    moveFront(A);
    for(i=0; i<5; i++) moveNext(A); // at index
    // 5
    insertBefore(A, -1);            // at index
    // 6
    for(i=0; i<9; i++) moveNext(A); // at index
    // 15
    insertAfter(A, -2);
    for(i=0; i<5; i++) movePrev(A); // at index
    // 10
    delete(A);
    printList(stdout,A);
    printf("\n");
    printf("%d\n", length(A));
    clear(A);
    printf("%d\n", length(A));

    freeList(&A);
    freeList(&B);
    freeList(&C);

    return(0);
}
