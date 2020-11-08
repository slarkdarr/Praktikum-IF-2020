/*
13519107
Daffa Ananda Pratama Resyaly
24 Agustus 2020
Pengenalan C
Menampilkan Hello World di layar
*/

#include <stdio.h>

int isValid(int N) {
    // isValid bertipe integer.
    // isValid mengembalikan nilai 1 bila N merupakan bilangan ganjil positif dan 0 jika bukan.
    return (N > 0 && N % 2 == 1);
}

void GambarSpasi(int N, int i) {
    // Gambar spasi dari indeks j = 0 hingga N/2 - i - 1
    // Contoh: Jika N = 7 dan i = 2, spasi digambarkan dari indeks j = 0 hingga (7/2 - 2 - 1 = 0)

    /* KAMUS LOKAL */
    int j;

    /* ALGORITMA */
    for (j = 0; j < N/2 - i; j++) {
        printf(" ");
    }
}

void GambarBintang(int N, int i) {
    // Gambar bintang dari indeks j = N/2 - i hingga N/2 + i
    // Contoh: Jika N = 7 dan i = 2, bintang digambarkan dari indeks j = (7/2 - 2 = 1) hingga (7/2 + 2 = 5)

    /* KAMUS LOKAL */
    int j;
    
    /* ALGORITMA */
    for (j = N/2 - i; j < N/2 + i + 1; j++) {
        printf("*");
    }
}

void GambarBelahKetupat(int N) {
    // Gambar belah ketupat berukuran N * N

    /* KAMUS LOKAL */
    int i;

    /* ALGORITMA */
    for (i = 0; i < N/2; i++) {
        GambarSpasi(N, i);
        GambarBintang(N, i);
        // Tidak ada penggambaran spasi setelah N/2 + i + 1, langsung cetak newline / enter
        printf("\n");
    }
    for (i = N/2; i >= 0; i--) {
        GambarSpasi(N, i);
        GambarBintang(N, i);
        // Tidak ada penggambaran spasi setelah N/2 + i + 1, langsung cetak newline / enter
        printf("\n");
    }
}

int main () {
    int N;
    scanf("%d", &N);

    if (isValid(N)){
        GambarBelahKetupat(N);
    } else {
        printf("Masukan tidak valid\n");
    }
    return 0;
}