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

    if(pos <= l->size){
        if(pos == 0){ // 11 1 2 3 4
            new->next = l->head;
            l->head = new;
            
            for(int i = 0 ; i < l->size-1 ; i++) temp = temp->next;
            if(l->size > 0 ){
                temp->next = l->head; // link last to the first
                l->head->prev = temp->next;
            }else{
                l->head->next = l->head;
                l->head->prev = l->head;
            }        
        }else{ //1 2 3 4 x
            for( int i = 0 ; i < pos - 1 ; i++ ) temp = temp->next;
            temp->next = new;
            new->prev = temp;
            temp->next = new;
            new->next = l->head;
            l->head->prev = new;
        }
        }
    l->size++;
}
dataType retrieve(Head *l, int pos){
    Node *buffer = l->head;
    Node *temp;
    Node *prevNode;
    dataType returned;
    if(pos == 0){
        if(isEmpty(*l) == 0){
            temp = buffer;
            prevNode = l->head->prev;
            l->head = l->head->next;
            l->head->prev = prevNode;
        }else{ printf("Empty linked list !\n"); return 0;}
    }else{
        for(int i = 0 ; i < pos - 1 ; i++) buffer = buffer->next;
        temp = buffer->next;
        buffer->next = buffer->next->next;
        buffer->next->prev = buffer; 
    }
    returned = temp->item;
    free(temp);
    l->size--;
    return returned;
}