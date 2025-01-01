#include <stdio.h>

int main() {
    int num;
    int len = 0;
    int ans = 0;
    scanf("%d", &num);
    int copy_num = num;
    while (num!=0){
        num/=10;
        len++;
    }
    for (len;len>0;len--){
        if(len%2==0){
            ans+=copy_num%10;
        }
        copy_num/=10;
    }
    printf("%d\n", ans);
}