/* 13519107
    Daffa Ananda Pratama Resyaly
    17 September 2020
    Modul Tabel Integer
    Arraydin
*/

/* MODUL TABEL INTEGER */
/* Berisi definisi dan semua primitif pemrosesan tabel integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi II : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori tabel dinamik */

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "arraydin.h"

/* Indeks yang digunakan [IdxMin..MaxEl-1] */
/* Jika T adalah TabInt, cara deklarasi dan akses: */
/* Deklarasi : T : TabInt */
/* Maka cara akses:
   T.Neff  untuk mengetahui banyaknya elemen
   T.TI    untuk mengakses seluruh nilai elemen tabel
   T.TI[i] untuk mengakses elemen ke-i */
/* Definisi :
  Tabel kosong: T.Neff = 0
  Definisi elemen pertama : T.TI[i] dengan i=0
  Definisi elemen terakhir yang terdefinisi: T.TI[i] dengan i=T.Neff */

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty(TabInt *T, int maxel)
/* I.S. T sembarang, maxel > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas maxel */
{
    IdxType i;

    T->Neff = 0;
    T->MaxEl = maxel;
    T->TI = (int*) malloc (maxel * sizeof(int));

    for (i = IdxMin; i < maxel; i++){
        T->TI[i] = 0;
    }
}

void Dealokasi(TabInt *T)
/* I.S. T terdefinisi; */
/* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; Neff(T)=0 */
{   
    T->Neff = 0;
    T->MaxEl = 0;
    free(T->TI);
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt(TabInt T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
{
    return T.Neff;
}

/* *** Daya tampung container *** */
int MaxElement(TabInt T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
    return T.MaxEl;
}

/* *** Selektor INDEKS *** */
IdxType GetFirstIdx(TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
    return IdxMin;
}

IdxType GetLastIdx(TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
    return (NbElmt(T) - 1);
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid(TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
    return (i >= IdxMin && i < T.MaxEl);
}

boolean IsIdxEff(TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
    return (i >= GetFirstIdx(T) && i <= GetLastIdx(T));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty(TabInt T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
    return (T.Neff == 0);
}

/* *** Test tabel penuh *** */
boolean IsFull(TabInt T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
    return (T.Neff == T.MaxEl);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi(TabInt *T)
/* I.S. T sembarang dan sudah dialokasikan sebelumnya */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxElement(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxElement(T); Lakukan N kali: Baca elemen mulai dari indeks
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
{
    ElType N;

    while(true){
        scanf("%d\n", &N);
        if((N >= 0) && (N <= MaxElement(*T))){
            break;
        }
    }
    if (N > 0){
        IdxType i;
        T->Neff = N;
        for(i = GetFirstIdx(*T); i <= GetLastIdx(*T); i++){
            scanf("%d\n", &(T->TI[i]));
        }
    }
    else{
        T->Neff = 0;
    }
}

void TulisIsiTab(TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */
{
    if (!IsEmpty(T)){
        IdxType i;
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
TabInt PlusMinusTab(TabInt T1, TabInt T2, boolean plus)
/* Prekondisi : T1 dan T2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
{
    IdxType i;
    int hasil1, hasil2;    
    TabInt tabHasil;

    MakeEmpty(&tabHasil, T1.MaxEl);
    tabHasil.Neff = T1.Neff;

    for(i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++){
        hasil1 = T1.TI[i];
        hasil2 = T2.TI[i];
        if(plus){
            tabHasil.TI[i] = hasil1 + hasil2;
        } 
        else{
            tabHasil.TI[i] = hasil1 - hasil2;
        }
    }
    return tabHasil;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ(TabInt T1, TabInt T2)
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika Neff T1 = T2 dan semua elemennya sama */
{
    IdxType i;
    boolean eq = true;
    
    if (T1.Neff != T2.Neff){
        eq = false;
    }

    for(i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++){
        if(T1.TI[i] != T2.TI[i] || i > GetLastIdx(T2)){
            eq = false;
            break;
        }
    }
    return eq;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1(TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */
{
    IdxType i = GetFirstIdx(T);
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

boolean SearchB(TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Skema searching yang digunakan bebas */
{
    IdxType i = GetFirstIdx(T);
    boolean found = false;

    while (i <= GetLastIdx(T) && !(found)){
        if (T.TI[i] == X){
            found = true;
        } 
        else{
            i += 1;
        } 
    }
    return found;
}

/* ********** NILAI EKSTREM ********** */
void MaxMin(TabInt T, ElType *Max, ElType *Min)
/* I.S. Tabel T tidak kosong */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */
{
    IdxType i;
    ElType maks = T.TI[GetFirstIdx(T)];
    ElType min = T.TI[GetFirstIdx(T)];

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
void CopyTab(TabInt Tin, TabInt *Tout)
/* I.S. Tin terdefinisi tidak kosong, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (identik, Neff dan MaxEl sama) */
/* Proses : Menyalin isi Tin ke Tout */
{
    IdxType i;
    TabInt tabHasil;

    MakeEmpty(&tabHasil, Tin.MaxEl);
    tabHasil.Neff = Tin.Neff;

    for(i = GetFirstIdx(Tin); i <= GetLastIdx(Tin); i++){
        tabHasil.TI[i] = Tin.TI[i];
    }
    *Tout = tabHasil;
}

ElType SumTab(TabInt T)
/* Menghasilkan hasil penjumlahan semua elemen T */
/* Jika T kosong menghasilkan 0 */
{
    int sum = 0;
    IdxType i;

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

int CountX(TabInt T, ElType X)
/* Menghasilkan berapa banyak kemunculan X di T */
/* Jika T kosong menghasilkan 0 */
{
    int sum = 0;
    IdxType i;

    for(i = GetFirstIdx(T); i <= GetLastIdx(T); i++){
        if(T.TI[i] == X){
            sum += 1;
        }
    }
    return sum;
}

boolean IsAllGenap(TabInt T)
/* Menghailkan true jika semua elemen T genap. T boleh kosong */
{
    IdxType i;
    boolean even = true;

    for(i = GetFirstIdx(T); i <= GetLastIdx(T); i++){
        if (T.TI[i] % 2 != 0){
            even = false;
        }
    }
    return even;
}

/* ********** SORTING ********** */
void Sort(TabInt *T, boolean asc)
/* I.S. T boleh kosong */
/* F.S. Jika asc = true, T terurut membesar */
/*      Jika asc = false, T terurut mengecil */
/* Proses : Mengurutkan T dengan salah satu algoritma sorting,
   algoritma bebas */
{
    IdxType i, iMax, pass;
    ElType temp;

    if (asc){
        for(pass = GetFirstIdx(*T); pass < GetLastIdx(*T); pass++){
            iMax = pass;
            for(i = pass+1; i <= GetLastIdx(*T); i++){
                if (T->TI[iMax] > T->TI[i]){
                    iMax = i;
                }
            }
            temp = T->TI[iMax];
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
            temp = T->TI[iMax];
            T->TI[iMax] = T->TI[pass];
            T->TI[pass] = temp;
        }
    }
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl(TabInt *T, ElType X)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
{
    if (!IsFull(*T)){
        T->TI[GetLastIdx(*T) + 1] = X;
        ++T->Neff;
    }
}

/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl(TabInt *T, ElType *X)
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
{
    *X = T->TI[GetLastIdx(*T)];
    --T->Neff;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void GrowTab(TabInt *T, int num)
/* Proses : Menambahkan max element sebanyak num */
/* I.S. Tabel sudah terdefinisi */
/* F.S. Ukuran tabel bertambah sebanyak num */
{
    IdxType i;
    TabInt tabBaru;

    MakeEmpty(&tabBaru, (T->MaxEl + num));
    tabBaru.Neff = T->Neff;

    for (i = GetFirstIdx(*T); i <= GetLastIdx(*T); i++){
        tabBaru.TI[i] = T->TI[i];
    }
    Dealokasi(T);
    *T = tabBaru;
}

void ShrinkTab(TabInt *T, int num)
/* Proses : Mengurangi max element sebanyak num */
/* I.S. Tabel sudah terdefinisi, ukuran MaxEl > num, dan Neff < MaxEl - num. */
/* F.S. Ukuran tabel berkurang sebanyak num. */
{
    IdxType i;
    TabInt tabBaru;

    MakeEmpty(&tabBaru, T->MaxEl - num);
    tabBaru.Neff = T->Neff;

    for (i = GetFirstIdx(*T); i <= GetLastIdx(*T); i++){
        tabBaru.TI[i] = T->TI[i];
    }
    Dealokasi(T);
    *T = tabBaru;
}

void CompactTab(TabInt *T)
/* Proses : Mengurangi max element sehingga Neff = MaxEl */
/* I.S. Tabel tidak kosong */
/* F.S. Ukuran MaxEl = Neff */
{
    IdxType i;
    TabInt tabBaru;

    MakeEmpty(&tabBaru, T->Neff);
    tabBaru.Neff = T->Neff;

    for (i = GetFirstIdx(*T); i <= GetLastIdx(*T); i++){
        tabBaru.TI[i] = T->TI[i];
    }
    Dealokasi(T);
    *T = tabBaru;
}
