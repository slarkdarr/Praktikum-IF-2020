#include <stdio.h>
#include "boolean.h"
#include "jam.h"

int main(){
    /* KAMUS */
    JAM J1, J2;
    int N1, N2;

    /* ALGORITMA */
    printf("Masukkan waktu pertama: ");
    BacaJAM(&J1);
    TulisJAM(J1);
    
    printf("Masukkan waktu kedua: ");
    BacaJAM(&J2);
    TulisJAM(J2);

    /* ***Operasi terhadap TYPE*** */
    if JEQ(J1, J2){
        printf("Waktu pertama sama dengan waktu kedua\n");
    }
    if JNEQ(J1, J2){
        printf("Waktu pertama tidak sama dengan waktu kedua\n");
    }
    if JLT(J1, J2){
        printf("Waktu pertama lebih awal dibanding waktu kedua\n");
    }
    if JGT(J1, J2){
        printf("Waktu pertama lebih lambat dibanding waktu kedua\n");
    }

    /* ***Operator aritmatika JAM**** */
    printf("Satu detik setelah waktu pertama adalah pukul: ");
    NextDetik(J1);

    printf("Satu detik setelah waktu kedua adalah pukul: ");
    NextDetik(J2);
    
    printf("Masukkan jumlah detik yang ingin ditambahkan: ");
    scanf("%d", &N1);
    printf("%d detik setelah waktu pertama adalah pukul: ", N1);
    NextNDetik(J1, N1);
    printf("%d detik setelah waktu kedua adalah pukul: ", N2);
    NextNDetik(J2, N1);
    
    printf("Satu detik sebelum waktu pertama adalah pukul: ");
    PrevDetik(J1);
    printf("Satu detik sebelum waktu kedua adalah pukul: ");
    PrevDetik(J2);
    
    printf("Masukkan jumlah detik yang ingin dikurangkan: ");
    scanf("%d", &N2);
    printf("%d detik sebelum waktu pertama adalah pukul: ", N1);
    NextNDetik(J1, N2);
    printf("%d detik sebelum waktu kedua adalah pukul: ", N2);
    NextNDetik(J2, N2);

    printf("Durasi antara waktu pertama dan kedua adalah: ");
    Durasi(J1, J2);
}