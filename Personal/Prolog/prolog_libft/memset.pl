
% Sets the memory from 0 to N to the character C.

memset(_, 0, C).
	

memset([C|T], N, C) :-
	N1 is N - 1,
	memset(T, N1, C).
