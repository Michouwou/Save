
:- initialization main.

main :-
	read(X),
	isPair(X),
	halt.

isPair(X) :- not(integer(X)), write('not a number'), nl.

isPair(X) :- pair(X), write('pair.'), nl.

isPair(X) :- impair(X), write('impair.'), nl.

pair(X) :- mod(X, 2) =:= 0.

impair(X) :- mod(X, 2) =:= 1.

prefix([], _).

prefix([X|L], [X|M]) :- 
	prefix(L, M). 

search([], X) :- 
	fail.

search([H|T], X) :-
	X=H.

search([H|T], X) :-
	search(T, X).

search_list([], X) :-
	fail.

search_list(Q, X) :-
	X=Q.

search_list([_|T], X) :-
	search_list(T, X).

search_list(Q, X) :-
	prefix(X, Q).

display([]).

display([H|T]) :-
	write(H),
	nl,
	display(T).

copy(X, X).

display_rev([]).

display_rev([H|T]) :-
	display_rev(T),
	write(H),
	nl.
