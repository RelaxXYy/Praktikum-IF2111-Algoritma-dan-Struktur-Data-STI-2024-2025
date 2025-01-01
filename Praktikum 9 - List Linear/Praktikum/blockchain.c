#include "blockchain.h"
#include "listlinierv2.h"
#include "boolean.h"
#include <stdio.h>

/* Menghitung hash value untuk blok baru */
/* I.S. Parameter block terdefinisi */
/* F.S. Mengembalikan nilai hash yang merupakan jumlah dari prevHash, data, dan timestamp */
infotype computeHash(BlockData block){
        return block.prevHash + block.data + block.timestamp;
}

/* I.S. blockchain kosong */
/* F.S. blockchain terisi dengan genesis block yang memiliki:
        - prevHash = 0
        - data = jumlah ASCII dari string "Satomoto"
        - timestamp = 0 */
void initBlock(List *blockchain){
        infotype data = 'S' + 'a' + 't' + 'o' + 'm' + 'o' + 't' + 'o';
        InsVLast(blockchain, 0, data, 0);
}

/* Menambahkan blok baru ke blockchain */
/* I.S. blockchain terdefinisi dan tidak kosong (minimal berisi genesis block) */
/* F.S. Sebuah blok baru ditambahkan ke akhir blockchain dengan:
        - prevHash = hash dari blok sebelumnya
        - data = value yang diberikan
        - timestamp = waktu yang diberikan */
void addBlock(List *blockchain, infotype value, infotype timestamp){
        address P = First(*blockchain); BlockData temp = (*P).info;
        while(P != Nil){
                temp = Info(P);
                P = Next(P);
        }
        InsVLast(blockchain, computeHash(temp), value, timestamp);
}

/* Memvalidasi integritas blockchain */
/* I.S. blockchain terdefinisi */
/* F.S. Mengembalikan true jika:
        - blockchain kosong atau hanya berisi 1 blok (genesis), atau
        - Semua blok memiliki hash yang valid dan terhubung dengan benar
        Mengembalikan false jika ada blok yang tidak valid atau tidak terhubung dengan benar */
boolean validateChain(List blockchain){
        if(IsEmpty(blockchain)) return true;
        address P = First(blockchain); BlockData temp = Info(P);
        while(Next(P) != Nil){
                P = Next(P);
                if (computeHash(temp) != PrevHash(P)) return false;
                temp = Info(P);
        }
        return true;

        
}

/* Menampilkan seluruh blok dalam blockchain */
/* I.S. blockchain terdefinisi */
/* F.S. Seluruh blok dalam blockchain ditampilkan ke layar dalam format:
        [
          Block 1: {            // indentasi 2 spasi
            prevHash: <nilai>,  // indentasi 4 spasi
            data: <nilai>,      // indentasi 4 spasi
            timestamp: <nilai>  // indentasi 4 spasi
          },                    // indentasi 2 spasi (tambahkan koma apabila bukan block terakhir)
          ...
        ]
        Jika blockchain kosong, menampilkan "[]" */
void printBlockchain(List blockchain){
        address P = First(blockchain); int c = NbElmt(blockchain);
        printf("[");
        if(!IsEmpty(blockchain)){
            printf("\n");
            for (int i = 1; i<=c; i++){
                printf("  Block %d: {\n", i);
                printf("    prevHash: %lld,\n", PrevHash(P));
                printf("    data: %lld,\n", Data(P));
                printf("    timestamp: %lld\n  }", Timestamp(P));
                P = Next(P);
                if(P != Nil){
                    printf(",");
                }
                printf("\n");
            }
        }

        printf("]\n");
}

/* Menghitung rata-rata nilai data dari semua block */
/* I.S. blockchain terdefinisi */
/* F.S. Mengembalikan rata-rata nilai data dari semua block dalam blockchain */
/* Jika blockchain kosong, mengembalikan 0 */
double getAverageData(List blockchain){
    address P = First(blockchain); double sum = 0.0; infotype count = 0;
    if(IsEmpty(blockchain)) return sum;
    while(P != Nil){
        sum += Data(P);
        count++;
        P = Next(P);
    }
    return sum/count;
}

/* Mencari block dengan nilai data terbesar */
/* I.S. blockchain terdefinisi */
/* F.S. Mengembalikan pointer ke block dengan nilai data terbesar */
/* Jika blockchain kosong, mengembalikan NULL */
address findLargestDataBlock(List blockchain){
    if(IsEmpty(blockchain)) return NULL;
    address P = First(blockchain), maxAddress = P; infotype maxData = Data(P);
    while(P != Nil){
        if(Data(P) > maxData){
            maxData = Data(P);
            maxAddress = P;
        }
        P = Next(P);
    }
    return maxAddress;    
}

// int main(){
//     List l;
//     CreateEmpty(&l);
//     printBlockchain(l);
//     printf("%d\n", validateChain(l));
//     initBlock(&l);
//     printBlockchain(l);
//     printf("%d\n", validateChain(l));
//     addBlock(&l, 865, 99);
//     addBlock(&l, 878, 99);
//     addBlock(&l, 876, 99);
//     addBlock(&l, 871, 99);
//     addBlock(&l, 877, 99);
//     printBlockchain(l);
//     printf("%d\n", validateChain(l));
//     printf("%lld\n", findLargestDataBlock(l)->info.data);
//     printf("%f\n", getAverageData(l));
// }

