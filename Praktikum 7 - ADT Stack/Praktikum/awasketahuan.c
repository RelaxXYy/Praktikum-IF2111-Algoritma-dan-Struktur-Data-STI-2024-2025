#include "awasketahuan.h"
#include "stack.h"

Stack awasKetahuan(Stack stack){
    Stack temp; int value;
    CreateEmpty(&temp);
    while(!IsEmpty(stack)){
        Pop(&stack, &value);
        if((value%2)==0) value/=2;
        Push(&temp, value);
    }
    while(!IsEmpty(temp)){
        Pop(&temp, &value);
        Push(&stack, value);
    }
    return stack;
}
/* Mengembalikan sebuah stack berisi integer yang elemen bernilai genapnya sudah dibagi dua */
/* Input berupa stack berisi integer. */
/*
    Contoh input:
        queue : [8, 7, 6, 5, 4, 23 // 8 adalah top
    Contoh output: [4, 7, 3, 5, 2, 3]

    Contoh input:
        queue : [12, 7, 3, 3, 6]
    Contoh output: [6, 7, 3, 3, 3]

*/