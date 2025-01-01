#include "boolean.h"
#include "listlinier.h"
#include <stdio.h>

int main(){
    List l; int n, q, temp;
    CreateEmpty(&l);
    scanf("%d", &n);
    scanf("%d", &q);
    for (int i = 1; i<=n; i++) InsVLast(&l, i);
    while(q--){
        scanf("%d", &temp);
        if(Search(l, temp) != Nil){
            DelP(&l, temp);
            printf("hit ");
        }
        else{
            DelVLast(&l, &n);
            printf("miss ");
        }
        InsVFirst(&l, temp);
        PrintInfo(l);
        printf("\n");
    }
}