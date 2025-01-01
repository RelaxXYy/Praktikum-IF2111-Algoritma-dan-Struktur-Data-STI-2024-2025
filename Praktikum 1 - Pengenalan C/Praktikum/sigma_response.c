#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char *nama;
    nama = (char *) malloc (20 * sizeof (char));
    scanf("%s", nama);
    if ((nama[0]=='A') || (nama[0]=='I')||(nama[0]=='U')||(nama[0]=='E')||(nama[0]=='O')){
        printf("%s menjawab: \"Bintang skibidi, bintang yang paling skibidi tertinggi itu kecuali skibidi 5 hanyalah mewing besar\"\n", nama);
    } else if ((nama[0]=='a') || (nama[0]=='i')||(nama[0]=='u')||(nama[0]=='e')||(nama[0]=='o')){
        printf("%s menjawab: \"Bintang skibidi, bintang yang paling skibidi tertinggi itu kecuali skibidi 5 hanyalah mewing besar\"\n", nama);
    } else {
        printf("%s menjawab: \"Bintang skibidi. Matahari terbenam di balik skibidi, hanya skibidi 7 yang tahu apa artinya\"\n", nama);
    }
}