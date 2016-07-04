
% Searches Y in X, both normally being chains or lists

strstr([], _, _) :-
	fail,
	!.

strstr(_, [], _).

strstr([H|T], [F|Q]) :-
	strstr(T, [F|Q]).

strstr([H|T], [H|Q]) :-
	strstr(T, Q, 1).

strstr([H|T], [H|Q], _) :-
	strstr(T, Q, 1).
