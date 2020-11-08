/*
13519107
Daffa Ananda Pratama Resyaly
08 Oktober 2020
Priority Queue
*/

/* File : prioqueue.c */
/* Definisi ADT Priority Queue Char dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */
/* Elemen queue terurut tidak mengecil berdasarkan elemen prio */

#include "prioqueuechar.h"
#include <stdlib.h>
#include <stdio.h>

/* ********* Prototype ********* */
boolean IsEmpty (PrioQueueChar Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
    return (Head(Q) == Nil && Tail(Q) == Nil);
}

boolean IsFull (PrioQueueChar Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
{
    return (Tail(Q) == MaxEl(Q) - 1);
}

int NBElmt (PrioQueueChar Q)
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
void MakeEmpty (PrioQueueChar * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
    PrioQueueChar Qtemp;
    Qtemp.T = (infotype *) malloc (Max * sizeof(infotype));
    ((Qtemp.T == NULL) ? (MaxEl(Qtemp) = 0) : (MaxEl(Qtemp) = Max));
    Head(Qtemp) = Nil;
    Tail(Qtemp) = Nil;
    *Q = Qtemp;
}

/* *** Destruktor *** */
void DeAlokasi(PrioQueueChar * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
{
    MaxEl(*Q) = 0;
    free((*Q).T);
}

/* *** Primitif Add/Delete *** */
void Enqueue (PrioQueueChar * Q, infotype X)
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
{
    if (IsEmpty(*Q)){
        Head(*Q) = 1;
    }
    ((Tail(*Q) == MaxEl(*Q) - 1) ? (Tail(*Q) = 1) : (Tail(*Q)++));
    InfoTail(*Q) = X;

    int i = Tail(*Q);
    boolean insert = true;
    while (i != Head(*Q) && insert){
        int j = i - 1;
        ((j == 0) ? MaxEl(*Q) : (i - 1));
        if (Prio(Elmt(*Q,i)) > Prio(Elmt(*Q,j))){
            infotype temp = Elmt(*Q,i);
            Elmt(*Q,i) = Elmt(*Q,j);
            Elmt(*Q,j) = temp;
        }
        else{
            insert = false;
        }
        i = j;
    }
}

void Dequeue (PrioQueueChar * Q, infotype * X)
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
        ((Head(*Q) == MaxEl(*Q) - 1) ? (Head(*Q) = 1) : (Head(*Q)++));
    }
}

/* Operasi Tambahan */
void PrintPrioQueueChar (PrioQueueChar Q)
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<prio-1> <elemen-1>
...
<prio-n> <elemen-n>
#
*/
{
    infotype el;
    while (!IsEmpty(Q)){
        Dequeue(&Q, &el);
        printf("%d %d\n", Prio(el), Info(el));
    }
    printf("#\n");
}
