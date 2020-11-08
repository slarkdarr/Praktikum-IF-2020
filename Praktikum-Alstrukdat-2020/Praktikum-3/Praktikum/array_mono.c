/*
13519107
Daffa Ananda Pratama Resyaly
Array Monotonik
*/

#include <stdio.h>
#include "arraypos.h"

int main(){
    TabInt T;
    BacaIsi(&T);
    TabInt asc = T, dsc = T;
    Sort(&asc, false);
    Sort(&dsc, false);

    if (IsEQ(T, asc) && IsEQ(T, dsc)){
        printf("Array monotonik statik\n");
    }
    else{
        if (IsEQ(T, asc)){
            printf("Array monotonik tidak mengecil\n");
        }
        else if (IsEQ(T, dsc)){
            printf("Array monotonik tidak membesar\n");
        }
        else{
            printf("Array tidak monotonik\n");
        }
    }
    return 0;
}
