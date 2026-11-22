#include <stdio.h>
#include <stdlib.h>
#include "linked.h"
#include <time.h>
#include <math.h>

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
int searchItem(Head l, dataType item, int *i , clock_t *atime){
    Node *temp = l.head;
    *atime = clock();
    while( temp != NULL ){
        for(int j = 0 ; j < 1000 ; j++){
            float a = log(j*j*j*j);
        } // for taking some time to test
        if(temp->item == item){
            *atime = clock() - *atime;
            return 1;
        }else{
            temp = temp->next;
        }
        (*i)++;
    }
    return 0;
}
void isPresent(Head *l, dataType item){
    clock_t timespent[2];
    int pos = 0;
    if(searchItem(*l,item, &pos, &timespent[0]) == 1){
        insert(l, retrieve(l, pos), 0);
        pos = 0;
        searchItem(*l,item, &pos, &timespent[1]);
        printf("Item is exist in pos %d and the list is optimized\n", pos);
        float n1 = (float) timespent[0] / CLOCKS_PER_SEC;
        float n2 = (float) timespent[1] / CLOCKS_PER_SEC;
        printf("Before : %f sec\nAfter : %f sec\nimprovement : %.2f %%\n", n1, n2, (n1/n2) * 100);
    }else{
        printf("Item is not exist\n");
    }

}