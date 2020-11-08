/*  
13519107
Daffa Ananda Pratama Resyaly
10 September 2020
Arraypos.c
*/

/* MODUL TABEL INTEGER DENGAN ELEMEN POSITIF */
/* Berisi definisi dan semua primitif pemrosesan tabel integer dengan elemen positif */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori tabel statik */

#include <stdio.h>
#include "boolean.h"
#include "arraypos.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty (TabInt * T)
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
/* Proses: Inisialisasi semua elemen tabel T dengan ValUndef */
{
    int i;
    for(i=IdxMin; i<=IdxMax; i++){
        (*T).TI[i] = ValUndef;
    }
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabInt T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
{
    int i;
    int eff = 0;
    for(i = IdxMin; i <= IdxMax; i++){
        if(T.TI[i] != ValUndef){
            eff += 1;
        }
        else{
            return eff;
        }
    }
    return eff;
}

/* *** Daya tampung container *** */
int MaxNbEl (TabInt T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
    return (IdxMax - IdxMin+1);
}

/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
    return IdxMin;
}

IdxType GetLastIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
    return (IdxMin+NbElmt(T)-1);
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
    return(i >= IdxMin && i <= IdxMax);
}

boolean IsIdxEff (TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
    return(i >= GetFirstIdx(T) && i <= GetLastIdx(T));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabInt T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
    int i;
    boolean emp = true;
    for(i = GetFirstIdx(T); i <= GetLastIdx(T); i++){
        if(T.TI[i] != ValUndef){
            emp = false;
        }
    }
    return emp;
}

/* *** Test tabel penuh *** */
boolean IsFull (TabInt T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
    int i;
    boolean full = false;
    for(i = GetFirstIdx(T); i <= GetLastIdx(T)+1; i++){
        if(i == IdxMax){
            full = true;
        }
    }
    return full;
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi (TabInt * T)
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxNbEl(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxNbEl(T); Lakukan N kali: Baca elemen mulai dari indeks 
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
{
    int N;
    MakeEmpty(T);

    while(true){
        scanf("%d\n", &N);
        if((N >= 0) && (N <= MaxNbEl(*T))){
            break;
        }
    }
    if(N > 0){
        int i;
        for(i = GetFirstIdx(*T); i < N; i++){
            scanf("%d\n", &(T->TI[i]));
        }
    }
    else{
        MakeEmpty(T);
    }
}

void TulisIsiTab (TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku; 
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */
{
    if (!IsEmpty(T)){
        int i;
        printf("[");
        for(i = GetFirstIdx(T); i <= GetLastIdx(T); i++){
            printf("%d", T.TI[i]);
            if (i != GetLastIdx(T)){
                printf(",");
            }
        }
        printf("]");
    }
    else{
        printf("[]");
    }
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusMinusTab (TabInt T1, TabInt T2, boolean plus)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Jika plus = true, mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
{
    int i, hasil1, hasil2;
    TabInt tabHasil;
    MakeEmpty(&tabHasil);
    
    for(i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++){
        if(plus){
            if(T1.TI[i] != ValUndef){
                hasil1 = T1.TI[i];
            }
            else{
                hasil1 = 0;
            }
            if(T2.TI[i] != ValUndef){
                hasil2 = T2.TI[i];
            }
            else{
                hasil2 = 0;
            }
            tabHasil.TI[i] = hasil1 + hasil2;
        }
        else{
            if(T1.TI[i] != ValUndef){
                hasil1 = T1.TI[i];
            }
            else{
                hasil1 = 0;
            }
            if(T2.TI[i] != ValUndef){
                hasil2 = T2.TI[i];
            }
            else{
                hasil2 = 0;
            }
            tabHasil.TI[i] = hasil1 - hasil2;
        }
    }
    return tabHasil;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ (TabInt T1, TabInt T2)
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika ukuran T1 = T2 dan semua elemennya sama */
{
    int i;
    boolean eq = true;

    for(i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++){
        if(T1.TI[i] != T2.TI[i]){
            eq = false;
        }
    }
    return eq;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1 (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */
{
    int i = GetFirstIdx(T);
    int Idx;

    if(IsEmpty(T)){
        Idx = IdxUndef;
    }
    else{
        while(i <= GetLastIdx(T) && T.TI[i] != X){
            i += 1;
        }
        if(T.TI[i] == X){
            Idx = i;
        }
        else{
            Idx = IdxUndef;
        }
    }
    return Idx;
}

boolean SearchB (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Skema searching yang digunakan bebas */
{
    int i = GetFirstIdx(T);
    boolean found = false;

    while (i <= GetLastIdx(T) && !(found)){
        if (T.TI[i] == X){
            found = true;
        }
        else
        {
            i += 1;
        } 
    }
    return found;
}

/* ********** NILAI EKSTREM ********** */
void MaxMin (TabInt T, ElType * Max, ElType * Min)
/* I.S. Tabel T tidak kosong */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */
{
    int i;
    int maks = T.TI[GetFirstIdx(T)];
    int min = T.TI[GetFirstIdx(T)];

    for (i = GetFirstIdx(T); i <= GetLastIdx(T); i++){
        if (maks < T.TI[i]){
            maks = T.TI[i];
        }
        else if (min > T.TI[i]){
            min = T.TI[i];
        }
    }
    *Max = maks;
    *Min = min;
}

/* ********** OPERASI LAIN ********** */
ElType SumTab (TabInt T)
/* Menghasilkan hasil penjumlahan semua elemen T */
/* Jika T kosong menghasilkan 0 */
{
    int sum = 0;
    int i;
    if(IsEmpty(T)){
        return 0;
    }
    else{
        for(i = GetFirstIdx(T); i <= GetLastIdx(T); i++){
            sum += T.TI[i];
        }
        return sum;
    }
}

int CountX (TabInt T, ElType X)
/* Menghasilkan berapa banyak kemunculan X di T */
/* Jika T kosong menghasilkan 0 */
{
    int sum = 0;
    int i;
    for(i = GetFirstIdx(T); i <= GetLastIdx(T); i++){
        if(T.TI[i] == X){
            sum += 1;
        }
    }
    return sum;
}

boolean IsAllGenap (TabInt T)
/* Menghailkan true jika semua elemen T genap */
{
    int i;
    boolean even = true;
    for(i = GetFirstIdx(T); i <= GetLastIdx(T); i++){
        if (T.TI[i] % 2 != 0){
            even = false;
        }
    }
    return even;
}

/* ********** SORTING ********** */
void Sort (TabInt * T, boolean asc)
/* I.S. T boleh kosong */
/* F.S. Jika asc = true, T terurut membesar */
/*      Jika asc = false, T terurut mengecil */
/* Proses : Mengurutkan T dengan salah satu algoritma sorting,
   algoritma bebas */
{
    int i, pass, temp, iMax;

    if (asc){
        for(pass = GetFirstIdx(*T); pass < GetLastIdx(*T); pass++){
            iMax = pass;
            for(i = pass+1; i <= GetLastIdx(*T); i++){
                if (T->TI[iMax] > T->TI[i]){
                    iMax = i;
                }
            }
            temp = (*T).TI[iMax];
            T->TI[iMax] = T->TI[pass];
            T->TI[pass] = temp;
        }
    }
    else{
        for(pass = GetFirstIdx(*T); pass <= GetLastIdx(*T); pass++){
            iMax = pass;
            for(i = pass+1; i <= GetLastIdx(*T); i++){
                if (T->TI[iMax] < T->TI[i]){
                    iMax = i;
                }
            }
            temp = (*T).TI[iMax];
            T->TI[iMax] = T->TI[pass];
            T->TI[pass] = temp;
        }
    }
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl (TabInt * T, ElType X)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
{
    (*T).TI[GetLastIdx(*T)+1] = X;
}

/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl (TabInt * T, ElType * X)
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
{
    *X = T->TI[GetLastIdx(*T)];
    T->TI[GetLastIdx(*T)] = ValUndef;
}
