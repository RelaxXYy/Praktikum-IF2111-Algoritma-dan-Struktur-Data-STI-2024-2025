#include <stdio.h>

int main(){
    int n=0, odd=0, arr[50];
    unsigned long long int count=0;
    scanf("%d", &odd);
    scanf("%d", &n);
    arr[0]=0;
    arr[1]=1;
    if (odd && n!=0) count++;
    for(int i = 2; i<=n;i++){
        arr[i]=arr[i-1]+arr[i-2];
        if ((odd) && (arr[i]%2==1)) count+=arr[i]; 
        if ((!odd) && (arr[i]%2==0)) count+=arr[i]; 
    }
    printf("%llu\n", count);
    printf("[%d", 0);
    for(int i = 1;i<=n;i++){
        printf(",%d", arr[i]);
    }
    printf("]\n");
}