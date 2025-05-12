% Define punctuation characters by their ASCII codes
is_punctuation(Char) :-
    member(Char, [46, 44, 59, 58, 33, 63, 39, 34, 45, 40, 41, 91, 93, 123, 125]).

% Predicate to remove punctuations from a list of character codes
remove_punctuations([], []).  % Base case: empty list returns empty list

remove_punctuations([H | T], Result) :-
    is_punctuation(H),  % If the character is punctuation, skip it
    remove_punctuations(T, Result).

remove_punctuations([H | T], [H | Result]) :-  % Otherwise, keep the character
    \+ is_punctuation(H),
    remove_punctuations(T, Result).

% Convert input string to output without punctuations
clean_string(Input, Output) :-
    string_codes(Input, Codes),       % Convert string to list of character codes
    remove_punctuations(Codes, CleanCodes),  % Remove punctuation marks
    string_codes(Output, CleanCodes).  % Convert back to string

% Main program that takes user input and displays cleaned string
start :-
    write('Enter a sentence: '), nl,
    read_line_to_string(user_input, Input),  % Read input from user
    clean_string(Input, Output),
    write('Original String: '), write(Input), nl,
    write('Cleaned String: '), write(Output), nl.
