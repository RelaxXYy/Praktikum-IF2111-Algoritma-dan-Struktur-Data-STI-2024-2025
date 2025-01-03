#include "queuelist.h"
#include <stdlib.h>
#include <stdio.h>
#include "boolean.h"

/* File : queuelist.h */
/* Representasi queue dengan list berkait dengan first (HEAD) dan last (TAIL) */
// #ifndef _QUEUELIST_H
// #define _QUEUELIST_H

/* Konstanta */
#define Nil NULL

/* Deklarasi infotype */
typedef int infotype;

/* Queue dengan representasi berkait dengan pointer */
typedef struct tElmtQueue *address;
typedef struct tElmtQueue
{
    infotype Info;
    address Next;
} ElmtQueue;

/* Type queue dengan ciri HEAD dan TAIL : */
typedef struct
{
    address HEAD; /* alamat penghapusan */
    address TAIL; /* alamat penambahan */
} Queue;

/* Selektor */
#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define InfoHead(Q) (Q).HEAD->Info
#define InfoTail(Q) (Q).TAIL->Info
#define Next(P) (P)->Next
#define Info(P) (P)->Info

/* Prototype manajemen memori */
void Alokasi(address *P, infotype X){
    *P = (address) malloc (sizeof (ElmtQueue));
    if(*P != Nil){
        Info(*P) = X;
        Next(*P) = Nil;
    }
}
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan
        Next(P)=Nil */
/*      P=Nil jika alokasi gagal */
void Dealokasi(address P){
    free(P);
}
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
boolean IsEmpty(Queue Q){
    return Head(Q) == Nil && Tail(Q) == Nil;
}
/* Mengirim true jika Q kosong: HEAD(Q)=Nil and TAIL(Q)=Nil */
int NbElmt(Queue Q){
    int n = 0;
    if(IsEmpty(Q)) return n;
    P = Head(Q);
    while (P != Tail(Q)){
        n++;
        P = Next(P);
    }
    return n;

}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
/*** Kreator ***/
void CreateEmpty(Queue *Q){
    Head(*Q) == Nil;
    Tail(*Q) == Nil;
}
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk */
/*** Primitif Add/Delete ***/
void Enqueue(Queue *Q, infotype X){
    address P;
    Alokasi(&P, *X);
    if(IsEmpty(*Q) && P != Nil){
        Head(*Q) == P;
        Tail(*Q) == P;
    }
    else if (P != Nil){
        address last(Tail(*Q));
        Next(last) = P;
        Tail(*Q) = p;
    }
}
/* Proses: Mengalokasi X dan menambahkan X pada bagian TAIL dari Q
   jika alokasi berhasil; jika alokasi gagal Q tetap */
/* Pada dasarnya adalah proses insert last */
/* I.S. Q mungkin kosong */
/* F.S. X menjadi TAIL, TAIL "maju" */
void Dequeue(Queue *Q, infotype *X){
    address P = Head(*Q);
    *X = Info(P);
    if(Next(P) == Nil){
        CreateEmpty(*Q);
    } else {
        Head(*Q) = Next(P);
    }
    Dealokasi(P);
}
/* Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi
   elemen HEAD */
/* Pada dasarnya operasi delete first */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */
