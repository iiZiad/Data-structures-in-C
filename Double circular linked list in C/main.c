#include <stdio.h>
#include "linked.h"

void printLS(Head l){
    int i = 0;
    Node *temp = l.head;
    while(i < l.size  ){
        if(i < l.size - 1){
            printf("| %c | --> ",temp->item);
        }else{
            printf("| %c |\n",temp->item);
        }
        temp = temp->next;
        i++;
    }
}
int main(){
    Head n;
    create(&n);
    for(int i = 70 ; i < 80 ; i++){
        insert(&n, i, i - 70);
    }
    dataType gar = retrieve(&n, 3);
    printLS(n);
    printf("\n%c\n", n.head->next->next->next->prev->item);
    return 0;
}