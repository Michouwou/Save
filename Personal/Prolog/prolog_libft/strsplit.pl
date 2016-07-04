
% strsplit/3 takes X a character string, C a separating character and stores in Y the result of the splitting of X by C

:- initialization consult(trim_double_list).

strsplit(X, C, Y) :-
        strsplit2(X, C, Y1),
        trim_double_list(Y1, Y),
        !.

strsplit2([], _, []).

strsplit2([H|T], C, [[H|Q]|R]) :-
        H\=C,
        strsplit2(T, C, [Q|R]).
        
strsplit2([C|T], C, [[]|R]) :-
        strsplit2(T, C, R, 1).
        
strsplit2([], _, [], _).

strsplit2([C|T], C, Y, _) :-
        strsplit2(T, C, Y, 1).

strsplit2([H|T], C, Y, _) :-
        H\=C,
        strsplit2([H|T], C, Y).