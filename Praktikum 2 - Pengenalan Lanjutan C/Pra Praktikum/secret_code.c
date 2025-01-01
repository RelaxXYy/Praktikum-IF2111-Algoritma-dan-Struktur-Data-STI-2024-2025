#include <stdio.h>
#include "secret_code.h"

int count_length(char str[]){
    int i = 0;
    while (str[i] != '#'){
        i++;
    }
    return (i+1);
}

void print_decrypted(char str[]){
    int i = 0;
    while (str[i] != '#'){
        if (((str[i])>='a' && (str[i])<='z') || ((str[i])>='A' && (str[i])<='Z')){
            printf("%c", str[i]);
        }  
        i++;
    }  
    printf("\n"); 
}

