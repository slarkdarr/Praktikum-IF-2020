/*
13519107
Daffa Ananda Pratama Resyaly
Vektor
*/

/* File: vector.c */
/* Tanggal: 29 Agustus 2020 */

#include "vector.h"

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk VECTOR *** */
VECTOR MakeVector(float x, float y)
/* Membentuk sebuah VECTOR dengan komponen absis x dan
   komponen ordinat y */
{
    VECTOR V;
    AbsisComponent(V) = x;
    OrdinatComponent(V) = y;
    return V;
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void TulisVector(VECTOR v)
/* Nilai v ditulis ke layar dengan format "<X,Y>"
   tanpa spasi, enter, atau karakter lain di depan, belakang, atau di antaranya
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. v terdefinisi */
/* F.S. v tertulis di layar dengan format "<X,Y>" */
{
    printf("<%.2f,%.2f>", AbsisComponent(v), OrdinatComponent(v));
}

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
float Magnitude(VECTOR v)
/* Menghasilkan magnitudo dari vector, yakni sqrt(v.x^2+v.y^2) */
{
    return (sqrt(AbsisComponent(v)*AbsisComponent(v) + OrdinatComponent(v)*OrdinatComponent(v)));
}

VECTOR Add(VECTOR a, VECTOR b)
/* Menghasilkan sebuah vector yang merupakan hasil a + b.
   Komponen absis vector hasil adalah vector pertama
   ditambah vector kedua, begitu pula dengan ordinatnya */
{
    VECTOR c;
    AbsisComponent(c) = AbsisComponent(a) + AbsisComponent(b);
    OrdinatComponent(c) = OrdinatComponent(a) + OrdinatComponent(b);
    return c;
}

VECTOR Substract(VECTOR a, VECTOR b)
/* Menghasilkan sebuah vector yang merupakan hasil a - b.
   Komponen absis vector hasil adalah vector pertama
   dikurangi vector kedua, begitu pula dengan ordinatnya */
{
    VECTOR c;
    AbsisComponent(c) = AbsisComponent(a) - AbsisComponent(b);
    OrdinatComponent(c) = OrdinatComponent(a) - OrdinatComponent(b);
    return c;
}

float Dot(VECTOR a, VECTOR b)
/* Menghasilkan perkalian dot vector, yakni a.x * b.x + a.y * b.y */
{
    float perkalianabsis = AbsisComponent(a) * AbsisComponent(b);
    float perkalianordinat = OrdinatComponent(a) * OrdinatComponent(b);
    return perkalianabsis + perkalianordinat;
}

VECTOR Multiply(VECTOR v, float s)
/* Menghasilkan perkalian skalar vector dengan s, yakni
   (s * a.x, s * a.y) */
{
    VECTOR c;
    AbsisComponent(c) = s * AbsisComponent(v);
    OrdinatComponent(c) = s * OrdinatComponent(v);
    return c;
}
