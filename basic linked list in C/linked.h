#ifndef LINKED_H
#define LINKED_H

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
void insert(Head *, dataType, int);
dataType retrieve(Head *, int);


#endif