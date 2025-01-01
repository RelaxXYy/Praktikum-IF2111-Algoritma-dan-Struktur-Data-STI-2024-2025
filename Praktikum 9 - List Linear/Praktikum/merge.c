#include "merge.h"
#include "boolean.h"
#include "listlinier.h"

List mergeSortedList(List L1, List L2){
    List result; infotype temp;
    CreateEmpty(&result);
    Konkat1(&L1, &L2, &result);
    for(address i = First(result); i != Nil; i = Next(i)){
        for(address j = i; j != Nil; j = Next(j)){
            if (Info(i) > Info(j)){
                temp = Info(j);
                Info(j) = Info(i);
                Info(i) = temp;
            }
        }
    }
    return result;
}
/*
    Membuat suatu fungsi yang mengambil 2 buah list yang berurutan dan menyatukannya
    menjadi satu buah list yang berurutan. 

    Asumsi List Input : 
    1. List input adalah List linier yang berisi integer
    2. List input mungkin kosong
    3. List input mungkin memiliki lebih dari satu elemen yang sama, misalnya [1,1]
    4. List input pasti berurutan dari kecil ke besar

    CONTOH 1
    input : 
        L1 = [1,1,2,3]
        L2 = [1,2]
    output : [1,1,1,2,2,3]

    CONTOH 2 
    input : 
        L1 = [1,3]
        l2 = [2,4]
    output : [1,2,3,4]

 */