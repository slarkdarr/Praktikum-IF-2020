/*
13519107
Daffa Ananda Pratama Resyaly
24 September 2020
ADT Matriks
*/

#include <stdio.h>
#include <math.h>
#include "matriks.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */              
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M)
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
{
    indeks i, j;
    NBrsEff(*M) = NB;
    NKolEff(*M) = NK;

    for (i = BrsMin; i < NB; i++){
       for (j = KolMin; j < NK; j++){
            Elmt(*M,i,j) = 0;
       }
    }
}

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j)
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
{
   return (i >= BrsMin && i <= BrsMax && j >= KolMin && j <= KolMax);
}

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terkecil M */
{
   return BrsMin;
}

indeks GetFirstIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terkecil M */
{
   return KolMin;
}

indeks GetLastIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terbesar M */
{
   return NBrsEff(M) - 1;
}

indeks GetLastIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terbesar M */
{
   return NKolEff(M) - 1;
}

boolean IsIdxEff (MATRIKS M, indeks i, indeks j)
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
{
   return (i >= BrsMin && i <= GetLastIdxBrs(M) && j >= KolMin && j <= GetLastIdxKol(M));
}

ElType GetElmtDiagonal (MATRIKS M, indeks i)
/* Mengirimkan elemen M(i,i) */
{
   return Elmt(M,i,i);
}

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl)
/* Melakukan assignment MHsl  MIn */
{
   indeks i, j;

   MakeMATRIKS(NBrsEff(MIn),NKolEff(MIn),MHsl);

   for (i = GetFirstIdxBrs(MIn); i <= GetLastIdxBrs(MIn); i++){
      for (j = GetFirstIdxKol(MIn); j <= GetLastIdxKol(MIn); j++){
         Elmt(*MHsl,i,j) = Elmt(MIn,i,j);
      }
   }
}

/* ********** KELOMPOK BACA/TULIS ********** */ 
void BacaMATRIKS (MATRIKS * M, int NB, int NK)
/* I.S. IsIdxValid(NB,NK) */ 
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
{
   indeks i, j;
   MakeMATRIKS(NB,NK,M);

   for (i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++){
      for (j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++){
         scanf("%d", &Elmt(*M,i,j));
      }
   }
}

void TulisMATRIKS (MATRIKS M)
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{
   indeks i, j;

   for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++){
      for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++){
         printf("%d", Elmt(M,i,j));
         if (j != GetLastIdxKol(M)){
            printf(" ");
         }
         else{
            if (i != GetLastIdxBrs(M)){
               printf("\n");
            }
         }
      }
   }
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */                                  
MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M1  berukuran sama dengan M2 */
/* Mengirim hasil penjumlahan matriks: M1 + M2 */ 
{
   indeks i, j;
   MATRIKS MRes;

   MakeMATRIKS(NBrsEff(M1),NKolEff(M1),&MRes);

   for (i = GetFirstIdxBrs(MRes); i <= GetLastIdxBrs(MRes); i++){
      for (j = GetFirstIdxKol(MRes); j <= GetLastIdxKol(MRes); j++){
         Elmt(MRes,i,j) = Elmt(M1,i,j) + Elmt(M2,i,j);
      }
   }
   return MRes;
}

MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M berukuran sama dengan M */
/* Mengirim hasil pengurangan matriks: salinan M1 – M2 */ 
{
   indeks i, j;
   MATRIKS MRes;

   MakeMATRIKS(NBrsEff(M1),NKolEff(M1),&MRes);

   for (i = GetFirstIdxBrs(MRes); i <= GetLastIdxBrs(MRes); i++){
      for (j = GetFirstIdxKol(MRes); j <= GetLastIdxKol(MRes); j++){
         Elmt(MRes,i,j) = Elmt(M1,i,j) - Elmt(M2,i,j);
      }
   }
   return MRes;
}

MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian matriks: salinan M1 * M2 */
{
   indeks i, j, k;
   MATRIKS MRes;

   MakeMATRIKS(NBrsEff(M1),NKolEff(M2),&MRes);

   for (i = GetFirstIdxBrs(M1); i <= GetLastIdxBrs(M1); i++){
      for (j = GetFirstIdxKol(M2); j <= GetLastIdxKol(M2); j++){
         for (k = GetFirstIdxKol(M1); k <= GetLastIdxKol(M1); k++){
            Elmt(MRes,i,j) += Elmt(M1,i,k) * Elmt(M2,k,j);
         }
      }
   }
   return MRes;
}

MATRIKS KaliKons (MATRIKS M, ElType X)
/* Mengirim hasil perkalian setiap elemen M dengan X */
{
   indeks i, j;
   MATRIKS MRes;

   MakeMATRIKS(NBrsEff(M),NKolEff(M),&MRes);

   for (i = GetFirstIdxBrs(MRes); i <= GetLastIdxBrs(MRes); i++){
      for (j = GetFirstIdxKol(MRes); j <= GetLastIdxKol(MRes); j++){
         Elmt(MRes,i,j) = Elmt(M,i,j) * X;
      }
   }
   return MRes;
}

void PKaliKons (MATRIKS * M, ElType K)
/* I.S. M terdefinisi, K terdefinisi */
/* F.S. Mengalikan setiap elemen M dengan K */
{
   MATRIKS MRes = KaliKons(*M,K);
   *M = MRes;
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQ (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2) 
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
{
   indeks i, j;
   boolean eq = true;

   if (NBElmt(M1) == NBElmt(M2)){
      for (i = GetFirstIdxBrs(M1); i <= GetLastIdxBrs(M2); i++){
         for (j = GetFirstIdxKol(M1); j <= GetLastIdxKol(M2); j++){
            if (Elmt(M1,i,j) != Elmt(M2,i,j)){
               eq = false;
            }
         }
      }
   }
   else{
      eq = false;
   }
   return eq;
}

boolean NEQ (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 tidak sama dengan M2 */
{
   return !EQ(M1,M2);
}

boolean EQSize (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */
{
   return (NBrsEff(M1) == NBrsEff(M2) && NKolEff(M1) == NKolEff(M2));
}

/* ********** Operasi lain ********** */
int NBElmt (MATRIKS M)
/* Mengirimkan banyaknya elemen M */
{
   indeks i, j;
   int sum = 0;

   for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++){
      for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++){
         ++sum;
      }
   }
   return sum;
}

/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar (MATRIKS M)
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
{
   return (NBrsEff(M) == NKolEff(M));
}

boolean IsSimetri (MATRIKS M)
/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M) 
   dan untuk setiap elemen M, M(i,j)=M(j,i) */
{
   indeks i, j;
   boolean simetri = true;

   for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++){
      for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++){
         if (Elmt(M,i,j) != Elmt(M,j,i)){
            simetri = false;
         }
      }
   }
   return simetri;
}

boolean IsSatuan (MATRIKS M)
/* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan 
   setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */ 
{
   indeks i, j;
   boolean satuan = false;

   if (IsBujurSangkar(M)){
      for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++){
         for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++){
            if (i != j && Elmt(M,i,i) == 1 && Elmt(M,i,j) == 0){
               satuan = true;
            }
         }
      }
   }
   return satuan;
}

boolean IsSparse (MATRIKS M)
/* Mengirimkan true jika M adalah matriks sparse: mariks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */ 
{
   indeks i, j;
   int notzero = 0;
   
   for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++){
      for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++){
         if (Elmt(M,i,j) != 0){
            ++notzero;
         }
      }
   }
   return (notzero <= (0.2 * NBElmt(M)));
}

MATRIKS Inverse1 (MATRIKS M)
/* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
{
   return KaliKons(M, -1);
}

float Determinan (MATRIKS M)
/* Prekondisi: IsBujurSangkar(M) */
/* Menghitung nilai determinan M */
{
    indeks i, j;
    int N = NBrsEff(M);
    float Mtemp[N][N];

    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            Mtemp[i][j] = Elmt(M, i, j);
        }
    }

    float result = 1;
    int swapped = 0;

    while (N > 0){
        boolean swap = false;
        i = 0;
        if (Mtemp[N-1][N-1] == 0){
            while (i < (N-1) && (!swap)){
                if (Mtemp[i][N-1] == 0){
                    i++;
                } else {
                    swap = true;
                }
            }
        }
        if (i == (N-1) && (N > 1)){
            return 0;
        } 
        else if (swap){
            for(j = 0; j < N; j++){
                float temp = Mtemp[N-1][j];
                Mtemp[N-1][j] = Mtemp[i][j];
                Mtemp[i][j] = temp;
            }
        }
        for (i = 0; i < (N-1); i++){
            for(j=0; j<N; j++){
                Mtemp[i][j] -= Mtemp[N-1][j]*(Mtemp[i][N-1]/Mtemp[N-1][N-1]);
            }
        }
        result *= Mtemp[N-1][N-1];

        int swapped;

        if (swap){
           swapped = (swapped + 1) % 2;
        }
        else{
           swapped = swapped % 2;
        }
        N--;
    }
    float finalresult;
    if (swapped == 0){
       finalresult = result * 1.0f;
    }
    else{
       finalresult = result * -1.0f;
    }
    if (finalresult < 1 && finalresult > -1){
       return 0.0f;
    }
    else{
       return finalresult;
    }
}

void PInverse1 (MATRIKS * M)
/* I.S. M terdefinisi */
/* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
{
   MATRIKS MRes = Inverse1(*M);
   *M = MRes;
}

void Transpose (MATRIKS * M)
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
{
   indeks i, j;
   MATRIKS MRes;

   MakeMATRIKS(NBrsEff(*M),NKolEff(*M),&MRes);

   for (i = GetFirstIdxBrs(MRes); i <= GetLastIdxBrs(MRes); i++){
      for (j = GetFirstIdxKol(MRes); j <= GetLastIdxKol(MRes); j++){
         Elmt(MRes,i,j) = Elmt(*M,j,i);
      }
   }
   *M = MRes;
}

/* Operasi berbasis baris dan per kolom */

float RataBrs (MATRIKS M, indeks i)
/* Menghasilkan rata-rata dari elemen pada baris ke-i */
/* Prekondisi: i adalah indeks baris efektif dari M */
{
    indeks j;
    float sum = 0;
    int count = 0;
    
    for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++){
        sum += Elmt(M,i,j);
        count += 1;
    }
    return (sum / count);
}

float RataKol (MATRIKS M, indeks j)
/* Menghasilkan rata-rata dari elemen pada kolom ke-j */
/* Prekondisi: j adalah indeks kolom efektif dari M */
{
    indeks i;
    float sum = 0;
    int count = 0;

    for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++){
        sum += Elmt(M,i,j);
        count += 1;
    }
    return (sum / count);
}

void MaxMinBrs (MATRIKS M, indeks i, ElType * max, ElType * min)
/* I.S. i adalah indeks baris efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada baris i dari M
           min berisi elemen minimum pada baris i dari M */
{
    indeks j;
    ElType mini = Elmt(M,i,GetFirstIdxKol(M));
    ElType maks = Elmt(M,i,GetFirstIdxKol(M));

    for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++){
        if (Elmt(M,i,j) < mini){
            mini = Elmt(M,i,j);
        }
        if (Elmt(M,i,j) > maks){
            maks = Elmt(M,i,j);
        }
    }
    *min = mini;
    *max = maks;
}

void MaxMinKol (MATRIKS M, indeks j, ElType * max, ElType * min)
/* I.S. j adalah indeks kolom efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada kolom j dari M
           min berisi elemen minimum pada kolom j dari M */
{
    indeks i;
    ElType mini = Elmt(M,GetFirstIdxBrs(M),j);
    ElType maks = Elmt(M,GetFirstIdxBrs(M),j);
    
    for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++){
        if (Elmt(M,i,j) < mini){
            mini = Elmt(M,i,j);
        }
        if (Elmt(M,i,j) > maks){
            maks = Elmt(M,i,j);
        }
    }
    *min = mini;
    *max = maks;
}

int CountXBrs (MATRIKS M, indeks i, ElType X)
/* Menghasilkan banyaknya kemunculan X pada baris i dari M */
{
    indeks j;
    int found = 0;

    for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++){
        if (Elmt(M,i,j) == X){
            found += 1;
        }
    }
    return found;
}

int CountXKol (MATRIKS M, indeks j, ElType X)
/* Menghasilkan banyaknya kemunculan X pada kolom j dari M */
{
    indeks i;
    int found = 0;

    for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++){
        if (Elmt(M,i,j) == X){
            found += 1;
        }
    }
    return found;
}
