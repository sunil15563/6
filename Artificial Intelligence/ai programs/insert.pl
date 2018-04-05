/* Write a prolog program, insert_nth(item, n, into_list, result) that asserts that result is the list into_list with item inserted as the n’th element into every list at all levels */
insert(Item,N,L,R):-
	nth0(N,R,Item,L).
