:- dynamic word/1.
word(apple).  % Define the word to guess

% Start the game
hangman :-
    word(Word),
    atom_chars(Word, WordList),
    length(WordList, N),
    play(WordList, N, [], 6).  % Max 6 wrong attempts

% Play function
play(WordList, _, Guessed, 0) :-
    write('Game Over! You ran out of attempts.'), nl,
    write('The correct word was: '), write(WordList), nl, !.

play(WordList, _, Guessed, _) :-
    word_complete(WordList, Guessed),
    write('Congratulations! You guessed the word: '), write(WordList), nl, !.

play(WordList, N, Guessed, Attempts) :-
    display_progress(WordList, Guessed),
    write('Enter your guess: '),
    read(Char),
    ( member(Char, WordList) ->
        write('Correct Guess!'), nl,
        play(WordList, N, [Char|Guessed], Attempts)
    ;
        write('Wrong Guess!'), nl,
        NewAttempts is Attempts - 1,
        write('Remaining Attempts: '), write(NewAttempts), nl,
        play(WordList, N, Guessed, NewAttempts)
    ).

% Check if all letters are guessed
word_complete([], _).
word_complete([H|T], Guessed) :-
    member(H, Guessed),
    word_complete(T, Guessed).

% Display word progress
display_progress([], _):- nl.
display_progress([H|T], Guessed) :-
    ( member(H, Guessed) -> write(H) ; write('_') ),
    write(' '),
    display_progress(T, Guessed).

% Start game
?- hangman.
