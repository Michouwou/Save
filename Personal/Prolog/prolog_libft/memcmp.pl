
memcmp([], [], _).

memcmp([H|T], [H|Q], X) :-
	X < 2.

memcmp([H|T], [H|Q], N) :-
	N1 is N - 1,
	memcmp(T, Q, N1).
