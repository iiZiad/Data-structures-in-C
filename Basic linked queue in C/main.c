#include <stdio.h>
#include "linkedqueue.h"

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
    for(int i = 70 ; i < 80 ; i++){
      enqueue(&n, i);
    }
    printLS(n);
    printf("retrieved is %c \n", dequeue(&n));
    printLS(n);
    printf("retrieved is %c \n", dequeue(&n));
    printLS(n);
    return 0;
}