

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include "List.h"
// this file contains the definitions for the List.h class


// Creating Node object structure
typedef struct Node* Nodeptr;
typedef struct Node
{
    int data;
    Nodeptr next;
    Nodeptr prev;
}Node;


// Constructor and Destructor for Node class
// Constructor of Node
Nodeptr newNode(int data){
    Nodeptr N = malloc(sizeof(Node));
    assert( N!=NULL );
    N->data = data;
    N->next = NULL;
    return(N);
}

// Destructor of Node
void freeNode(Nodeptr* pN){
    if( pN!=NULL && *pN!=NULL ){
        free(*pN);
        *pN = NULL;
    }
}


/********************************************************/
// Creating Doubly Linked List definitions from here
typedef struct List
{
    Nodeptr head;
    Nodeptr tail;
    Nodeptr cursor;
    int index;
    int length;
}Listobj;


// Creating Constructor and Destructor of Doubly Linked List a.k.a List
// Constructor
Listptr newList()
{
    Listptr Q;
    Q = malloc(sizeof(List));
    assert( Q!=NULL );
    // setting length
    Q->length = 0;
    // setting cursor to NULL and index to -1
    Q->cursor = NULL;
    Q->index = -1;
    // allocating head and tail pointers
    Q->head = newNode(-1);
    Q->tail = newNode(-1);
    // setting pointers to null
    Q->head->prev = Q->tail->next = NULL;
    // setting pointers to each other
    Q->head->next = Q->tail;
    Q->tail->prev = Q->head;

    // Returning
    return(Q);
}


// Destructor
void freeList(Listptr *pl)
{
    if(pl!=NULL && *pl!=NULL) {
        while (!isEmpty(*pl)) {
            deleteFree(*pl);
        }
        // freeing head and tail pointers
        free((*pl)->head);
        free((*pl)->tail);
        // freeing list
        free(*pl);
        *pl = NULL;
    }
}



// Access Functions
// index
//Returns index of cursor element, if defined
//-1 otherwise
int Index(Listptr l)
{
    // this function returns the index of the cursor in the list
    // it returns -1, if cursor is undefined
    if(l->cursor == NULL)
    {
        return -1;
    }
    else
        return l->index;
}

// length
// Returns the number of elements in L
int length(Listptr l)
{
    // this function returns the current length of the list
    return l->length;
}

// front
// Returns front element of L
// Pre: length() > 0
int front(Listptr l)
{
    // this functions returns the data of the first element in the list
    // in order to return, length must be greater than 0
    // if not then exit
    if(l->length <= 0)
    {
        printf("List Error: Calling front() on an empty list\n");
        exit(EXIT_FAILURE);
    }

    // if length is not zero
    return l->head->next->data;
}

// back
// Returns back element of L
// Pre: length() > 0
int back(Listptr l)
{
    // this functions returns the data of the last element of the list
    // in order to return, length must be greater than 0
    // if not then exit
    if(l->length <=0)
    {
        printf("List Error: Calling back() on an empty list\n");
        exit(EXIT_FAILURE);
    }

    // if length is not zero
    return l->tail->prev->data;
}

// get
// Returns the cursor element of the L
// Pre: length() > 0 AND index >=0
int get(Listptr l)
{
    // this functions returns the data in the cursor element of the list
    // in order to return, length must be >= 0 AND index >= 0
    // if not then exit
    if(l->length <=0 || l->index < 0)
    {
        printf("List Error: Calling get() on an empty list\n");
        exit(EXIT_FAILURE);
    }

    // if both conditions meet
    return l->cursor->data;
}

// equals
// Returns true iff A and B are in same state, and retuns false otherwise
bool equals(Listptr a, Listptr b)
{
    // this function iterates on 2 lists and checks whether they are exactly same or not
    // first check length is equal, if not return false
    if(a->length == b->length)
    {
        // if both list lengths are equal
        // now iterate on both lists and checks whether 'data' is also same on same indexes
        // if at any point not same, return false
        // iterating through both lists
        a->cursor = a->head->next;
        b->cursor = b->head->next;
        while(a->cursor != a->tail || b->cursor != b->tail)
        {
            if(a->cursor->data != b->cursor->data)
                return false;
            a->cursor = a->cursor->next;
            b->cursor = b->cursor->next;
        }
        // if we exit loop, it means both lists has same data on same indexes
        // return true then
        return true;
    }
    else
        // if they are not equal
        return false;
}

// Manipulation Procedures
// clear
// Resets L to its original empty state
void clear(Listptr l)
{
    // this function deletes everything, except head and tail node
    // setting cursor
    l->cursor = l->head->next;
    // traversing
    while(l->cursor != l->tail)
    {
        // storing node to be deleted
        Nodeptr n = l->cursor;
        // incrementing cursor
        l->cursor = l->cursor->next;
        // freeing node
        free(n);
        // decreasing length
        l->length--;
    }
}

// set
// Overwrites the cursor element's data with 'x'
// Pre: length() > 0 AND index >= 0
void set(Listptr l, int x)
{
    // this functions set the 'x' to the cursor->data of the list
    // in order to set, length AND index >=0
    // if not then exit
    if(l->length <=0 || l->index <= 0)
    {
        printf("List Error: Calling set() on an empty list\n");
        exit(EXIT_FAILURE);
    }

    // if both conditions meet
    l->cursor->data = x;
}

// moveFront
// If L is non-empty, sets cursor under the front element
// otherwise does nothing
void moveFront(Listptr l)
{
    // this function set the cursor to the first element of the list
    // in order to set, list must not be empty
    // if list is empty, then this functions perform no task
    if(l->length > 0)
    {
        // if list is not empty
        l->cursor = l->head->next;
        // setting index also
        l->index = 0;
    }
}

// moveBack
// If L is non-empty, sets cursor under the back element
// otherwise does nothing
void moveBack(Listptr l)
{
    // this function set the cursor to the last element of the list
    // in order to set, list must not be empty
    // if list is empty, then this functions perform no task
    if(l->length > 0)
    {
        // if list is not empty
        l->cursor = l->tail->prev;
        // setting index also
        l->index = l->length - 1;
    }
}

// movePrev
// If cursor is defined and not at front, move cursor one step forward towards front of L
// if cursor is defined and at front, cursor becomes undefined
// if cursor is undefined, do nothing
void movePrev(Listptr l)
{
    // this functions moves cursor 1 step back, it means cursor--
    // following some certain conditions
    if(l->cursor == NULL || l->cursor == l->head)
    {
        // do nothing
    }
    else if(l->cursor == l->head->next)
    {
        // if cursor is at head->next, means front
        // make it undefined
        l->cursor = NULL;
        // also setting index
        l->index = 0;
    }
    else
    {
        // if cursor is not null, and is not at head
        l->cursor = l->cursor->prev;
        // also decreasing index
        l->index--;
    }
}

// moveNext
// If cursor is defined and not at back, move cursor one step towards the back of L
// if cursor is defined and at back, cursor becomes undefined
// if cursor is undefined, do nothing
void moveNext(Listptr l)
{
    // this functions moves cursor one step forward towards the tail of the list, means cursor++
    // following some certain conditions
    if(l->cursor == NULL)
    {
        // do nothing
    }
    else if(l->cursor == l->tail->prev)
    {
        // if cursor is at tail->prev, means at the last element
        // make it undefined
        l->cursor = NULL;
        // also setting index
        l->index = l->length - 1;
    }
    else
    {
        // if cursor is not null and not at tail
        l->cursor = l->cursor->next;
        // also setting index
        l->index++;
    }
}

// prepend
// Inserts new element into L
// if L is non-empty, insertions takes place before front element
void prepend(Listptr L, int x)
{
    // this functions inserts a new value at the start of the list
    if(L->length == 0)
    {
        // if there is 0 element in the list
        // then it doesn't matter where we insert, it will be same in all cases
        // creating a new node
        Nodeptr n = newNode(x);
        //setting pointers
        L->head->next = n;
        L->tail->prev = n;
        //setting new node pointers
        n->next = L->tail;
        n->prev = L->head;
        // incrementing length
        L->length++;
    }
    else
    {
        // creating a new node
        Nodeptr n = newNode(x);
        //setting pointers
        n->next = L->head->next;
        L->head->next = n;
        n->next->prev = n;
        n->prev = L->head;
        // incrementing length
        L->length++;
    }
}

// insertBefore
// Insert new element before cursor
// Pre: length() > 0 AND index >= 0
void insertBefore(Listptr l, int x)
{
    // this function inserts 'x' before the cursor element
    // list must not be empty
    if(l->length < 0 || l->index < 0 )
    {
        // if list is empty
        printf("List Error: Calling insertBefore() on an undefined list\n");
        exit(EXIT_FAILURE);
    }

    // implementing some test cases
    if(l->length == 0)
    {
        // if list is empty and this function is called
        // then it doesn't matter where the cursor is, it will insert 1 value to the list
        // creating a new node
        Nodeptr n = newNode(x);
        //setting pointers
        l->head->next = n;
        l->tail->prev = n;
        //setting new node pointers
        n->next = l->tail;
        n->prev = l->head;
        // incrementing length
        l->length++;
        //also setting index and cursor
        l->index = 0;
        l->cursor = l->head->next;
    }
    else
    {
        // creating a new node
        Nodeptr n = newNode(x);
        //setting pointers
        n->next = l->cursor;
        n->prev = l->cursor->prev;
        l->cursor->prev->next = n;
        l->cursor->prev = n;
        // incrementing length
        l->length++;
    }
}

// insertAfter
// Insert new element after cursor
// Pre: length() > 0 AND index >= 0
void insertAfter(Listptr l, int x)
{
    // this functions inserts 'x' after the cursor of the list
    // list must not be empty
    if(l->length < 0 || l->index < 0 )
    {
        // if list is empty
        printf("List Error: Calling insertAfter() on an undefined list\n");
        exit(EXIT_FAILURE);
    }

    // implementing some test cases
    if(l->length == 0)
    {
        // if list is empty and this function is called
        // then it doesn't matter where the cursor is, it will insert 1 value to the list
        // creating a new node
        Nodeptr n = newNode(x);
        //setting pointers
        l->head->next = n;
        l->tail->prev = n;
        //setting new node pointers
        n->next = l->tail;
        n->prev = l->head;
        // incrementing length
        l->length++;
        // also setting index and cursor
        l->index = 0;
        l->cursor = l->head->next;
    }
    else
    {
        // creating a new node
        Nodeptr n = newNode(x);
        //setting pointers
        n->next = l->cursor->next;
        n->prev = l->cursor;
        l->cursor->next->prev = n;
        l->cursor->next = n;
        // incrementing length
        l->length++;
    }
}

// deleteFront
// Delete the front element.
// Pre: length() > 0
void deleteFront(Listptr l)
{
    // this function deletes the first element of the list
    // in order to do this, list must not be empty
    // if empty, exit
    if(l->length <= 0)
    {
        printf("List Error: Calling deleteFront() on an empty list\n");
        exit(EXIT_FAILURE);
    }

    // if list is not empty
    // storing front node, which needs to be deleted
    Nodeptr n = l->head->next;
    // setting pointers
    l->head->next = n->next;
    n->next->prev = n->prev;
    // freeing n node
    free(n);
    //decreasing length by 1
    l->length--;
}

// deleteBack
// Delete back element
// Pre: length() > 0
void deleteBack(Listptr l)
{
    // this function deletes the last element of the list
    // in order to perform this, list must not be empty
    // if list is empty, then exit
    if(l->length <= 0)
    {
        printf("List Error: Calling deleteBack() on an empty list\n");
        exit(EXIT_FAILURE);
    }

    // if list is not empty
    // storing back node, which needs to be deleted
    Nodeptr n = l->tail->prev;
    // setting some pointers
    l->tail->prev = n->prev;
    n->prev->next = n->next;
    // freeing n node
    free(n);
    //decreasing length by 1
    l->length--;
}

// isEmpty
// Returns true of list is empty otherwise returns false
bool isEmpty(Listptr l)
{
    if( l==NULL ){
        printf("Queue Error: calling isEmpty() on NULL Queue reference\n");
        exit(EXIT_FAILURE);
    }
    return(l->length==0);
}


// append(List L, int x)
// Inserts a new element into L
// if L is non-empty, insertions takes place after back element
void append(Listptr L, int x)
{
    // append is basically insertAtTail() call
    if(L->length == 0)
    {
        // if there is 0 element in the list
        // then it doesn't matter where we insert, it will be same in all cases
        // creating a new node
        Nodeptr n = newNode(x);
        //setting pointers
        L->head->next = n;
        L->tail->prev = n;
        //setting new node pointers
        n->next = L->tail;
        n->prev = L->head;
        // incrementing length
        L->length++;
    }
    else
    {
        // creating a new node
        Nodeptr n = newNode(x);
        //setting pointers
        L->tail->prev->next = n;
        n->prev = L->tail->prev;
        n->next = L->tail;
        L->tail->prev = n;
        // incrementing length
        L->length++;
    }
}


// print
void print(Listptr l)
{
    // first check that list is not empty
    if(l->length<=0)
    {
        printf("List Error: Calling print() on an empty or null list\n");
        exit(EXIT_FAILURE);
    }
    // set cursor to object next to head
    l->cursor = l->head->next;
    while(l->cursor != l->tail)
    {
        printf("%d, ", l->cursor->data);
        l->cursor = l->cursor->next;
    }
    printf("\n");
    // also setting index, as we used cursor to iterate
    l->index = -1;
}

// delete
// Deletes the cursor element, making cursor undefined
// Pre: length() > 0 AND index >= 0
void delete(Listptr l)
{
    // this function deleted the cursor element
    // if list is empty it throws error
    // otherwise it works fine

    // first check that list is not empty
    if(l->length<=0)
    {
        // if list is empty
        printf("List Error: List Error: Calling delete() on an empty or null list\n");
        exit(EXIT_FAILURE);
    }

    // also checks if the cursor is not already NULL
    if(l->cursor == NULL)
    {
        printf("List Error: Calling delete() on undefined cursor\n");
        exit(EXIT_FAILURE);
    }

    // if list is not empty
    // setting pointers
    l->cursor->prev->next = l->cursor->next;
    l->cursor->next->prev = l->cursor->prev;
    // freeing cursor
    free(l->cursor);
    // making it undefined(NULL)
    l->cursor = NULL;
    l->length--;
}

// deleteFree
// this is not used outside. it is just used by the freelist function to carefully delete and free all nodes without causing memory leaks
void deleteFree(Listptr l)
{
    // first check that list is not empty
    if(l->length<=0)
    {
        printf("List Error: List Error: Calling delete() on an empty or null list\n");
        exit(EXIT_FAILURE);
    }
    // setting cursor to object next to head
    l->cursor = l->head->next;
    while(l->cursor != l->tail)
    {
        Nodeptr n = l->cursor;
        l->cursor = l->cursor->next;
        free(n);
        l->length--;
    }
}

// printList
// Prints to the file pointed to by out, a string
// representation of L consisting of a space
// seperated sequence of integers with front on Left
void printList(FILE *out, Listptr l)
{
    // this function writes string representation of 'l' to the file
    // assuming that the file is already opened by the called function
    // just write content to the file and all DONE
    // setting cursor
    l->cursor = l->head->next;
    while(l->cursor != l->tail)
    {
        fprintf(out, "%d ", l->cursor->data);
        l->cursor = l->cursor->next;
    }
    // this function doesn't close the file, it will be closed by the caller function
}

// copyList
// Returns a new list representing the same integer sequence as L
// The cursor in the new list is undefined, regardless of the state of the cursor in L
// The state of L is unchanged
Listptr copyList(Listptr l)
{
    // this function copy 'l' into a new list and returns it
    // creating a new list
    Listptr temp = newList();
    // iterating through 'l' and appending cursor->data into new list
    l->cursor = l->head->next;
    while(l->cursor != l->tail)
    {
        append(temp, l->cursor->data);
        l->cursor = l->cursor->next;
    }

    // return point
    return temp;
}

// deleteFrontAndReturn
int deleteFrontAndReturn(Listptr l)
{
    if(l != NULL)
    {
        // this function deletes the first element of the list
        // in order to do this, list must not be empty
        // if empty, exit
        if(l->length <= 0)
        {
            printf("List Error: Calling deleteFront() on an empty list\n");
            exit(EXIT_FAILURE);
        }

        // if list is not empty
        // storing front node, which needs to be deleted
        Nodeptr n = l->head->next;
        int temp = n->data;
        // setting pointers
        l->head->next = n->next;
        n->next->prev = n->prev;
        // freeing n node
        free(n);
        //decreasing length by 1
        l->length--;
        return temp;
    }
}

// getAtIndex
int getAtIndex(Listptr l, int v)
{
    int counter = 1;
    l->cursor = l->head->next;
    while(l->cursor != l->tail)
    {
        if(counter == v)
            return l->cursor->data;
        l->cursor = l->cursor->next;
        counter++;
    }
    return -1;
}

// isNull
bool isNull(Listptr l)
{
    /*if(l != NULL)
        return (l->length == 0);
    else
        return true;*/
    return (l->length == 0);
}