/* Write a Prolog program to implement max(X,Y,Max) so that Max is the greater of two numbers X and Y. */
max(X,Y,M):-
	X>Y,
	M=X
	;X<Y,
	M=Y.
