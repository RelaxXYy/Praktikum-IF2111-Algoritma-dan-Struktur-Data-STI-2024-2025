#include "array.h"
#include <stdio.h>

/* Konstruktor : create tabel kosong */
void MakeEmpty(TabInt *T) {
    T->Neff = 0;
}

/* Mengirimkan banyaknya elemen efektif tabel */
int NbElmt(TabInt T) {
    return T.Neff;
}

/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
int MaxNbEl(TabInt T) {
    return IdxMax - IdxMin + 1;
}

/* Prekondisi : Tabel T tidak kosong */
IdxType GetFirstIdx(TabInt T) {
    return IdxMin;
}

/* Prekondisi : Tabel T tidak kosong */
IdxType GetLastIdx(TabInt T) {
    return T.Neff;
}

/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
ElType GetElmt(TabInt T, IdxType i) {
    if (IsIdxEff(T, i)) {
        return T.TI[i - IdxMin]; // Adjust index for 0-based array
    }
    return 0; // Or handle error as necessary
}

/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan Tin */
void SetTab(TabInt Tin, TabInt *Tout) {
    Tout->Neff = Tin.Neff;
    for (int i = IdxMin; i <= Tout->Neff; i++) {
        Tout->TI[i - IdxMin] = Tin.TI[i - IdxMin];
    }
}

/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
void SetEl(TabInt *T, IdxType i, ElType v) {
    if (IsIdxEff(*T, i)) {
        T->TI[i - IdxMin] = v; // Adjust index for 0-based array
    }
}

/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
void SetNeff(TabInt *T, IdxType N) {
    if (N >= 0 && N <= MaxNbEl(*T)) {
        T->Neff = N;
    }
}

/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
boolean IsIdxValid(TabInt T, IdxType i) {
    return (i >= IdxMin && i <= IdxMax);
}

/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
boolean IsIdxEff(TabInt T, IdxType i) {
    return (i >= IdxMin && i <= T.Neff);
}

/* Mengirimkan true jika tabel T kosong */
boolean IsEmpty(TabInt T) {
    return (T.Neff == 0);
}

/* Mengirimkan true jika tabel T penuh */
boolean IsFull(TabInt T) {
    return (T.Neff == MaxNbEl(T));
}

/* Proses : Menuliskan isi tabel dengan traversal */
void TulisIsi(TabInt T) {
    if (IsEmpty(T)) {
        printf("Tabel kosong\n");
    } else {
        for (int i = GetFirstIdx(T); i <= GetLastIdx(T); i++) {
            printf("%d:%d\n", i, GetElmt(T, i));
        }
    }
}

/* Mengirimkan T1 + T2 */
TabInt PlusTab(TabInt T1, TabInt T2) {
    TabInt Hsl;
    MakeEmpty(&Hsl);
    SetNeff(&Hsl, NbElmt(T1));
    for (int i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++) {
        SetEl(&Hsl, i, GetElmt(T1, i) + GetElmt(T2, i));
    }
    return Hsl;
}

/* Mengirimkan T1 - T2 */
TabInt MinusTab(TabInt T1, TabInt T2) {
    TabInt Hsl;
    MakeEmpty(&Hsl);
    SetNeff(&Hsl, NbElmt(T1));
    for (int i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++) {
        SetEl(&Hsl, i, GetElmt(T1, i) - GetElmt(T2, i));
    }
    return Hsl;
}

/* Mengirimkan nilai maksimum tabel */
ElType ValMax(TabInt T) {
    ElType max = T.TI[0];
    for (int i = GetFirstIdx(T); i <= GetLastIdx(T); i++) {
        if (GetElmt(T, i) > max) {
            max = GetElmt(T, i);
        }
    }
    return max;
}

/* Mengirimkan nilai minimum tabel */
ElType ValMin(TabInt T) {
    ElType min = T.TI[0];
    for (int i = GetFirstIdx(T); i <= GetLastIdx(T); i++) {
        if (GetElmt(T, i) < min) {
            min = GetElmt(T, i);
        }
    }
    return min;
}

/* Mengirimkan indeks i dengan elemen ke-i adalah nilai maksimum pada tabel */
IdxType IdxMaxTab(TabInt T) {
    ElType max = ValMax(T);
    for (int i = GetFirstIdx(T); i <= GetLastIdx(T); i++) {
        if (GetElmt(T, i) == max) {
            return i;
        }
    }
    return IdxUndef; // Should not reach here if T is not empty
}

/* Mengirimkan indeks i dengan elemen ke-i nilai minimum pada tabel */
IdxType IdxMinTab(TabInt T) {
    ElType min = ValMin(T);
    for (int i = GetFirstIdx(T); i <= GetLastIdx(T); i++) {
        if (GetElmt(T, i) == min) {
            return i;
        }
    }
    return IdxUndef; // Should not reach here if T is not empty
}
