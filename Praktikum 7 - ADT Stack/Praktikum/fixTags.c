#include "stack.h"
#include <stdio.h>

int main(){
    int n, count = 0; Stack s; char c;
    CreateEmpty(&s);
    scanf("%d", &n);
    while(n--){
        scanf(" %c", &c);
        if (c=='>' && !IsEmpty(s) && InfoTop(s)=='<'){
            Pop(&s, &c);
            count++;
        }
        else{
            Push(&s, c);
        }
    }
    while(count--) printf("<>");
    printf("\n");
}