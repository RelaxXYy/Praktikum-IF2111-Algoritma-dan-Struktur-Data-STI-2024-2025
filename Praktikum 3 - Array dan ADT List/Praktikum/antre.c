#include <stdio.h>

int main(){
    int n=0,temp;
    int data[100];
    scanf("%d", &n);
    for(int i = 0; i<n;i++){
        scanf("%d", &temp);
        data[i]=temp;
    }
    for(int i=0;i<n;i++){
        if (i!=0){
            if ((data[i])!=(data[i-1])){
                printf(" %d", data[i]);
                }
            
        }else {
            printf("%d", data[i]);
        }
    }
    printf("\n");
}

