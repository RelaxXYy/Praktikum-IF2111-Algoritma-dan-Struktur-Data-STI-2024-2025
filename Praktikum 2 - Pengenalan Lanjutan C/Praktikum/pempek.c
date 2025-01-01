#include <stdio.h>

int main(){
    unsigned long long int q, n, d;
    scanf("%llu", &q);
    for (q;q>0;q--){
        scanf("%llu %llu", &n, &d);
        printf("%d\n", ((n/d)+1)%2);   
    }
}