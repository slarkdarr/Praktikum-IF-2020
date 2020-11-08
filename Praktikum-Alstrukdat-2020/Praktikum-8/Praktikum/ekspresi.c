/*
13519107
Daffa Ananda Pratama Resyaly
22 Oktober 2020
Ekspresi
*/

#include <stdio.h>
#include <math.h>
#include "stackt.h"
#include "mesintoken.h"

boolean EndToken = true;

boolean IsOperator(Token CT){
    if (CT.tkn == '+' || CT.tkn == '-' || CT.tkn == '*' || CT.tkn == '/' || CT.tkn == '^'){
        return true;
    }
    else{
        return false;
    }
}

int Hitung(int Op1, int Op2, Token CT){
    switch(CToken.tkn){
        case '+':
            return Op1 + Op2;
        case '-':
            return Op1 - Op2;
        case '*':
            return Op1 * Op2;
        case '/':
            return Op1 / Op2;
        case '^':
            return pow(Op1, Op2);
    }
}

int main(){
    Stack S;
    Token CToken;
    infotype Op1, Op2;
    CreateEmpty(&S);

    STARTTOKEN();

    if (IsEmpty(S)){
        printf("Ekspresi kosong\n");
    }
    else{
        while (!EndToken){
            if (IsOperator(CToken)){
                Pop(&S, &Op2);
                Pop(&S, &Op1);

                printf("%d %c %d\n", Op2, CToken.tkn, Op1);

                Push(&S, Hitung(Op1, Op2, CToken));
                printf("%d\n", Hitung(Op1, Op2, CToken));
            }

            else{
                Push(&S, CToken.val);
                printf("%d\n", CToken.val);
            }

            ADVTOKEN();
        }
        int hasil;
        Pop(&S, &hasil);
        printf("Hasil=%d\n", hasil);
    }
    return 0;
}