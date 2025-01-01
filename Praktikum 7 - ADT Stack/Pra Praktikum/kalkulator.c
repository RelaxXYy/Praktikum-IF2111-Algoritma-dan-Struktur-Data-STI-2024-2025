#include <stdio.h>
#include "stack.h"
#include "stackchar.h"


int main(){
    char operation = ' ';
    int temp;
    long long int value = 0;
    Stack valueStack;
    StackChar operationStack;
    CreateEmpty(&valueStack);
    CreateEmptyChar(&operationStack);
    while(operation != '='){
        scanf(" %c", &operation);
        if (operation == 'u'){
            Pop(&valueStack, &temp);
            PopChar(&operationStack, &operation);
            if (operation == '+'){
                value -= temp;
            }
            else if (operation == '-'){
                value += temp;
            }
        }
        else{
            PushChar(&operationStack, operation);
            scanf("%d", &temp);
            if (operation == '+'){
                Push(&valueStack, temp);
                value += temp;
            }
            else if (operation == '-'){
                Push(&valueStack, temp);
                value -= temp;
            }
        }
    }
    printf("%lld\n", value);
}