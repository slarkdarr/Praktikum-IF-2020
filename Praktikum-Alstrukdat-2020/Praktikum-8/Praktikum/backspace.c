/*
13519107
Daffa Ananda Pratama Resyaly
22 Oktober 2020
Ekspresi
*/

#include <stdio.h>
#include "stackt.h"

int main(){
    Stack A, B;
    int N, M;
    infotype X, a, b;

    CreateEmpty(&A);
    CreateEmpty(&B);

    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++){
        scanf("%d", &X);
        if (X != 0){
            Push(&A, X);
        }
        else if (!IsEmpty(A)){
            Pop(&A, &X);
        }
    }
    for (int i = 0; i < M; i++){
        scanf("%d", &X);
        if (X != 0){
            Push(&A, X);
        }
        else if (!IsEmpty(B)){
            Pop(&B, &X);
        }
    }
    while (!(IsEmpty(A) || IsEmpty(B))){
        Pop(&A, &a);
        Pop(&B, &b);
        if (a != b){
            Push(&B, b);
            break;
        }
    }
    if (IsEmpty(A) && IsEmpty(B)){
        print("Sama\n");
    }
    else{
        printf("Tidak sama\n");
    }
    return 0;
}