
% Copies N characters from X to Y

memccpy([], _, _).

memccpy(_, _, 0).

memccpy([H|T], [H|Q], N) :-
	N1 is N - 1,
	memccpy(T, Q, N1).
