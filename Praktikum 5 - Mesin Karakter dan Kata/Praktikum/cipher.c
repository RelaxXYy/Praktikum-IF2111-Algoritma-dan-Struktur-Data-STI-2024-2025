#include "boolean.h"
#include <stdio.h>
#include "mesinkata.h"
#include "mesinkarakterv2.h"

int main(){
    int shift=0, n=0;
    char huruf[100];
    START();
    IgnoreBlanks();
    while(currentChar!=BLANK){
        huruf[n]=currentChar;
        shift++;
        n++;
        ADV();
    }
    for(int i = 0; i<n; i++){
        printf("%c", ((huruf[i]+shift-65)%26)+65);
    }
    while(currentChar!=MARK){
        if (currentChar==BLANK) printf(" ");
        else printf("%c", ((currentChar+shift-65)%26)+65);
        ADV();
    }
    printf(".\n");
}
