#include <stdlib.h>
#include <stdio.h>
#include "boolean.h"
#include "stacklinked.h"

int main(){
    int n, from, to, temp; Stack a, b, c;
    CreateStack(&a);
    CreateStack(&b);
    CreateStack(&c);
    push(&a, 5);
    push(&a, 4);
    push(&a, 3);
    push(&a, 2);
    push(&a, 1);

    scanf("%d", &n);

    while(n--){
        scanf("%d", &from);
        scanf("%d", &to);
        if(from == 1){
            if (isEmpty(a)) printf("Menara kosong\n");
            else if(to == 2){
                pop(&a, &temp);
                if(isEmpty(b) || (TOP(b) > temp)) push(&b, temp);
                else{
                    printf("Piringan tidak dapat dipindah\n");
                    push(&a, temp);
                }
            }
            else{ //3
                pop(&a, &temp);
                if(isEmpty(c) || (TOP(c) > temp)) push(&c, temp);
                else{
                    printf("Piringan tidak dapat dipindah\n");
                    push(&a, temp);
                }
            }
        }else if(from == 2){
            if (isEmpty(b)) printf("Menara kosong\n");
            else if(to == 1){
                pop(&b, &temp);
                if(isEmpty(a) || (TOP(a) > temp)) push(&a, temp);
                else{
                    printf("Piringan tidak dapat dipindah\n");
                    push(&b, temp);
                }
            }
            else{ //3
                pop(&b, &temp);
                if(isEmpty(c) || (TOP(c) > temp)) push(&c, temp);
                else{
                    printf("Piringan tidak dapat dipindah\n");
                    push(&b, temp);
                }

            }
        }else{
            if (isEmpty(c)) printf("Menara kosong\n");
            else if(to == 1){
                pop(&c, &temp);
                if(isEmpty(a) || (TOP(a) > temp)) push(&a, temp);
                else{
                    printf("Piringan tidak dapat dipindah\n");
                    push(&c, temp);
                }
            }
            else{ //2
                pop(&c, &temp);
                if(isEmpty(b) || (TOP(b) > temp)) push(&b, temp);
                else{
                    printf("Piringan tidak dapat dipindah\n");
                    push(&c, temp);
                }
            }
        }
    }
    printf("Menara 1: ");
    DisplayStack(a);
    printf("\n");
    printf("Menara 2: ");
    DisplayStack(b);
    printf("\n");
    printf("Menara 3: ");
    DisplayStack(c);
    printf("\n");
}