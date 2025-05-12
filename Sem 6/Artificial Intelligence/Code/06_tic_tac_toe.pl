% Define the initial empty board
initial_board([empty, empty, empty, empty, empty, empty, empty, empty, empty]).

% Start the game
start_game :-
    initial_board(Board),
    play_game(Board, x).

% Game loop
play_game(Board, Player) :-
    print_board(Board),
    ( winner(Board, x) -> write('Player X wins!'), nl
    ; winner(Board, o) -> write('Player O wins!'), nl
    ; full_board(Board) -> write('It\'s a draw!'), nl
    ; make_move(Board, Player, NewBoard),
      next_player(Player, NextPlayer),
      play_game(NewBoard, NextPlayer)
    ).

% Print the Tic-Tac-Toe board
print_board([A, B, C, D, E, F, G, H, I]) :-
    write(' '), display_symbol(A), write(' | '), display_symbol(B), write(' | '), display_symbol(C), nl,
    write('-----------'), nl,
    write(' '), display_symbol(D), write(' | '), display_symbol(E), write(' | '), display_symbol(F), nl,
    write('-----------'), nl,
    write(' '), display_symbol(G), write(' | '), display_symbol(H), write(' | '), display_symbol(I), nl, nl.

% Display 'X', 'O', or an empty position
display_symbol(empty) :- write(' ').
display_symbol(X) :- write(X).

% Check if a player has won
winner(Board, Player) :-
    ( row_win(Board, Player)
    ; col_win(Board, Player)
    ; diag_win(Board, Player)
    ).

% Check winning row conditions
row_win([A, B, C, _, _, _, _, _, _], Player) :- A = Player, B = Player, C = Player.
row_win([_, _, _, D, E, F, _, _, _], Player) :- D = Player, E = Player, F = Player.
row_win([_, _, _, _, _, _, G, H, I], Player) :- G = Player, H = Player, I = Player.

% Check winning column conditions
col_win([A, _, _, D, _, _, G, _, _], Player) :- A = Player, D = Player, G = Player.
col_win([_, B, _, _, E, _, _, H, _], Player) :- B = Player, E = Player, H = Player.
col_win([_, _, C, _, _, F, _, _, I], Player) :- C = Player, F = Player, I = Player.

% Check winning diagonal conditions
diag_win([A, _, _, _, E, _, _, _, I], Player) :- A = Player, E = Player, I = Player.
diag_win([_, _, A, _, E, _, I, _, _], Player) :- A = Player, E = Player, I = Player.

% Check if the board is full
full_board(Board) :-
    \+ member(empty, Board).

% Make a move for the current player
make_move(Board, Player, NewBoard) :-
    repeat,
    write('Enter a position (1-9): '), read(Pos),
    ( valid_move(Board, Pos) -> replace(Pos, Player, Board, NewBoard), !
    ; write('Invalid move! Try again.'), nl, fail
    ).

% Validate the move (position must be between 1-9 and must be empty)
valid_move(Board, Pos) :-
    integer(Pos), Pos >= 1, Pos =< 9, nth1(Pos, Board, empty).

% Replace a position on the board with the player's symbol
replace(Pos, Player, Board, NewBoard) :-
    nth1(Pos, Board, empty, TempBoard),
    nth1(Pos, NewBoard, Player, TempBoard).

% Switch to the next player
next_player(x, o).
next_player(o, x).
