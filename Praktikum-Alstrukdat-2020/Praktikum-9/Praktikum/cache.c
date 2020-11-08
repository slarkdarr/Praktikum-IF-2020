/*
13519107
Daffa Ananda Pratama Resyaly
05 November 2020
List Linier
Cache
*/

#include <stdio.h>
#include "listlinier.h"

int main(){
    List L;
    address P;
    int N, x, Q;

    scanf("%d\n", &N);
    for (int i = 1; i <= N; i++){
        P = Alokasi(i);
        InsertLast(&L, P);
    }
    
    scanf("%d\n", &Q);
    for (int i = 0; i < Q; i++){
        scanf("%d", &x);
        P = Search(L, x);
        if (P != Nil){
            DelP(&L, x);
            P = Alokasi(x);
            InsertFirst(&L, P);
            printf("hit ");
            PrintInfo(L);
            printf("\n");
        }
        else{
            DelLast(&L, &P);
            P = Alokasi(x);
            InsertFirst(&L, P);
            printf("miss ");
            PrintInfo(L);
            printf("\n");
        }
    }
    return 0;
}