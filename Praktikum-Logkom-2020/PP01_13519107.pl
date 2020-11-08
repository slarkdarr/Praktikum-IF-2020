/*** Bagian I ***/

/* Deklarasi Fakta */
/* pria(X) benar jika X adalah laki-laki */
pria(yoga).
pria(zaynmalik).
pria(padil).
pria(jovan).
pria(zunan).
pria(farras).
pria(william).
pria(smallfaris).
pria(babythajeb).
/* wanita(X) benar jika X adalah perempuan */
wanita(lisa).
wanita(asin).
wanita(rikha).
wanita(siti).
wanita(nurbaya).
/* usia(X,Y) benar jika X berusia Y */
usia(yoga,71).
usia(lisa,65).
usia(zaynmalik,56).
usia(asin,51).
usia(padil,58).
usia(rikha,40).
usia(jovan,24).
usia(zunan,30).
usia(farras,32).
usia(siti,26).
usia(william,28).
usia(nurbaya,24).
usia(smallfaris,6).
usia(babythajeb,3).
/* menikah(X,Y) benar jika X menikah dengan Y */
menikah(yoga,lisa).
menikah(lisa,yoga).
menikah(zaynmalik,asin).
menikah(asin,zaynmalik).
menikah(padil,rikha).
menikah(rikha,padil).
menikah(farras,siti).
menikah(siti,farras).
menikah(william,nurbaya).
menikah(nurbaya,william).
/* anak(X,Y) benar jika X adalah anak dari Y */
anak(jovan,yoga).
anak(jovan,lisa).
anak(zunan,yoga).
anak(zunan,lisa).
anak(farras,yoga).
anak(farras,lisa).
anak(siti,zaynmalik).
anak(siti,asin).
anak(william,zaynmalik).
anak(william,asin).
anak(nurbaya,padil).
anak(nurbaya,rikha).
anak(smallfaris,farras).
anak(smallfaris,siti).
anak(babythajeb,william).
anak(babythajeb,nurbaya).
/* saudara(X,Y) benar jika X adalah saudara kandung dari Y */
saudara(jovan,zunan).
saudara(jovan,farras).
saudara(zunan,jovan).
saudara(zunan,farras).
saudara(farras,jovan).
saudara(farras,zunan).
saudara(siti,william).
saudara(william,siti).

/* Deklarasi Aturan */
/* kakak(X,Y) benar jika X adalah kakak dari Y */
kakak(X,Y) :-
    saudara(X,Y),
    usia(X,U1),
    usia(Y,U2),
    U1 > U2.
/* keponakan(X,Y) benar jika X adalah keponakan dari Y */
keponakan(X,Y) :-
    anak(X,Z),
    saudara(Y,Z).
/* suami(X,Y) benar jika X adalah suami dari Y */
suami(X,Y) :-
    menikah(X,Y),
    pria(X).
/* sepupu(X,Y) benar jika X adalah sepupu dari Y */
sepupu(X,Y) :-
    anak(X,V),
    saudara(V,Z),
    anak(Y,Z).
/* mertua(X,Y) benar jika X adalah mertua dari Y */
mertua(X,Y) :-
    anak(Z,X),
    menikah(Y,Z).
/* bibi(X,Y) benar jika X adalah bibi dari Y */
bibi(X,Y) :-
    saudara(X,Y),
    wanita(X).
/* cucu(X,Y) benar jika X adalah cucu dari Y */
cucu(X,Y) :-
    anak(X,Z),
    anak(Z,Y).
/* anaksulung(X) benar jika X adalah anak paling tua */
anaksulung(X) :-
    kakak(X,_),
    \+kakak(_,X).
anaksulung(X) :-
    anak(X,_),
    \+saudara(X,_).
/* anakbungsu(X) benar jika X adalah anak paling muda */
anakbungsu(X) :-
    kakak(_,X),
    \+kakak(X,_).
anakbungsu(X) :-
    anak(X,_),
    \+saudara(X,_).


/*** Bagian II ***/

/** 1. Faktorial **/
/* Deklarasi Fakta */
faktorial(1,1).

/* Deklarasi Aturan */
faktorial(N,X) :-
    N >= 1,
    N1 is N-1,
    faktorial(N1,X1),
    X is X1*N.

/** 2. Greatest Common Divisor **/
/* Deklarasi Fakta */
gcd(A,0,A).

/* Deklarasi Aturan */
gcd(A,B,X) :-
    A >= B,
    A1 is A-B,
    gcd(A1,B,X).
gcd(A,B,X) :-
    A < B,
    B1 is B-A,
    gcd(B1,A,X).

/** 3. Power **/
/* Deklarasi Fakta */
power(_,0,1).

/* Deklarasi Aturan */
power(A,B,X) :-
    B >= 1,
    B1 is B-1,
    power(A,B1,X1),
    X is A*X1.

/** 4. Count Digit **/
/* Deklarasi Fakta */
countDigit(A,1) :- A < 10.

/* Deklarasi Aturan */
countDigit(A,X) :-
    A >= 10,
    A1 is A//10,
    countDigit(A1,X1),
    X is X1+1.

/** 5. Create Triangle **/
/* Deklarasi Fakta */
createTriangle(1) :- write('*').

/* Deklarasi Aturan */
createTriangle(X) :- X =< 0.

createTriangle(X) :-
    X > 0,
    count(1,X),
    Z = X-1,
    nl,
    createTriangle(Z).

count(X,Y) :-
    X =< Y,
    write('*'),
    X1 is X+1,
    count(X1,Y).

count(X,Y) :- X > Y.


/*** Bagian III ***/

/** 1. Queue **/

/* Push */
/* Deklarasi Fakta */
push(X,[],[X]).

/* Deklarasi Aturan */
push(X,[H|T],[H|Tresult]) :- push(X,T,Tresult).

/* Pop */
/* Deklarasi Fakta */
pop([_],[]).

/* Deklarasi Aturan */
pop([H|T],[H|Tresult]) :- pop(T,Tresult).

/* Front */
/* Deklarasi Fakta */
front([H|_],H).

/* Deklarasi Aturan */
front([H|_],Result) :- front(H,Result).

/* Back */
/* Deklarasi Fakta */
back([T],T).

/* Deklarasi Aturan */
back([_|T],Result) :- back(T,Result).

/** 2. Concatenate **/

/* Deklarasi Fakta */
take(_,0,[]).
take([],_,[]).

/* Deklarasi Aturan */
take([H|T1],N,[H|T2]) :-
    M is N-1,
    take(T1,M,T2).

/* Deklarasi Fakta */
conc([],L,L).

/* Deklarasi Aturan */
conc([H|T1],L,[H|T2]) :-
    conc(T1,L,T2).

/* Deklarasi Fakta */
concatenate([],L,_,_,L).
concatenate(L,[],_,_,L).
concatenate(_,_,0,0,[]).

/* Deklarasi Aturan */
concatenate(L1,L2,M,N,Ls) :-
    take(L1,M,Ls1),
    take(L2,N,Ls2),
    conc(Ls1,Ls2,Ls).

/** 3. Palindrom List **/

/* Deklarasi Fakta */
palindrom([]).
palindrom([_]).

/* Deklarasi Aturan */
palindrom([H|T]) :-
    conc(X,[H],T),  /* Menggunakan fungsi conc(L1,L2,Result) yang didefinisikan pada soal nomor 2 */
    palindrom(X).

/*** BONUS ***/

/** Ridge **/
/* Deklarasi Fakta */
ridge_check([],0).

/* Deklarasi Aturan */
ridge_check([H1,R,H2|T],N) :-
    R < H1,
    R < H2,
    ridge_check([H2|T],N1),
    N is N1+1.

ridge_check([H1,R,H2|T],N) :-
    R > H1,
    R > H2,
    ridge_check([H2|T],N1),
    N is N1+0.

/* Deklarasi Fakta */
len([],0).

/* Deklarasi Aturan */
len([_|T],N) :-
    len(T,N1),
    N is N1+1.

/* Deklarasi Aturan */
ridge(L) :-
    len(L,X),
    X > 2,
    ridge_check(L,N),
    write(N).