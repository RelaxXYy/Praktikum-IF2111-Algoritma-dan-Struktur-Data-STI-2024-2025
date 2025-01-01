#include "boolean.h"
#include "list.h"

/* Indeks yang digunakan seberapa banyak memori itu terisi */
/* Jika L adalah List, cara deklarasi dan akses: */
/* Deklarasi: L : List */
/* Maka cara akses:
 * L.A untuk mengakses seluruh nilai elemen list
 * L.A[i] untuk mengakses elemen ke-i */

/* ********** KONSTRUKTOR ********** */
/* Konstruktor: create list kosong */
List MakeList() {
    List L;
    for (int i = 0; i < MaxEl; i++) {
        L.A[i] = Mark;
    }
    return L;
}


/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean IsEmpty(List L){
	for(int i = 0; i<MaxEl;i++){
		if(L.A[i]!=Mark){
			return false;
		}
	}
	return true;
}

/* *** Menghasilkan sebuah elemen *** */
ElType Get(List L, IdxType i){
	return L.A[i];
}

/* *** Selektor SET : Mengubah nilai list dan elemen list *** */
void Set(List *L, IdxType i, ElType v){
	(*L).A[i]=v;
}

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int Length(List L){
	int count=0;
	for(int i = 0; i<MaxEl;i++){
		if(L.A[i]!=Mark){
			count++;
		}
	}
	return count;
}

/* *** Selektor INDEKS *** */
IdxType FirstIdx(List L){
	return 0;
}

IdxType LastIdx(List L){
	for(int i = MaxEl-1; i>=0;i--){
		if(L.A[i]!=Mark) return i;
	}
	return -1;
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (List L, IdxType i){
	return ((i>=0) && (i<MaxEl));
}

boolean IsIdxEff (List L, IdxType i){
	return ((i>=0) && (i<MaxEl) && (L.A[i]!=Mark));
}

/* ********** Operasi-operasi ********** */
boolean Search(List L, ElType X){
	for(int i = 0; i<MaxEl;i++){
		if(L.A[i]==X) return true;
	}
	return false;
}

void InsertFirst(List *L, ElType X) {
    if (Length(*L) < MaxEl) {
        for (int i = Length(*L); i > 0; i--) {
            (*L).A[i] = (*L).A[i - 1];
        }
        (*L).A[0] = X;
    }
}

void InsertAt(List *L, ElType X, IdxType i) {
    if (Length(*L) < MaxEl && IsIdxValid(*L, i)) {
        for (int j = Length(*L); j > i; j--) {
            (*L).A[j] = (*L).A[j - 1];
        }
        (*L).A[i] = X;
    }
}

void InsertLast(List *L, ElType X){
	if(Length(*L)<MaxEl) (*L).A[Length(*L)]=X;
}

void DeleteFirst(List *L) {
    if (!IsEmpty(*L)) {
        for (int i = 0; i < Length(*L) - 1; i++) {
            (*L).A[i] = (*L).A[i + 1];
        }
        (*L).A[Length(*L) - 1] = Mark;
    }
}

void DeleteAt(List *L, IdxType i) {
    if (IsIdxEff(*L, i)) {
        for (int j = i; j < Length(*L) - 1; j++) {
            (*L).A[j] = (*L).A[j + 1];
        }
        (*L).A[Length(*L) - 1] = Mark;
    }
}

void DeleteLast(List *L) {
    if (!IsEmpty(*L)) {
        (*L).A[LastIdx(*L)] = Mark;
    }
}


List Concat(List L1, List L2) {
    List L3 = MakeList();
    int index = 0;
    for (int i = 0; i < Length(L1); i++) {
        L3.A[index++] = L1.A[i];
    }
    for (int i = 0; i < Length(L2); i++) {
        L3.A[index++] = L2.A[i];
    }
    return L3;
}
