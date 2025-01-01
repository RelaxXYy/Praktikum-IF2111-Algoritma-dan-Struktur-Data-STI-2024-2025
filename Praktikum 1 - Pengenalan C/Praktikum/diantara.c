#include <stdio.h>

int main(){
    int L,R,D;
    int count = 0;
    scanf("%d", &L);
    scanf("%d", &R);
    scanf("%d", &D);
    for (L;L<=R;L++){
        if (L%D==0){
            count++;
        }
    }
    printf("%d\n", count);
}
