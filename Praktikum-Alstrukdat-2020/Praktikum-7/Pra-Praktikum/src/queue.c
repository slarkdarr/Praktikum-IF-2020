/*
13519107
Daffa Ananda Pratama Resyaly
07 Oktober 2020
ADT Queue
*/

/* File : queue.c */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */

#include "queue.h"
#include <stdlib.h>

/* ********* Prototype ********* */
boolean IsEmpty (Queue Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
        return ((Head(Q) == Nil) && (Tail(Q) == Nil));
}

boolean IsFull (Queue Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
{
        return (Tail(Q) == MaxEl(Q) - 1);
}

int NBElmt (Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
        if (IsEmpty(Q)){
                return 0;
        }
        else{
                return ((Head(Q) <= Tail(Q)) ? (Tail(Q) - Head(Q) + 1) : (MaxEl(Q) + Tail(Q) - Head(Q) + 1));
        }
}

/* *** Kreator *** */
void MakeEmpty (Queue * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
        (*Q).T = (infotype *) malloc (Max * sizeof(infotype));
        (((*Q).T == NULL) ? (MaxEl(*Q) = 0) : (MaxEl(*Q) = Max));
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
}

/* *** Destruktor *** */
void DeAlokasi(Queue * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
{
        MaxEl(*Q) = 0;
        free((*Q).T);
}

/* *** Primitif Add/Delete *** */
void Enqueue (Queue * Q, infotype X)
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
{
        if (IsEmpty(*Q)){
                Head(*Q) = 0;
        }
        ((Tail(*Q) == MaxEl(*Q) - 1) ? (Tail(*Q) = 0) : (Tail(*Q)++));
        InfoTail(*Q) = X;
}

void Dequeue (Queue * Q, infotype * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer; 
        Q mungkin kosong */
{
        *X = InfoHead(*Q);
        if (Head(*Q) == Tail(*Q)){
                Head(*Q) = Nil;
                Tail(*Q) = Nil;
        }
        else{
                ((Head(*Q) == MaxEl(*Q) - 1) ? (Head(*Q) = 0) : (Head(*Q)++));
        }
}
