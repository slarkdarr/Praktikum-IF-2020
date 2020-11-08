#include <stdio.h>
#include "arraypos.h"

int main(){
    TabInt T;
    ElType X, maks, min, med;
    BacaIsi(&T);
    scanf("%d\n", &X);
    TulisIsiTab(T);
    printf("\n");
    if (Search1(T, X) == IdxUndef){
        printf("%d tidak ada\n", X);
    }
    else{
        printf("%d\n", Search1(T, X));
        MaxMin(T, &maks, &min);
        if (X == maks){
            printf("maksimum\n");
        }
        if (X == min){
            printf("minimum\n");
        }
        Sort(&T, true);
        if (NbElmt(T) % 2 == 0){
            med = Elmt(T, (NbElmt(T) / 2) - 1);
        }
        else if (NbElmt(T) % 2 == 1){
            med = Elmt(T, NbElmt(T) / 2);
        }
        if (X == med && med >= 0){
            printf("median\n");
        }    
    }
    return 0;
}