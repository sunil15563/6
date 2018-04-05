/* Write a Prolog program to implement sumlist(List,Sum) so that Sum is the sum of a given list of numbers List.  */
sumoflist(L):-
	sumlist(L,S),
	write('Sum of all the elements in the list= '),write(S).
