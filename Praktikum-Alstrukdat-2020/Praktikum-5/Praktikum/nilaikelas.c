/*
13519107
Daffa Ananda Pratama Resyaly
24 September 2020
Matriks -- Nilai Kelas
*/

#include <stdio.h>
#include "matriks.h"

void TulisNilaiX (MATRIKS M, indeks j, ElType X)
{
    indeks i;
    
    printf("[");
    for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++){
        if (Elmt(M,i,j) == X){
            printf("%d", i);
            if (i != GetLastIdxBrs(M)){
                printf(",");
            }
            else{
                printf("]");
            }
        }
    }
}

void TulisStatistikMhs (MATRIKS M, indeks i)
{
    indeks j;
    ElType min, max;
    float rata = RataBrs(M,i);
    MaxMinBrs(M,i,&max,&min);

    printf("[%d] %.2f %d %d", i, rata, max, min);
}

void TulisStatistikMK (MATRIKS M, indeks j)
{
    indeks i;
    ElType min, max;
    float rata = RataKol(M,j);
    MaxMinKol(M,j,&max,&min);

    int tinggi = CountXKol(M,j,max);
    int rendah = CountXKol(M,j,min);

    printf("[%d] %.2f", j, rata);

    printf("[%d %d", max, tinggi);
    TulisNilaiX(M,j,max);
    printf("] ");

    printf("[%d %d", min, rendah);
    TulisNilaiX(M,j,min);
    printf("]");
}

int main(){
    MATRIKS MNilai;
    indeks i, j;
    int n, m;

    scanf("%d\n%d", &m, &n);
    MakeMATRIKS(n,m,&MNilai);
    BacaMATRIKS(&MNilai,n,m);

    printf("STATISTIK PER MAHASISWA\n");
    for (i = GetFirstIdxBrs(MNilai); i <= GetLastIdxBrs(MNilai); i++){
        TulisStatistikMhs(MNilai,i);
        if (i != GetLastIdxBrs(MNilai)){
            printf("\n");
        }
    }

    for (j = GetFirstIdxKol(MNilai); j <= GetLastIdxKol(MNilai); j++){
        TulisStatistikMK(MNilai,j);
        if (j != GetLastIdxKol(MNilai)){
            printf("\n");
        }
    }
    return 0;
}
