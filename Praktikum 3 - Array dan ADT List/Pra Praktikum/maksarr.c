#include <stdio.h>

int main(){
    int n, data[100000], max=0, temp, c;
    scanf("%d", &n);

    for (int i = 0;i<n;i++){
        scanf("%d", &temp);
        if (temp>max){
            max=temp;
            for (int j = 0; j <= c; j++){
                data[j] = 0;
            }
            c=0;    
        }
        if (temp==max){
            data[c]=i;
            c++;
        }
    }
    printf("%d %d\n", max, c);
    for (int j = 0; j < c; j++){
        printf("%d ", data[j]);
    }
    printf("\n");
}