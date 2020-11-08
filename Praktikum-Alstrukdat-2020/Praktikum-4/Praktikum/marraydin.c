/* 13519107
    Daffa Ananda Pratama Resyaly
    17 September 2020
    Modul Tabel Integer
    Arraydin
*/

#include <stdio.h>
#include <stdlib.h>
#include "arraydin.h"
#include "boolean.h"

int main(){
    TabInt *T;
    int Q, op, maxel;
    IdxType i = 1;

    scanf("%d\n", &maxel);
    MakeEmpty(&T, maxel);
    BacaIsi(&T);
    scanf("%d\n", &Q);

    while (i <= Q){
        scanf("%d ", &op);
        ++i;
    }

    if (op == 1){
        if (IsFull(*T)){
            printf("array sudah penuh\n");
        }
        else{
            int num;
            scanf("%d\n", &num);
            AddAsLastEl(T, num);
            printf("%d ", T->MaxEl);
            TulisIsiTab(*T);
            printf("\n");
        }
    }
    if (op == 2){
        int num;
        scanf("%d\n", &num);
        GrowTab(T, num);
        printf("%d ", T->MaxEl);
        TulisIsiTab(*T);
        printf("\n");
    }
    if (op == 3){
        int num;
        scanf("%d\n", &num);
        if (T->MaxEl < num){
            printf("array terlalu kecil\n");
        }
        else{
            ShrinkTab(T, num);
            printf("%d ", T->MaxEl);
            TulisIsiTab(*T);
            printf("\n");
        }
    }
    if (op == 4){
        CompactTab(T);
        printf("%d ", T->MaxEl);
        TulisIsiTab(*T);
        printf("\n");
    }

    return 0;
}
