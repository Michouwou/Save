
toupper(X, X) :-
	X < 97.

toupper(X, X) :-
	X > 123.

toupper(X, Y) :-
	Y is X - 32.
