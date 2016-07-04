
read_file(X, Y) :-
        open(X, read, Z),
        read(Z, Y).