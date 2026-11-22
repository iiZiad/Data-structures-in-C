#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

typedef int dataType;
typedef struct node {
    dataType item;
    struct node *next;
}Node;
typedef struct{
    Node *head;
}Head;

void create(Head *);
int isEmpty(Head);
int isFull(Head);
void push(Head *, dataType);
dataType pop(Head *);


#endif