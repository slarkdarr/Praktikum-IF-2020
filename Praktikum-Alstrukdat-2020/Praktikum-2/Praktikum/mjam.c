/*  13519107
    Daffa Ananda Pratama Resyaly
    03 September 2020
    Praktikum 02
    Program mjam
*/

#include <stdio.h>
#include "jam.h"

int main(){
    int i, N;
    long min = 86400, maks = -1;
    scanf("%d\n", &N);

    for (i = 1; i <= N; i++){
        JAM J1, J2;
        printf("[%d]\n", i);
        BacaJAM(&J1);
        BacaJAM(&J2);
        if (JAMToDetik(J1) < min){
            min = JAMToDetik(J1);
        }
        if (JAMToDetik(J1) > maks){
            maks = JAMToDetik(J1);
        }
        if (JAMToDetik(J2) < min){
            min = JAMToDetik(J2);
        }
        if (JAMToDetik(J2) > maks){
            maks = JAMToDetik(J2);
        }
        printf("%ld\n", (JLT(J1, J2)) ? Durasi(J1, J2) : Durasi(J2, J1));
    }
    TulisJAM(DetikToJAM(min));
    printf("\n");
    TulisJAM(DetikToJAM(maks));
    printf("\n");
    return 0;
}