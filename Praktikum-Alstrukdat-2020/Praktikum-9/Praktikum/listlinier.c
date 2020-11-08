/*
13519107
Daffa Ananda Pratama Resyaly
05 November 2020
List Linier
ADT List Berkait
*/

/* File : listlinier.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* infotype adalah integer */

#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
/* Mengirim true jika list kosong */
{
    return (First(L) == Nil);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
    First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    ElmtList *P;

    P = (ElmtList *) malloc (sizeof(ElmtList));

    return ((P == Nil) ? Nil : (Info(P) = X, Next(P) = Nil, P));
}

void Dealokasi (address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
    address P;
    boolean found = false;

    P = First(L);
    while (P != Nil && !(found)){
        if (Info(P) == X){
            found = true;
        }
        else{
            P = Next(P);
        }
    }

    return (found ? P : Nil);
}

boolean FSearch (List L, address P)
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
{
    address Ptemp;
    boolean found = false;

    Ptemp = First(L);
    while (Ptemp != Nil && !(found)){
        if (Ptemp == P){
            found = true;
        }
        else{
            Ptemp = Next(Ptemp);
        }
    }
    
    return found;
}

address SearchPrec (List L, infotype X)
/* Mengirimkan address elemen sebelum elemen yang nilainya=X */
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P dan Info(P)=X. */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec=Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain */
{
    address P, Prec;
    boolean found;

    P = First(L); Prec = Nil;
    while(P != Nil && !(found)){
        if (Info(P) == X){
            found = true;
        }
        else{
            Prec = P;
            P = Next(P);
        }
    }
    
    return (found ? Prec : (Prec = Nil, Prec));
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
    address P;

    P = Alokasi(X);
    if (P != Nil){
        InsertFirst(L, P);
    }
}

void InsVLast (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    address P;

    P = Alokasi(X);
    if (P != Nil){
        InsertLast(L, P);
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    address P;

    DelFirst(L, &P);
    *X = Info(P);
    Dealokasi(&P);
}

void DelVLast (List *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    address P;

    DelLast(L, &P);
    *X = Info(P);
    Dealokasi(&P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
    Next(P) = First(*L);
    First(*L) = P;
}

void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    address Last;

    if (IsEmpty(*L)){
        First(*L) = P;
        Next(P) = Nil;
    }
    else{
        Last = First(*L);
        while (Next(Last) != Nil){
            Last = Next(Last);
        }
        InsertAfter(L, P, Last);
    }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    *P = First(*L);
    First(*L) = Next(*P);
}

void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika ada lebih dari satu elemen list dengan Info bernilai X */
/* maka yang dihapus hanya elemen pertama dengan Info = X */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
    address P, Prec;

    P = Search(*L, X); Prec = First(*L);
    if (P != Nil){
        if (Prec == P){
            DelFirst(L, &P);
        }
        else{
            while (Next(Prec) != P){
                Prec = Next(Prec);
            }
            DelAfter(L, &P, Prec);
        }
    }
    Dealokasi(&P);
}

void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
{
    address Prec;

    *P = First(*L); Prec = Nil;
    while (Next(*P) != Nil){
        Prec = *P; *P = Next(*P);
    }

    ((Prec == Nil) ? (First(*L) = Nil) : (Next(Prec) = Nil));
}

void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    *Pdel = Next(Prec);
    if (*Pdel != Nil){
        Next(Prec) = Next(Next(Prec));
    }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    address P;

    printf("[");
    if (!IsEmpty(L)){
        P = First(L);
        while (P != Nil){
            printf("%d", Info(P));
            P = Next(P);
            if (P != Nil){
                printf(",");
            }
        }
    }
    printf("]");
}

int NbElmt (List L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
    address P;
    int i;

    P = First(L); i = 0;
    while (P != Nil){
        P = Next(P);
        i++;
    }
    return i;
}

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max (List L)
/* Mengirimkan nilai info(P) yang maksimum */
{
    address P;
    infotype max;

    P = First(L); max = Info(P);
    while (P != Nil){
        if (Info(P) >= max){
            max = Info(P);
        }
        P = Next(P);
    }
    return max;
}

address AdrMax (List L)
/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
{
    address P;

    return (P = Search(L,Max(L)));
}

infotype Min (List L)
/* Mengirimkan nilai info(P) yang minimum */
{
    address P;
    infotype min;

    P = First(L); min = Info(P);
    while (P != Nil){
        if (Info(P) <= min){
            min = Info(P);
        }
        P = Next(P);
    }
    return min;
}

address AdrMin (List L)
/* Mengirimkan address P, dengan info(P) yang bernilai minimum */
{
    address P;

    return (P = Search(L,Min(L)));
}

float Average (List L)
/* Mengirimkan nilai rata-rata info(P) */
{
    address P;
    float sum = 0;

    P = First(L);
    while (P != Nil){
        sum += Info(P);
        P = Next(P);
    }
    
    return (sum / NbElmt(L));
}

/****************** PROSES TERHADAP LIST ******************/
void DelAll (List *L)
/* Delete semua elemen list dan alamat elemen di-dealokasi */
{
    address P;

    P = First(*L);
    while (P != Nil){
        DelP(L, Info(P));
        P = Next(P);
    }

    Dealokasi(&P);
}

void InversList (List *L)
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
{
    address P, Prec, Last;

    P = First(*L); Prec = Nil;
    while (P != Nil){
        Last = P;
        P = Next(P);
        Next(Last) = Prec;
        Prec = Last;
    }
    First(*L) = Last;
}

List FInversList (List L)
/* Mengirimkan list baru, hasil invers dari L */
/* dengan menyalin semua elemn list. Alokasi mungkin gagal. */
/* Jika alokasi gagal, hasilnya list kosong */
/* dan semua elemen yang terlanjur di-alokasi, harus didealokasi */
{
    List L1;

    L1 = FCopyList(L);
    InversList(&L1);

    return L1;
}

void CopyList (List *L1, List *L2)
/* I.S. L1 sembarang. F.S. L2=L1 */
/* L1 dan L2 "menunjuk" kepada list yang sama.*/
/* Tidak ada alokasi/dealokasi elemen */
{
    First(*L2) = First(*L1);
}

List FCopyList (List L)
/* Mengirimkan list yang merupakan salinan L */
/* dengan melakukan alokasi. */
/* Jika ada alokasi gagal, hasilnya list kosong dan */
/* semua elemen yang terlanjur di-alokasi, harus didealokasi */
{
    List L1;
    address P, P1;
    boolean fail;

    CreateEmpty(&L1); P = First(L); fail = false;
    while (P != Nil && !(fail)){
        P1 = Alokasi(Info(P));
        if (P1 != Nil){
            InsertLast(&L1, P1);
        }
        else{
            fail = true;
            DelAll(&L1);
        }
        P = Next(P);
    }

    return L1;
}

void CpAlokList (List Lin, List *Lout)
/* I.S. Lin sembarang. */
/* F.S. Jika semua alokasi berhasil,maka Lout berisi hasil copy Lin */
/* Jika ada alokasi yang gagal, maka Lout=Nil dan semua elemen yang terlanjur dialokasi, didealokasi */
/* dengan melakukan alokasi elemen. */
/* Lout adalah list kosong jika ada alokasi elemen yang gagal */
{
    *Lout = FCopyList(Lin);
}

void Konkat (List L1, List L2, List * L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 tetap, L3 adalah hasil konkatenasi L1 & L2 */
/* Jika semua alokasi berhasil, maka L3 adalah hasil konkatenasi*/
/* Jika ada alokasi yang gagal, semua elemen yang sudah dialokasi */
/* harus di-dealokasi dan L3=Nil*/
/* Konkatenasi dua buah list : L1 & L2 menghasilkan L3 yang "baru" */
/* Elemen L3 adalah hasil alokasi elemen yang “baru”. */
/* Jika ada alokasi yang gagal, maka L3 harus bernilai Nil*/
/* dan semua elemen yang pernah dialokasi didealokasi */
{
    address LastP1;

    CreateEmpty(L3);

    LastP1 = First(*L3);
    if (!(IsEmpty(L1))){
        CpAlokList(L1, L3);
        while (Next(LastP1) != Nil){
            LastP1 = Next(LastP1);
        }
        Next(LastP1) = First(L2);
    }
    else{
        CpAlokList(L2, L3);
    }
}

void Konkat1 (List *L1, List *L2, List *L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
    address P1, P2;
    CreateEmpty(L3);

    P1 = First(*L1); P2 = First(*L2); First(*L3) = P1;
    if (!(IsEmpty(*L1))){
        while (Next(P1) != Nil){
            P1 = Next(P1);
        }
        Next(P1) = P2;
    }
    else{
        First(*L3) = P2;
    }
    CreateEmpty(L1);
    CreateEmpty(L2);
}

void PecahList (List *L1, List *L2, List L)
/* I.S. L mungkin kosong */
/* F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2 */
/* L tidak berubah: untuk membentuk L1 dan L2 harus alokasi */
/* L1 berisi separuh elemen L dan L2 berisi sisa elemen L */
/* Jika elemen L ganjil, maka separuh adalah NbElmt(L) div 2 */
{
    address P;

    CpAlokList(L, L1);
    CpAlokList(L, L2);
    int i = 0;
    if (NbElmt(L) % 2 == 1){
        while (i < (NbElmt(L)+1)/2){
            DelLast(L1, &P);
            i++;
        }
        while (i < (NbElmt(L)-1)/2){
            DelLast(L2,&P);
            i++;
        }
    }
    else{
        int i = 0;
        while (i < NbElmt(L)/2){
            DelLast(L1,&P);
            DelLast(L2,&P);
            i++;
        }
    }
}
