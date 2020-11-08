/*
13519107
Daffa Ananda Pratama Resyaly
24 Agustus 2020
Pengenalan C
Menampilkan Hello World di layar
*/

#include "stdio.h"

int main() {
	float c;
	char tipe;
	
	scanf("%f %c", &c, &tipe);
	
	printf("%.2f\n", (tipe == 'R') ? c*4/5 : (tipe == 'F') ? c*9/5+32 : c+273.15);
	
	return 0;
}
