max(A,B):-
(
 A=B -> write('both are equal');
 A>B -> (Z is A,write(Z));
 (Z is B,write(Z))
).
