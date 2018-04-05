/* Write a prolog program to find the maximum of two numbers */
max(X,Y):-
	X>Y,
	write(X),write(' IS GREATER THAN '),write(Y)
	;X<Y,
	write(Y),write(' IS GREATER THAN '),write(X).
