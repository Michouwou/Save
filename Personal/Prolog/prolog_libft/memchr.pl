
memchr(_, _, 0, X) :-
	!,
	fail.

memchr([], _, _, X) :-
	fail.

memchr([T|H], T, N, [T|H]).

memchr([T|H], C, N, X) :-
	N1 is N - 1,
	memchr(H, C, N1, X).
