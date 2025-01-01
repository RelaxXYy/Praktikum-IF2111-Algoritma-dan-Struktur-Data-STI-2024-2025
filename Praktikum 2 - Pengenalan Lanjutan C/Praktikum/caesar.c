#include <stdio.h>


int main(){
    int i=0, c=0;
    char str[20];
    scanf("%s", str);
    while (str[c]!='.'){
        c++;
    }
    while (str[i]!='.'){
        str[i]+=c;
        while ((str[i])>90){
            str[i]-=26;
        }
        printf("%c", (str[i]));
        i++;
    }
    printf("\n");
}