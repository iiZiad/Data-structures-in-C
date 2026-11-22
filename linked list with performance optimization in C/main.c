#include <stdio.h>
#include "linked.h"
#include <time.h>

void printLS(Head l){
    int i = 0;
    Node *temp = l.head;
    while(temp != NULL){
        printf("------     ");
        temp = temp->next;
    }
    temp = l.head;
    printf("\n");
    while(temp != NULL){
        if(temp->next != NULL){
            printf("| %d | --> ",temp->item);
        }else{
            printf("| %d |\n",temp->item);
        }
        temp = temp->next;
    }
    temp = l.head;
    while(temp != NULL){
        printf("------     ");
        temp = temp->next;
    }
    printf("\n");
}
int main(){
    Head n;
    create(&n);
    for(int i = 70 ; i < 76 ; i++){
        int i1  = clock();
        insert(&n, i, i - 70);
    }
    printLS(n);
    isPresent(&n, 74);
    printLS(n);
    return 0;
}