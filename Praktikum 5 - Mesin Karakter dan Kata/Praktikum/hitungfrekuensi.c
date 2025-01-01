#include "hitungfrekuensi.h"
#include "boolean.h"
#include "mesinkarakter.h"

int hitungfrekuensi(){
    int c=0;
    START();
    while(!IsEOP() && GetCC()!=MARK){
        if (GetCC() == 't' | GetCC() == 'T'){
            ADV();
            if (GetCC() == 'i' | GetCC() == 'I'){
                ADV();
                if (GetCC() == 'g' | GetCC() == 'G'){
                    ADV();
                    if (GetCC() == 'a' | GetCC() == 'A'){
                        c++;
                    }
                }
            }
        }
        ADV();
    }
    return c;
}