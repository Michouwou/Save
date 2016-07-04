sum(0, 0).

sum(X, Y) :-
	Z is X - 1,
	sum(Z, U),
	Y is X + U.
