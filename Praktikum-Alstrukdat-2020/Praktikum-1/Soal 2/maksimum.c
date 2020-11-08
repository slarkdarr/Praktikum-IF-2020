/*
13519107
Daffa Ananda Pratama Resyaly
24 Agustus 2020
Pengenalan C
Menampilkan Hello World di layar
*/

#include "stdio.h"

int main() {
	int a, b, c;
	
	scanf("%d %d %d", &a, &b, &c);
	
	printf("%d\n", (a > b) ? a : (b > c) ? b : c);
	
	return 0;
}
