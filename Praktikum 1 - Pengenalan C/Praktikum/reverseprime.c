#include <stdio.h>

int main(){
    int num;
    int ans=0;
    int mul=0;
    scanf("%d", &num);
    while (num/=10!=0){
        if (num%10==7){
            ans+=7;
            mul++;
        } else if (num%10==5){
            ans+=5;
            mul++;
        } else if (num%10==3){
            ans+=3;
            mul++;
        } else if (num%10==2){
            ans+=2;
            mul++;
        }
        if (mul){
            ans*=10;
            mul=0;
        }
        num/=10;
    }
    ans/=10;
    printf("%d\n", ans);
}