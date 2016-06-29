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


