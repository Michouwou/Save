:- initialization consult([isalpha, isdigit]).

isalnum(X) :-
	isalpha(X).

isalnum(X) :-
	isdigit(X).
