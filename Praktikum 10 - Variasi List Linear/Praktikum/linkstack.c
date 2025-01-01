#include "linkstack.h"
#include <stdlib.h>
#include <stdio.h>
#include "boolean.h"

/* File: linkstack.h */
// #ifndef _LINKSTACK_H
// #define _LINKSTACK_H
// #define Nil NULL

// /* Selektor */
// #define Top(S) (S).TOP
// #define InfoTop(S) (S).TOP->Info
// #define Next(P) (P)->Next
// #define Info(P) (P)->Info

// /* Deklarasi infotype */
// typedef int ElType;

// /* Stack dengan representasi berkait dengan pointer */
// typedef struct tNode *address;
// typedef struct tNode {
//     ElType Info;
//     address Next;
// } Node;

// /* Type stack dengan ciri TOP: */
// typedef struct {
//     address TOP; /* alamat TOP: elemen puncak */
// } Stack;

/* ********* PROTOTYPE MANAJEMEN MEMORI ********* */
void Alokasi(address *P, ElType X){
    *P = (address) malloc (sizeof (Node));
    if (*P != Nil){
        Info(*P) = X;
        Next(*P) = Nil;
    }
}
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan Next(P)=Nil */
/* P=Nil jika alokasi gagal */
void Dealokasi(address P){
    free(P);
}
/* I.S. P adalah hasil alokasi, P <> Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */

/* ********* PROTOTYPE REPRESENTASI LOJIK STACK ***************/
boolean IsEmpty(Stack S){
    return Top(S) == Nil;
}
/* Mengirim true jika Stack kosong: TOP(S) = Nil */
void CreateEmpty(Stack *S){
    Top(*S) = Nil;
}
/* I.S. sembarang */
/* F.S. Membuat sebuah stack S yang kosong */
void Push(Stack *S, ElType X){
    address P;
    Alokasi(&P, X);
    if(!IsEmpty(*S) && P != Nil){
        Next(P) = Top(*S);
        Top(*S) = P;
    } else if(P != Nil) {
        Top(*S) = P;
    }
}
/* Menambahkan X sebagai elemen Stack S */
/* I.S. S mungkin kosong, X terdefinisi */
/* F.S. X menjadi TOP yang baru jika alokasi X berhasil, */
/* jika tidak, S tetap */
/* Pada dasarnya adalah operasi Insert First pada list linier */
void Pop(Stack *S, ElType *X){
    address P = (Top(*S));
    *X = InfoTop(*S);
    Top(*S) = Next(P);
    Dealokasi(P);
}
/* Menghapus X dari Stack S. */
/* I.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, */
/* elemen TOP yang lama didealokasi */
/* Pada dasarnya adalah operasi Delete First pada list linier */