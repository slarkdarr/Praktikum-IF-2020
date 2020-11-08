/*
13519107
Daffa Ananda Pratama Resyaly
24 Agustus 2020
Pengenalan C
Menampilkan Hello World di layar
*/

#include "stdio.h"
#include "stdbool.h"

bool IsWithinRange(float x, float min, float max) {
  return (min <= x && x <= max);
}

int main() {
  float totalNilai = 0;
  int jumlah = 0;
  int jumlahLulus = 0;
  int jumlahTidakLulus = 0;
  float x = 0;

  while(x != -999) {
    scanf("%f", &x);
    if(IsWithinRange(x, 2.75, 4)) {
      totalNilai = totalNilai + x;
      jumlahLulus = jumlahLulus + 1;
      jumlah = jumlah + 1;
    } else if(IsWithinRange(x, 0, 2.75)) {
      totalNilai = totalNilai + x;
      jumlahTidakLulus = jumlahTidakLulus + 1;
      jumlah = jumlah + 1;
    }
  }

  if (jumlah == 0) {
    printf("Tidak ada data\n");
  } else {
    printf("%d\n", jumlah);
    printf("%d\n", jumlahLulus);
    printf("%d\n", jumlahTidakLulus);
    printf("%.2f\n", totalNilai / jumlah);
  }
	
	return 0;
}
