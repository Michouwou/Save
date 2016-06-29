
% Copies the whole list X in Y

memcpy([], _).

memcpy([H|T], [H|Q]) :-
	memcpy(T, Q).
