result(R,X,Y):-		   R==0-> write(Y);
			not(R==0) -> write(R)

			   .

gcd(X,Y):-
	        X>Y -> R is mod(X,Y),
                  result(R,X,Y);

	X<Y -> gcd(Y,X) ;
	X==Y -> write(X)
.




