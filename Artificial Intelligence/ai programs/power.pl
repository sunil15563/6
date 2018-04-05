power(N,1,N).
power(N,P,A):-
	P>1,
	POW is P-1,
	power(N,POW,A1),
	A is A1*N.
	
