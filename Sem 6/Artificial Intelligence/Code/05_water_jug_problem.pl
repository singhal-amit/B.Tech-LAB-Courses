:- dynamic visited_state/2. % Declare visited_state as dynamic

% Define a predicate that takes user input and starts the process
fill(X, Y) :-
    retractall(visited_state(_, _)), % Clear visited states before starting
    assertz(visited_state(X, Y)),
    state(X, Y, [(X, Y)]). % Pass an empty list to collect steps

% Goal State: 4-Litre jug should have exactly 2 Litres
state(2, Y, Steps) :-
    format("Goal reached: (2, ~d)\n", [Y]),
    print_steps(Steps), % Print the steps
    !. % Stop further execution

% Fill the 4-Litre Jug
state(X, Y, Steps) :-
    X < 4,
    \+ visited_state(4, Y),
    assertz(visited_state(4, Y)),
    format("Fill 4-Litre Jug: (~d, ~d) --> (4, ~d)\n", [X, Y, Y]),
    state(4, Y, [(X, Y) | Steps]). % Record the current state in the steps

% Fill the 3-Litre Jug
state(X, Y, Steps) :-
    Y < 3,
    \+ visited_state(X, 3),
    assertz(visited_state(X, 3)),
    format("Fill 3-Litre Jug: (~d, ~d) --> (~d, 3)\n", [X, Y, X]),
    state(X, 3, [(X, Y) | Steps]). % Record the current state in the steps

% Empty the 4-Litre Jug
state(X, Y, Steps) :-
    X > 0,
    \+ visited_state(0, Y),
    assertz(visited_state(0, Y)),
    format("Empty 4-Litre Jug: (~d, ~d) --> (0, ~d)\n", [X, Y, Y]),
    state(0, Y, [(X, Y) | Steps]). % Record the current state in the steps

% Empty the 3-Litre Jug
state(X, Y, Steps) :-
    Y > 0,
    \+ visited_state(X, 0),
    assertz(visited_state(X, 0)),
    format("Empty 3-Litre Jug: (~d, ~d) --> (~d, 0)\n", [X, Y, X]),
    state(X, 0, [(X, Y) | Steps]). % Record the current state in the steps

% Pour from 3-Litre to 4-Litre (until full)
state(X, Y, Steps) :-
    X + Y >= 4,
    Y > 0,
    NEW_Y is Y - (4 - X),
    \+ visited_state(4, NEW_Y),
    assertz(visited_state(4, NEW_Y)),
    format("Pour from 3-Litre to 4-Litre: (~d, ~d) --> (4, ~d)\n", [X, Y, NEW_Y]),
    state(4, NEW_Y, [(X, Y) | Steps]). % Record the current state in the steps

% Pour from 4-Litre to 3-Litre (until full)
state(X, Y, Steps) :-
    X + Y >= 3,
    X > 0,
    NEW_X is X - (3 - Y),
    \+ visited_state(NEW_X, 3),
    assertz(visited_state(NEW_X, 3)),
    format("Pour from 4-Litre to 3-Litre: (~d, ~d) --> (~d, 3)\n", [X, Y, NEW_X]),
    state(NEW_X, 3, [(X, Y) | Steps]). % Record the current state in the steps

% Pour all from 3-Litre to 4-Litre
state(X, Y, Steps) :-
    X + Y < 4,
    Y > 0,
    NEW_X is X + Y,
    \+ visited_state(NEW_X, 0),
    assertz(visited_state(NEW_X, 0)),
    format("Pour all from 3-Litre to 4-Litre: (~d, ~d) --> (~d, 0)\n", [X, Y, NEW_X]),
    state(NEW_X, 0, [(X, Y) | Steps]). % Record the current state in the steps

% Pour all from 4-Litre to 3-Litre
state(X, Y, Steps) :-
    X + Y < 3,
    X > 0,
    NEW_Y is X + Y,
    \+ visited_state(0, NEW_Y),
    assertz(visited_state(0, NEW_Y)),
    format("Pour all from 4-Litre to 3-Litre: (~d, ~d) --> (0, ~d)\n", [X, Y, NEW_Y]),
    state(0, NEW_Y, [(X, Y) | Steps]). % Record the current state in the steps

% Predicate to print all steps in the solution path
print_steps([]).
print_steps([(X, Y) | Rest]) :-
    print_steps(Rest),
    format("State --> (~d, ~d)\n", [X, Y]).
