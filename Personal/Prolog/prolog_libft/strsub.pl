
% Copies N characters in Y from the chain/list X at character B

strsub([], _, _, _) :-
	fail,
	!.

strsub(_, _, 0, _).

strsub([H|T], 0, N, [H|Q]) :-
	N1 is N - 1,
	strsub(T, 0, N1, Q).

strsub([H|T], B, N, Y) :-
	B1 is B - 1,
	strsub(T, B1, N, Y).
