% Define the graph as facts (edges)
edge(a, b).
edge(a, c).
edge(b, d).
edge(b, e).
edge(c, f).
edge(c, g).

% Check if a node exists in the graph (as a parent or child)
node_exists(Node) :-
    edge(Node, _);  % Check if the node has an outgoing edge (parent)
    edge(_, Node).  % Check if the node has an incoming edge (child)

% Breadth-First Search Traversal
bfs(Start, Goal) :-
    bfs_helper([Start], Goal, []).

bfs_helper([Goal | _], Goal, Path) :-
    reverse([Goal | Path], FinalPath),
    print_path(FinalPath).

bfs_helper([Node | Rest], Goal, Visited) :-
    findall(Neighbor, (edge(Node, Neighbor), \+ member(Neighbor, Visited)), Neighbors),
    append(Rest, Neighbors, NewQueue),
    bfs_helper(NewQueue, Goal, [Node | Visited]).

% Print the path from Start to Goal
print_path([]) :-
    writeln('No path found.').

print_path([Node]) :-
    write(Node), nl.

print_path([Node | Rest]) :-
    write(Node), write(' - '),
    print_path(Rest).

% Print the path from Start to Goal in a parent-child relationship
print_parent([]).

print_parent([Node]) :-
    write(Node), nl.

print_parent([Node | Rest]) :-
    write(Node), write(' - '),
    print_parent(Rest).

% Print the path from Start to Goal in a reverse relationship
print_reverse_path([]).

print_reverse_path([Node]) :-
    write(Node), nl.

print_reverse_path([Node | Rest]) :-
    print_reverse_path(Rest),
    write(Node), write(' - ').
