/*Write a Prolog program to implement palindrome(List).*/
same([],[]).
same([H1|T1],[H2|T2]):-
	H1 = H2,
	same(T1, T2).
rev([],[]).
rev([H|T],R):-
	rev(T,Rv),
	append(Rv,[H],R).
palindrome(L):-
	rev(L,R),
	same(L,R),
		write('List is Palindrome')
	;
		write('List is not Palindrome').
