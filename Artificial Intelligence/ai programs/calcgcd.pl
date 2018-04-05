/* Write a Prolog program to implement GCD of two numbers */
gcd(A,0):-
	write('GCD of the two numbers is:- '),write(A).
gcd(A,B):-
	B>A,
	gcd(B,A)
	;
	K is mod(A,B),
	gcd(B,K).
calcgcd(X,Y):-
	gcd(X,Y).
