
% Concatenates two lists or strings. Z will contain X + Y

strcat([], [], _).

strcat([H|T], Y, [H|Q]) :-
	strcat(T, Y, Q).

strcat([], [H|T], [H|Q]) :-
	strcat([], T, Q).
