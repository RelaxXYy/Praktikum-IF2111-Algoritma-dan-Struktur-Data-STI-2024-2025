#include <stdio.h>
#include <stdlib.h>
#include "arraydin.h"

int main(){
    int n=0;
    scanf("%d", &n);
    ArrayDin array;
    array.A = (ElType *) malloc(n * sizeof(ElType));
    array.Capacity = n;
    array.Neff = 0;
    for(int i=0;i<n;i++){
        int A=0;
        scanf("%d", &A);
        if (A==2) InsertLast(&array, A);
        else for(int j=2;j<=A;j++){
            while (A%j==0) {
                InsertLast(&array, j);
                A/=j;
            }
        };
    }

    for(int i=0;i<array.Neff;i++){
        if (i==0) printf("%d", array.A[i]);
        else printf(" %d", array.A[i]);
    }
    printf("\n");
}