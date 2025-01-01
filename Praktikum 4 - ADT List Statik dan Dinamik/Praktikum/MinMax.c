#include "MinMax.h"
#include "list.h"

List MinMax(List L){
    int MinIdx=0, MaxIdx=0;
    for(int i=FirstIdx(L);i<=LastIdx(L);i++){
        if(Get(L,i)>Get(L,MaxIdx)) MaxIdx=i;
        if(Get(L,i)<Get(L,MinIdx)) MinIdx=i;
    }
    int Min=Get(L,MinIdx), Max=Get(L,MaxIdx);
    DeleteAt(&L, MinIdx);
    if (MinIdx<MaxIdx) MaxIdx--;
    DeleteAt(&L, MaxIdx);
    InsertLast(&L, Min);
    InsertLast(&L, Max);
    return L;
}
