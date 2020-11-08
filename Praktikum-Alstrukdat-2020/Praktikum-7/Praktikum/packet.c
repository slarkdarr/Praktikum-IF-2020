/*
13519107
Daffa Ananda Pratama Resyaly
08 Oktober
Packet
*/

#include "prioqueuechar.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
    int N;
    scanf("%d", &N);
    PrioQueueChar package;
    MakeEmpty(&package, N);
    int i, sec = 1;
    while (sec <= N){
        infotype temp, out;
        int current = 0;
        scanf("%d %c", &Prio(temp), &Info(temp));
        Enqueue(&package, temp);
        while (Prio(InfoHead(package)) == current + 1){
            Dequeue(&package, &out);
            printf("%d %c\n", sec, out.info);
            current++;
        }
        sec++;
    }
}