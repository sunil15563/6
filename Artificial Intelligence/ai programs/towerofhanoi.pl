movetower(1,A,B,_):-
	write('Move top disk from '),
	write(A),
	write(' to '),
	write(B),
	nl.
movetower(N,A,B,C):-
	N>1,
	Num is N-1,
	movetower(Num,A,C,B),
	movetower(1,A,B,_),
	movetower(Num,C,B,A).

toh(N):-
	movetower(N,left,right,center).
