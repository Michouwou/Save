
strlen([], N) :-
	N is 0.

strlen([H|T], N) :-
	strlen(T, N1),
	N is N1 + 1.
