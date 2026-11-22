#include <stdio.h>
#include <stdlib.h>
#include "linkedqueue.h"

void create(Head *l){
    l->head = NULL;
    l->size = 0;
}
int isEmpty(Head l){
    return l.head == NULL;
}
int isFull(Head l){
    return 0;
}
void enqueue(Head *l, dataType item){
    Node *new = (Node *) malloc( sizeof(Node) );
    new->item = item;
    new->next = l->head;
    l->head = new;
    l->size++;
}
dataType dequeue(Head *l){
    Node *temp = l->head;
    Node *buffer;
    dataType returned;
    if(isEmpty(*l) == 0){ // 0 1 |2 3     i = 2   i < 3
        for( int i = 0 ; i < l->size -2  ; i++ ) temp = temp->next;
        buffer = temp->next;
    }else{ printf("Empty Stack !\n"); }
    returned = buffer->item;
    temp->next = NULL;
    free(buffer);
    l->size--;
    return returned;
}