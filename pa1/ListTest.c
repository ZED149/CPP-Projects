/*


#include <stdio.h>
#include "List.h"

int main()
{
    printf("Code starting from here\n");

    // Testing
    Listptr L = newList();
    append(L, 1);
    print(L);
    deleteFree(L);
    append(L, 1);
    append(L, 2);
    append(L, 5);
    append(L, 10);
    append(L, 11);
    append(L, 12);
    print(L);
    // checking moveFront and moveNext function
    moveFront(L);
    int x = 0;
    printf("Testing index(), get(), moveFront() and moveNext() functions\n");
    while(Index(L) >= 0)
    {
        x = get(L);
        // do something with x;
        printf("%d, ", x);
        moveNext(L);
    }
    printf("\nOK: These 4 functions are working fine\n");
    printf("Now testing moveBack() and movePrev() functions\n");
    moveBack(L);
    while (Index(L) >= 0)
    {
        x = get(L);
        // do something with x;
        printf("%d, ", x);
        movePrev(L);
    }
    printf("OK:  These 2 functions are working fine\n");
    printf("Now testing insertBefore() function\n");
    moveFront(L);
    insertBefore(L, 19);
    print(L);
    moveFront(L);
    moveNext(L);
    moveNext(L);
    moveNext(L);
    insertBefore(L, 99);
    print(L);
    moveBack(L);
    insertBefore(L, -39);
    print(L);
    printf("OK: This function is working fine\n");
    printf("Now testing insertAfter() function\n");
    moveBack(L);
    insertAfter(L, 69);
    print(L);
    printf("Index of cursor is now: %d\n", Index(L));
    printf("Caling moveFront()\n");
    moveFront(L);
    printf("Now index of cursor is: %d\n", Index(L));
    insertAfter(L, -54);
    print(L);
    printf("OK: This function is working properly\n");
    printf("Now testing deleteFront() and length() functions\n");
    printf("Length before deleteFront() is: %d\n", length(L));
    deleteFront(L);
    print(L);
    printf("Length after deleteFront() is: %d\n", length(L));
    printf("OK: These two functions are working fine\n");
    printf("Now testing deleteBack() function\n");
    printf("Length before deleteBack() is: %d\n", length(L));
    deleteBack(L);
    print(L);
    printf("Length after deleteBack() is: %d\n", length(L));
    printf("OK: This function is working fine\n");
    printf("Now testing clear() and prepend() functions\n");
    clear(L);
    printf("Length after clear() is: %d\n", length(L));
    printf("Adding some values to the reseted list\n");
    prepend(L, 23);
    print(L);
    printf("OK: These functions are working fine\n");
    printf("Now testing equals() function\n");
    Listptr a = newList();
    Listptr b = newList();
    append(a, 1);
    append(a, 5);
    append(a, 10);
    append(a, 56);
    append(a, -23);
    append(a, 34);

    append(b, 1);
    append(b, 5);
    append(b, 10);
    append(b, 56);
    append(b, -237);
    append(b, 34);

    printf("Both lists are: %B\n", equals(a, b));
    printf("OK: This function is working fine\n");

    printf("Now testing copyList() function\n");
    Listptr d = copyList(L);
    print(d);
    printf("OK: This function is working fine\n");

    printf("Now testing printList() function\n");
    FILE *ptr = fopen("../test", "w");
    if(ptr == NULL)
    {
        perror("Error opening test file for writing\n");
    }
    printList(ptr, b);
    fclose(ptr);
    printf("OK: This function is working fine\n");
    // making a new list
    Listptr n = newList();
    append(n, 1);
    append(n, 2);
    append(n, 3);
    append(n, 4);
    append(n, 5);
    append(n, 6);
    append(n, 7);
    append(n, 8);
    append(n, 9);
    // printing to the console
    printf("Prining 'n' before doing anything\n");
    print(n);
    printf("Now calling delete() on list\n");
    moveFront(n);
    delete(n);
    printf("After deletion is: \n");
    print(n);
}
*/
