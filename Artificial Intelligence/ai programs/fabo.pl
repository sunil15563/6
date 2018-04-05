fabo(N,T,A,B):-

(	N>T -> T1 is T+1,
	C is A+B,
	A1 is B,
	B1 is C,
	N1 is N,
	fabo(N1,T1,A1,B1)
);
 N=T ->	C is A+B,
 write(C)

.

