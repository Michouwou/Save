factorial(0, 1).

factorial(X, Y) :-
	Z is X - 1,
	factorial(Z, U),
	Y is U * X.
