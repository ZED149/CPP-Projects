//
// Created by salman on 4/8/23.
// This file contains the List class
//


// List class is basically a doubly linked list
// It consists of a Node structure whose data variable is int


// class starting from here

#ifndef PA_2_h
#define PA_2_h
#include <stdbool.h>


// Constructor and Destructor for Doubly Linked List a.k.a List
typedef struct List* Listptr;
typedef struct List List;

// Constructor
Listptr newList();

// Destructor
void freeList(Listptr *pl);


// Access Functions
// index
int Index(Listptr l);

// length
int length(Listptr l);

// front
int front(Listptr l);

// back
int back(Listptr l);

// get
int get(Listptr l);

// equals
bool equals(Listptr a, Listptr b);

// Manipulation Procedures
// clear
void clear(Listptr l);

// set
void set(Listptr l, int x);

// moveFront
void moveFront(Listptr l);

// moveBack
void moveBack(Listptr l);

// movePrev
void movePrev(Listptr l);

// moveNext
void moveNext(Listptr l);

// prepend
void prepend(Listptr l, int x);

// insertBefore
void insertBefore(Listptr l, int x);

// insertAfter
void insertAfter(Listptr l, int x);

// deleteFront
void deleteFront(Listptr l);

// deleteBack
void deleteBack(Listptr l);

// isEmpty
bool isEmpty(Listptr l);

// append
void append(Listptr L, int x);

// delete
void delete(Listptr l);

// deleteFree
void deleteFree(Listptr l);

//print
void print(Listptr l);

// printList
void printList(FILE *out, Listptr l);

// deleteFrontAndReturn
int deleteFrontAndReturn(Listptr l);

// getAtIndex
int getAtIndex(Listptr l, int index);

// isNull
bool isNull(Listptr l);

// copyList
Listptr copyList(Listptr l);

#endif
