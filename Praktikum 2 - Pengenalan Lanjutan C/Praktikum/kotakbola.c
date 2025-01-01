#include <stdio.h>

int main(){
    int kH = 0 , kM = 0, kB = 0, H =0, M=0, B=0, valid=0;
    char warna;
    scanf("%d %d %d\n", &kH, &kM, &kB);
    while (!valid){
        int temp=0;
        scanf("%c", &warna);
        if (warna=='E') {
            break;
        }
        else{
            scanf("%d\n", &temp);
        }
        if (warna=='H'){
            H+=temp;
            kH-=temp;
        }
        else if (warna=='M'){
            M+=temp;
            kM-=temp;
        }
        else if (warna=='B'){
            B+=temp;
            kB-=temp;
        }
    }
    printf("%d %d %d\n", H, M, B);
    if ((kH>=0) && (kM>=0) && (kB>=0)){
        if  ((H>0) || (M>0) || (B>0)){
            valid=1;
        }
    }
    printf((valid) ? "Ya\n" : "Tidak\n");
}