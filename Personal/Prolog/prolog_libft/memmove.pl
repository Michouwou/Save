
% Copies N characters from X to Y

memmove(_, _, 0).

memmove([], _, _).

memmove([H|T], [H|Q], N) :-
	N1 is N - 1,
	memmove(T, Q, N1).
