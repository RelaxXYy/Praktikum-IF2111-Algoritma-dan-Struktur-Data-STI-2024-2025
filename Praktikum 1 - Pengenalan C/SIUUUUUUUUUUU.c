#include <stdio.h>

int main() {
    int N;
    int i = 1;
    scanf("%d", &N);
    for (i;i<=N;i++){
        if ((i%7==0) && ((i%2==0) || (i%5==0))){
            printf("RonaldoMessi\n");
        } else if (i%7==0){
            printf("Ronaldo\n");
        } else if ((i%2==0) || (i%5==0)){
            printf("Messi\n");
        } else {
            printf("%d\n", i);
        }
    }
}