#include <stdio.h>
#include "linkedstack.h"

void printLS(Head l){
    int i = 0;
    Node *temp = l.head;
    while(temp != NULL){
        printf("-----     ");
        temp = temp->next;
    }
    temp = l.head;
    printf("\n");
    while(temp != NULL){
        if(temp->next != NULL){
            printf("| %c | --> ",temp->item);
        }else{
            printf("| %c |\n",temp->item);
        }
        temp = temp->next;
    }
    temp = l.head;
    while(temp != NULL){
        printf("-----     ");
        temp = temp->next;
    }
    printf("\n");
}
int main(){
    Head n;
    create(&n);
    push(&n, 'H');
    push(&n, 'j');
    push(&n, 'K');
    printLS(n);
    printf("poped is %c \n", pop(&n));
    printLS(n);
    printf("poped is %c \n", pop(&n));
    printLS(n);
    return 0;
}