:- initialization consult(memset).

bzero(X, N) :-
	memset(X, N, 0).
