#include <stdio.h>
#include "stack.h"
#include "boolean.h"

void FindMax(Stack *S, int *floor, infotype *maxMoney) {
    *maxMoney = InfoTop(*S);
    *floor = Top(*S) + 1;
    for (int i = 0; i <= Top(*S); i++) {
        if (S->T[i] > *maxMoney) {
            *maxMoney = S->T[i];
            *floor = i + 1;
        }
    }
}

int main() {
    int Q;
    scanf("%d", &Q);

    Stack S;
    CreateEmpty(&S);

    for (int i = 0; i < Q; i++) {
        int command;
        scanf("%d", &command);

        if (command == 1) {
            infotype X;
            scanf("%d", &X);
            Push(&S, X);
        } else if (command == 2) {
            infotype X;
            Pop(&S, &X);
        } else if (command == 3) {
            int floor;
            infotype maxMoney;
            FindMax(&S, &floor, &maxMoney);
            printf("%d %d\n", floor, maxMoney);
        }
    }

    return 0;
}