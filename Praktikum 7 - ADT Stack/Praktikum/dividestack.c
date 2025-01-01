#include "dividestack.h"
#include "stack.h"

void divideStack(Stack *s, Stack *oddS, Stack *evenS){
    Stack temp; int value;
    CreateEmpty(&temp);
    while(!IsEmpty(*s)){
        Pop(s, &value);
        Push(&temp, value);
    }
    while(!IsEmpty(temp)){
        Pop(&temp, &value);
        if(value%2==0) Push(evenS, value);
        else Push(oddS, value);
    }
}
/*
Memisahkan nilai genap dan nilai ganjil dari Stack s.

Awal:
s: 1,2,3,4
evenS:
oddS:

Akhir:
s: 
evenS 2,4
oddS: 1,3

Perhatikan order di dalam stacknya

*/