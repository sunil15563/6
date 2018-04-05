/* Write a Prolog program to implement maxlist(List,Max) so that Max is the greatest number in the list of numbers List. */
max([],Max):-
	write('Maximum in the list:- '),write(Max).
max([H|T],Max):-
	H>Max,
	M=H,
	max(T,M)
	;
	max(T,Max).
maxlist(L):-
	max(L,0).
