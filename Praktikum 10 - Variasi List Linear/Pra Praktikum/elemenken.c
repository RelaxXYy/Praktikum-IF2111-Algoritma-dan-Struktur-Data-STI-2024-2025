#include <stdio.h>
#include "listsirkuler.h"

int ElemenKeN(List L, int r) {
    address P = First(L);
    while(r > 0) {
        if(P == Nil) P = First(L);
        P = Next(P);
        r--;
    }
    return Info(P);
}

int main () {
    List L; CreateEmpty(&L);
    int r;
    scanf("%d", &r);
    while(r != 0){
        InsVLast(&L, r);
        scanf("%d", &r);
    }
    scanf("%d", &r);
    if(IsEmpty(L)) printf("List Kosong\n");
    else printf("%d\n", ElemenKeN(L, r));
}