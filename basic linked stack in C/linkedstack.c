#include <stdio.h>
#include <stdlib.h>
#include "linkedstack.h"

void create(Head *l){
    l->head = NULL;
}
int isEmpty(Head l){
    return l.head == NULL;
}
int isFull(Head l){
    return 0;
}
void push(Head *l, dataType item){
    Node *new = (Node *) malloc( sizeof(Node) );
    new->item = item;
    new->next = l->head;
    l->head = new;
}
dataType pop(Head *l){
    Node *temp = l->head;
    Node *buffer;
    dataType returned;
    if(isEmpty(*l) == 0){ // 0 1 |2 3     i = 2   i < 3
        buffer = temp;
        l->head = l->head->next;
    }else{ printf("Empty Stack !\n"); }
    returned = buffer->item;
    free(buffer);
    return returned;
}