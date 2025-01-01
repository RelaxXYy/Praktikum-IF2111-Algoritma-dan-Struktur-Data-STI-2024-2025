#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "arrayGames.h"

/* ********** KONSTRUKTOR ARRAY ********** */
void MakeEmpty(TabGames *T) {
    T->Neff = 0;
}

/* ********** SELEKTOR ********** */
int NbElmt(TabGames T) {
    return T.Neff;
}

int MaxNbEl(TabGames T) {
    return IdxMax - IdxMin + 1;
}

IdxType GetFirstIdx(TabGames T) {
    return IdxMin;
}

IdxType GetLastIdx(TabGames T) {
    return IdxMin + T.Neff - 1;
}

ElType GetElmt(TabGames T, IdxType i) {
    return T.TI[i - IdxMin];
}

/* ********** SET dan MODIFIKASI ********** */
void SetTab(TabGames Tin, TabGames *Tout) {
    Tout->Neff = Tin.Neff;
    for (int i = GetFirstIdx(Tin); i <= GetLastIdx(Tin); i++) {
        Tout->TI[i - IdxMin] = GetElmt(Tin, i);
    }
}

void SetEl(TabGames *T, IdxType i, ElType v) {
    if (IsIdxValid(*T, i)) {
        T->TI[i - IdxMin] = v;
        if (i > T->Neff + IdxMin - 1) {
            SetNeff(T, i);
        }
    }
}

void SetNeff(TabGames *T, IdxType N) {
    T->Neff = N;
}

/* ********** TEST INDEKS ********** */
boolean IsIdxValid(TabGames T, IdxType i) {
    return i >= GetFirstIdx(T) && i <= IdxMax;
}

boolean IsIdxEff(TabGames T, IdxType i) {
    return i >= GetFirstIdx(T) && i <= GetLastIdx(T);
}

/* ********** TEST KOSONG/PENUH ********** */
boolean IsEmpty(TabGames T) {
    return T.Neff == 0;
}

boolean IsFull(TabGames T) {
    return NbElmt(T) == MaxNbEl(T);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void TulisIsi(TabGames T) {
    if (IsEmpty(T)) {
        printf("Tabel kosong\n");
    } else {
        for (int i = GetFirstIdx(T); i <= GetLastIdx(T); i++) {
            printf("%s | %d | %d\n", GetElmt(T, i).nama, GetElmt(T, i).rating, GetElmt(T, i).harga);
        }
    }
}

/* ********** KONSTRUKTOR GAMES ********** */
ElType MakeGame(char *Nama, int Rating, int Harga) {
    ElType Game;
    Game.nama = Nama;
    Game.rating = Rating;
    Game.harga = Harga;
    return Game;
}

/* ********** OPERATOR STATISTIK GAME ********** */
float RataRataHarga(TabGames T) {
    if (IsEmpty(T)) return 0;
    int sum = 0;
    for (int i = GetFirstIdx(T); i <= GetLastIdx(T); i++) {
        sum += GetElmt(T, i).harga;
    }
    return (float)sum / NbElmt(T);
}

float RataRataRating(TabGames T) {
    if (IsEmpty(T)) return 0;
    int sum = 0;
    for (int i = GetFirstIdx(T); i <= GetLastIdx(T); i++) {
        sum += GetElmt(T, i).rating;
    }
    return (float)sum / NbElmt(T);
}

int MaxRating(TabGames T) {
    if (IsEmpty(T)) return -1; // Penanda untuk tabel kosong
    int max = GetElmt(T, GetFirstIdx(T)).rating;
    for (int i = GetFirstIdx(T) + 1; i <= GetLastIdx(T); i++) {
        if (GetElmt(T, i).rating > max) {
            max = GetElmt(T, i).rating;
        }
    }
    return max;
}

int MinRating(TabGames T) {
    if (IsEmpty(T)) return -1; // Penanda untuk tabel kosong
    int min = GetElmt(T, GetFirstIdx(T)).rating;
    for (int i = GetFirstIdx(T) + 1; i <= GetLastIdx(T); i++) {
        if (GetElmt(T, i).rating < min) {
            min = GetElmt(T, i).rating;
        }
    }
    return min;
}

char *MaxHargaNama(TabGames T) {
    if (IsEmpty(T)) return NULL; // Penanda untuk tabel kosong
    int maxid = GetFirstIdx(T);
    for (int i = GetFirstIdx(T) + 1; i <= GetLastIdx(T); i++) {
        if (GetElmt(T, i).harga > GetElmt(T, maxid).harga || 
            (GetElmt(T, i).harga == GetElmt(T, maxid).harga && GetElmt(T, i).rating > GetElmt(T, maxid).rating)) {
            maxid = i;
        }
    }
    return GetElmt(T, maxid).nama;
}

char *MinHargaNama(TabGames T) {
    if (IsEmpty(T)) return NULL; // Penanda untuk tabel kosong
    int minid = GetFirstIdx(T);
    for (int i = GetFirstIdx(T) + 1; i <= GetLastIdx(T); i++) {
        if (GetElmt(T, i).harga < GetElmt(T, minid).harga || 
            (GetElmt(T, i).harga == GetElmt(T, minid).harga && GetElmt(T, i).rating > GetElmt(T, minid).rating)) {
            minid = i;
        }
    }
    return GetElmt(T, minid).nama;
}

int JumlahGamesRating(TabGames T, int R) {
    int ctr = 0;
    for (int i = GetFirstIdx(T); i <= GetLastIdx(T); i++) {
        if (GetElmt(T, i).rating == R) {
            ctr++;
        }
    }
    return ctr;
}
