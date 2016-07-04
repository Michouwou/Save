
% trims off elements in a list of lists

trim_double_list([], []).

trim_double_list([[]|T], Y) :-
        trim_double_list(T, Y),
        !.
        
trim_double_list([[H|T]|Q], [[H|T]|R]) :-
        trim_double_list(Q, R).