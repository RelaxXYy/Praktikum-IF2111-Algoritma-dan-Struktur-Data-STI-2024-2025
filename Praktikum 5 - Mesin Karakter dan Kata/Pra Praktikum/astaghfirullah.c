#include <stdio.h>
#include "mesinkarakter.h"

/*char currentChar;
boolean EOP;

static FILE *pita;
static int retval;*/

int main(){
    int count=0;
    char exc;
    scanf("%c", &exc);

    START();
    while (!IsEOP()){
        if (GetCC()=='a' || GetCC()=='i' || GetCC() =='u' || GetCC()=='e' || GetCC()=='o'){
            if (GetCC()==exc){
                ADV();
            }
            else{ 
                printf("%c", GetCC());
                count+=1;
            }
        }
        ADV();
    }

    if (count==0){
        printf("0\n");
    }
    else{
        printf(" %d\n", count);
    }
    return 0;
}