#include <stdio.h>
#include <stdlib.h>
#include "linked.h"

void create(Head *l){
    l->head = NULL;
}
int isEmpty(Head l){
    return l.head == NULL;
}
int isFull(Head l){
    return 0;
}
void insert(Head *l, dataType item, int pos){
    Node *new = (Node *) malloc( sizeof(Node) );
    Node *temp = l->head;
    new->item = item;
    if(pos == 0){
        new->next = l->head;
        l->head = new;
    }else{
        for( int i = 0 ; i < pos - 1 ; i++ ) temp = temp->next;
        new->next = temp->next;
        temp->next = new;
    }

}
dataType retrieve(Head *l, int pos){
    Node *buffer = l->head;
    Node *temp;
    dataType returned;
    if(pos == 0){
        if(isEmpty(*l) == 0){
            temp = buffer;
            l->head = l->head->next;
        }else{ printf("Empty linked list !\n"); }
    }else{
        for(int i = 0 ; i < pos - 1 ; i++) buffer = buffer->next;
        temp = buffer->next;
        buffer->next = buffer->next->next;
    }
    returned = temp->item;
    free(temp);
    return returned;
}