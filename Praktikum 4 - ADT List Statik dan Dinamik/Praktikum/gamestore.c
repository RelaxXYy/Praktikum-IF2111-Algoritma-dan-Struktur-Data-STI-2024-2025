#include "arrayGames.h"
#include "boolean.h"
#include <stdio.h>


/* I.S. games terdefinisi dan terisi katalog games yang ada di toko dan Q adalah jumlah aksi yang ditangani */
/* F.S. Menerima Q buah aksi yang masing-masing menjalankan kegiatannya sebagai berikut
        - Aksi 0: Mencetak permainan yang ada di toko saat ini
        - Aksi 1: Mencetak jumlah permainan dengan rating tertinggi
        - Aksi 2: Mencetak nama permainan dengan harga termurah
        - Aksi 3: Mencetak nama-nama permainan dengan rating tertinggi
*/

void UrusToko(TabGames games, int Q){
        for(int i=0;i<Q;i++){
                int n=0;
                scanf("%d", &n);
                if(n==0) TulisIsi(games);
                else if(n==1) {
                        int count=0, max=0;
                        max=MaxRating(games);
                        for(int j=GetFirstIdx(games);j<=GetLastIdx(games);j++){
                                if (GetElmt(games, j).rating==max) count++;
                        }
                        printf("%d\n", count);
                }
                else if(n==2) printf("%s\n",MinHargaNama(games));
                else if(n==3) {
                        int max=0;
                        max=MaxRating(games);
                        for(int j=GetFirstIdx(games);j<=GetLastIdx(games);j++){
                                if (GetElmt(games, j).rating==max) printf("%s\n", GetElmt(games, j).nama);
                        }
                }
        }
}


/*
CONTOH JALAN:
I.S. 
Q bernilai: 4 dan TabGames games berisi:
Minecraft | 5 | 50
Terraria | 5 | 50
Apex | 3 | 10
CSGO | 4 | 10
VSCode | 1 | 5

F.S. Diberikan aksi 0, 1, 2, dan 3 maka output yang keluar adalah
Minecraft | 5 | 50
Terraria | 5 | 50
Apex | 3 | 10
CSGO | 4 | 10
VSCode | 1 | 5
2
VSCode
Minecraft
Terraria


*/