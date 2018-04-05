/* Write a prolog program to calculate the factorial of a given number. */
fact(0,1).
fact(N,F):-
	N>0,
	Num is N-1,
	fact(Num,F1),
	F is F1*N.
