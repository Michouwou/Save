
tolower(X, X) :-
	X < 65.

tolower(X, X) :-
	X > 90.

tolower(X, Y) :-
	Y is X + 32.
