make_list(0, []) :- !.
make_list(N, [(_Size, _Height, _Position)|B]) :- N1 is N - 1, make_list(N1, B).

object1([(3, 2, A)|_]).
object1([_|Q]) :- object1(Q).

object2([(4, B, 1)|_]).
object2([_|Q]) :- object2(Q).

object3([(C, 2, 2)|_]).
object3([_|Q]) :- object3(Q).

object4([(3, 6, D)|_]).
object4([_|Q]) :- object4(Q).

object5([(1, E, 4)|_]).
object5([_|Q]) :- object5(Q).

object6([(F, 3, 5)|_]).
object6([_|Q]) :- object6(Q).

object7([(2, 3, G)|_]).
object7([_|Q]) :- object7(Q).

object8([(3, H, 3)|_]).
object8([_|Q]) :- object8(Q).

/*bag(0, [H|_], H).
bag(N, [_|Q], E) :- N1 is N - 1, bag(N1, [Q], E).*/

find_object3([_|T]) :- object3(T) -> print(T) ; find_object3(T).

resolve(A) :-
                make_list(8, A),
                object1(A),
                object2(A),
                object3(A),
                object4(A),
                object5(A),
                object6(A),
                object7(A),
                object8(A),
                find_object3(A).