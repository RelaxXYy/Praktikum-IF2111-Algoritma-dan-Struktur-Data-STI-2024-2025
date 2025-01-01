#include "listlinier.h"
#include "boolean.h"
#include <stdio.h>

int main(){
    List L;
    int n = 0;
    CreateEmpty(&L);
    while (n>=0 && n<=100){
        scanf("%d", &n);
        if (n>=0 && n<=100) InsVLast(&L, n);
    }
    if(!IsEmpty(L)){
        printf("%d\n", NbElmt(L));
        printf("%d\n", Max(L));
        printf("%d\n", Min(L));
        printf("%.2f\n", Average(L));
        PrintInfo(L);
        printf("\n");
        InversList(&L);
        PrintInfo(L);
        printf("\n");
    }
    else printf("Daftar nilai kosong\n");
}