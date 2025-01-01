#include <stdio.h>
#include "boolean.h"
#include "listMatkul.h"

void MakeEmpty (ListMatkul* L){
    (*L).Neff=0;
}

int NbElmt (ListMatkul L){
    return L.Neff;
}

int MaxNbEl (ListMatkul L){
    return MAX_CAPACITY;
}

IdxType GetFirstIdx (ListMatkul L){
    return 0;
}

IdxType GetLastIdx (ListMatkul L){
    return L.Neff-1;
}

ElType GetElmt (ListMatkul L, IdxType i){
    return L.contents[i];
}

void SetTab (ListMatkul Lin, ListMatkul* Lout){
    (*Lout).Neff = Lin.Neff;
    for(int i = 0; i < Lin.Neff; i++){
        (*Lout).contents[i] = Lin.contents[i];
    }
}

void SetEl (ListMatkul* L, IdxType i, ElType v){
    (*L).contents[i] = v;
    if ((*L).Neff < i+1){
        (*L).Neff = i+1;
    }
}

void SetNeff (ListMatkul* L, IdxType N){
    (*L).Neff = N;
}

boolean IsIdxValid (ListMatkul L, IdxType i){
    return i >= GetFirstIdx(L) && i < MAX_CAPACITY;
}

boolean IsIdxEff (ListMatkul L, IdxType i){
    return i >= GetFirstIdx(L) && i <= GetLastIdx(L);
}

boolean IsEmpty (ListMatkul L){
    return L.Neff == 0;
}

boolean IsFull (ListMatkul L){
    return L.Neff == MAX_CAPACITY;
}

void PrintIsi(ListMatkul L){
    if (IsEmpty(L)) printf("List kosong\n");
    else{
        for(int i = 0;i < L.Neff;i++){
            printf("%s(%d) - %d: %c\n", L.contents[i].kode, L.contents[i].sks, L.contents[i].semester, L.contents[i].nilai);
        }
    }
}

ElType MakeMatkul (char* kode, int sks, int semester, char nilai){
    ElType matkul;
    matkul.kode=kode;
    matkul.sks=sks;
    matkul.semester=semester;
    matkul.nilai=nilai;
    return matkul;
}

int SumNilai(ListMatkul L, int semester){
    int sum = 0;
    for(int i = 0;i<L.Neff;i++){
        if (L.contents[i].semester==semester){
            if (L.contents[i].nilai=='A') sum+=4*L.contents[i].sks;
            else if (L.contents[i].nilai=='B') sum+=3*L.contents[i].sks;
            else if (L.contents[i].nilai=='C') sum+=2*L.contents[i].sks;
            else if (L.contents[i].nilai=='D') sum+=1*L.contents[i].sks;  
        }   
    }
    return sum;
}

int CountMatkul(ListMatkul L, int semester){
    int count = 0;
    for(int i = 0;i<L.Neff;i++){
        if (L.contents[i].semester==semester) count++;
    }
    return count;
}

int CountSKS(ListMatkul L, int semester){
    int count = 0;
    for(int i = 0;i<L.Neff;i++){
        if (L.contents[i].semester==semester) count+=L.contents[i].sks;
    }
    return count;
}

int CountTotalSKS(ListMatkul L){
    int count = 0;
    for(int i = 0;i<L.Neff;i++){
        count+=L.contents[i].sks;
    }
    return count;
}

int MaxSemester(ListMatkul L){
    int max = 0;
    for(int i = 0;i<L.Neff;i++){
        if (L.contents[i].semester>max) max=L.contents[i].semester;
    }
    return max;
}

float HitungIP(ListMatkul L, int semester) {
    int nilai = SumNilai(L, semester);
    int sks = CountSKS(L, semester);

    if (sks == 0) return 0;

    return (float)nilai / sks;
}


float HitungIPK(ListMatkul L) {
    int totalNilai = 0, totalSKS = 0;
    int maxSem = MaxSemester(L);

    for (int i = 1; i <= maxSem; i++) {
        totalNilai += SumNilai(L, i);
        totalSKS += CountSKS(L, i);
    }
    if (totalSKS == 0) return 0;

    return (float)totalNilai / totalSKS;
}


int CountMatkulLuar(ListMatkul L, char* kodeJur){
    int count=0;
    for(int i =0;i<L.Neff;i++){
        if ((L.contents[i].kode[0]!=kodeJur[0]) || (L.contents[i].kode[1]!=kodeJur[1])){
            count++;
        }
    }
    return count;
}

void DisplaySIX(ListMatkul L){
    printf("IPK: %.2f\n", HitungIPK(L));
    printf("IP: %.2f\n", HitungIP(L, MaxSemester(L)));
    printf("SKS: Sudah Diambil %d SKS\n", CountTotalSKS(L));
    printf("Daftar Kuliah Semester %d:\n", MaxSemester(L));
    for(int i = 0;i < L.Neff;i++){
        if ((L.contents[i].semester)==MaxSemester(L)) printf("%s(%d) - %d: %c\n", L.contents[i].kode, L.contents[i].sks, L.contents[i].semester, L.contents[i].nilai);
    }
}