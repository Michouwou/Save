
% Transforms a string representation of a number into a number

:- initialization consult(strcat).

atoi(X, Y) :-
	atoi(X, Y, P).

atoi([], 0, 1).

atoi([45|T], Y, P) :-
	atoi(T, Y1, P),
	Y is Y1 * -1.

atoi([H|T], Y, P) :-
	atoi(T, Y1, P1),
	Y is (H - 48) * P1 + Y1,
	P is P1 * 10.

power(X, 0, 1).

power(X, 1, X).

power(X, Y, Z) :-
	Y1 is Y - 1,
	power(X, Y1, Z1),
	Z is Z1 * X. 
