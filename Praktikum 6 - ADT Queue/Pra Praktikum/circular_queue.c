#include "boolean.h"
#include "circular_queue.h"
#include <stdio.h>

/* ********* Prototype ********* */
boolean IsEmpty (Queue Q){
    return (IDX_HEAD(Q) == IDX_UNDEF && IDX_TAIL(Q) == IDX_UNDEF);
}
/* Mengirim true jika Q kosong */
/* yaitu ketika idxHead=IDX_UNDEF dan idxTail=IDX_UNDEF */
boolean IsFull (Queue Q){
    return (IDX_HEAD(Q) == ((IDX_TAIL(Q) + 1) % (IDX_MAX + 1)));
}
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu ketika idxHead=0 dan idxTail=IDX_MAX atau idxHead=idxTail+1 ketika idxHead > idxTail */
int Length (Queue Q){
    return ((IDX_TAIL(Q) - IDX_HEAD(Q)) % (IDX_MAX + 1)) + 1;
}
/* Mengirimkan banyaknya elemen Q, 0 jika kosong */

/* *** Kreator *** */
void CreateQueue (Queue * Q){
    IDX_HEAD(*Q) = IDX_UNDEF;
    IDX_TAIL(*Q) = IDX_UNDEF;
}
/* I.S. sembarang */
/* F.S. mengembalikan Q kosong dengan kondisi sbb: */
/* - idxHead=IDX_UNDEF; */
/* - idxTail=IDX_UNDEF. */

/* *** Primitif Add/Delete *** */
void enqueue (Queue * Q, ElType X){
    if (IsEmpty(*Q)){
        IDX_HEAD(*Q) = 0;
        IDX_TAIL(*Q) = 0;
    } else {
        IDX_TAIL(*Q) = (IDX_TAIL(*Q) + 1) % (IDX_MAX + 1);
    }
    TAIL(*Q) = X;
}
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. Tail "maju" dengan mekanisme circular buffer,
        X menjadi idxTail yang baru
        Jika Q kosong, idxHead dimulai dari 0 */
ElType dequeue (Queue * Q){
    ElType temp = HEAD(*Q);
    if (Length(*Q) == 1){
        IDX_HEAD(*Q) = IDX_UNDEF;
        IDX_TAIL(*Q) = IDX_UNDEF;
    } else {
        IDX_HEAD(*Q) = (IDX_HEAD(*Q) + 1) % (IDX_MAX + 1);
    }
    return temp;
}
/* Proses: Menghapus idxHead pada Q dengan aturan FIFO, lalu mengembalikan nilainya */
/* I.S. Q tidak mungkin kosong */
/* F.S. mengembalikan nilai Q pada idxHead;
        Head "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

/* *** Display Queue *** */
void displayQueue(Queue q){
    printf("[");
    if (!IsEmpty(q)){
        int i = q.idxHead;
        while (i != q.idxTail){
            printf("%d,",q.Tab[i]); 
            i = (i + 1) % (IDX_MAX + 1);
        }
        printf("%d",q.Tab[q.idxTail]);
    }   
    printf("]\n");
}
/* Proses : Menuliskan isi Queue dengan traversal; Queue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma" */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */
/* Note: Output mengandung newline */