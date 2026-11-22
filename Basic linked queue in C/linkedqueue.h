#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

typedef int dataType;
typedef struct node {
    dataType item;
    struct node *next;
}Node;
typedef struct{
    Node *head;
    int size;
}Head;

void create(Head *);
int isEmpty(Head);
int isFull(Head);
void enqueue(Head *, dataType);
dataType dequeue(Head *);


#endif