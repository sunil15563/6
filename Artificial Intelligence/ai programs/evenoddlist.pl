/* Write a Prolog program to implement two predicates evenlength(List) and oddlength(List) so that they  are  true  if their argument is a list of even or odd length respectively.*/ 
evenlength(L):-
	proper_length(L,S),
	0 is mod(S,2).
oddlength(L):-
	proper_length(L,S),
	1 is mod(S,2).
