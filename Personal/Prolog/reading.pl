
read_file(X, Y) :-
        open(X, read, Z),
        read_multiple(Z, Y),
        close(Z).

read_multiple(I, [B|T]) :-
        read(I, B),
        B\=end_of_file ->
        read_multiple(I, T);
        !
        .