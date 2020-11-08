#include <stdio.h>
#include "point.h"

int main(){
    /* KAMUS */
    POINT P1, P2;
    float dx, dy;

    /* ALGORITMA */
    
    printf("Masukkan nilai absis dan ordinat pertama: \n");
    BacaPOINT(&P1);
    printf("Masukkan nilai absis dan ordinat kedua: \n");
    BacaPOINT(&P2);
    printf("Titik P1 adalah titik ");
    TulisPOINT(P1);
    printf("Titik P2 adalah titik ");
    TulisPOINT(P2);

    /* Operasi relasional terhadap POINT */
    if (EQ(P1, P2)){
        printf("Koordinat titik pertama dan kedua sama\n");
    }
    if (NEQ(P1, P2)){
        pritnf("Koordinat titik pertama dan kedua berbeda\n");
    }
    if (IsOrigin(P1)){
        printf("P1 adalah titik origin\n");
    }
    if (IsOrigin(P2)){
        printf("P2 adalah titik origin\n");
    }
    if (IsOnSbX(P1)){
        printf("Titik P1 berada pada sumbu X\n");
    if (IsOnSbX(P2)){
        printf("Titik P2 berada pada sumbu X\n");
    }
    if (IsOnSbY(P1)){
        printf("Titik P1 berada pada sumbu Y\n");
    }
    if (IsOnSbY(P2)){
        printf("Titik P2 berada pada sumbu Y\n");
    }
    printf("Titik P1 berada pada Kuadran ke-%d", Kuadran(P1));
    printf("Titik P2 berada pada Kuadran ke-%d", Kuadran(P2));

    /* Operasi lain terhadap TYPE */
    
    printf("Koordinat titik P1 jika digeser satu satuan ke kanan menghasilkan titik ");
    TulisPOINT(NextX(P1));
    printf("\n");

    printf("Koordinat titik P2 jika digeser satu satuan ke kanan menghasilkan titik ");
    TulisPOINT(NextX(P2));
    printf("\n");
    
    print("Koordinat titik P1 jika digeser satu satuan ke kanan menghasilkan titik ");
    TulisPOINT(NextY(P1));
    printf("\n");

    print("Koordinat titik P2 jika digeser satu satuan ke kanan menghasilkan titik ");
    TulisPOINT(NextY(P2));
    printf("\n");
    
    printf("Geser sejajar sumbu x sebesar: ");
    scanf("%f", &dx);
    printf("Geser sejajar sumbu y sebesar: ");
    scanf("%f", &dy);
    
    printf("Setelah titik P1 digeser, koordinatnya menjadi: ");
    TulisPOINT(PlusDelta(P1, dx, dy));
    printf("\n");

    printf("Setelah titik P2 digeser, koordinatnya menjadi: ");
    TulisPOINT(PlusDelta(P2, dx, dy));
    printf("\n");
    
    printf("Apabila dicerminkan terhadap sumbu X, koordinat P1 menjadi: ");
    TulisPOINT(MirrorOf(P1, 1));
    printf("\n");

    printf("Apabila dicerminkan terhadap sumbu X, koordinat P2 menjadi: ");
    TulisPOINT(MirrorOf(P2, 1));
    printf("\n");
    
    printf("Apabila dicerminkan terhadap sumbu Y, koordinat P1 menjadi: ");
    TulisPOINT(MirrorOf(P1, 0));
    printf("\n");

    printf("Apabila dicerminkan terhadap sumbu Y, koordinat P2 menjadi: ");
    TulisPOINT(MirrorOf(P2, 0));
    printf("\n");

    printf("Jarak P1 ke titik origin (0,0) adalah: ");
    Jarak0(P1);

    printf("Jarak P2 ke titik origin (0,0) adalah: ");
    Jarak0(P2);

    printf("Panjang garis yang dibentuk P1 dan P2 adalah: ");
    Panjang(P1, P2);

}