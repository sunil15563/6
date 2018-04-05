/* Write a Prolog program to implement reverse(List,ReversedList) that reverses lists. */
rev([],[]).
rev([H|T],R):-
	rev(T,Rv),
	append(Rv,[H],R).
reverse(L,R):-
	rev(L,R).
