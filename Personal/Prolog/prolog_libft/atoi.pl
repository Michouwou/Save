
% Transforms a string representation of a number into a number

:- initialization consult(strcat).

atoi([], 0).

atoi(["-"|T], X) :-
	atoi(T, X1),
	X is -X1,
	!.

atoi([H|T], X) :-
	atoi(T, X1),
	ten_p(Y, X1),
	X2 is H - 48,
	X is X2 * Y + X1.

% X becomes the smallest power of ten superior to Y 

ten_p(X, Y) :-
	get_divide(X1, Y),
	X2 is 10,
	power(X2, X1, X).

get_divide(X, Y) :-
	Y < 1,
	X is 1.

get_divide(X, Y) :-
	get_divide(X1, Y),
	X is X1 + 1.

power(X, 0, X).

power(X, Y, Z) :-
	Y1 is Y - 1,
	power(X, Y1, Z1),
	Z is Z1 * X. 
