% Main predicate to read input and sort the sentence
sort_sentence :-
    write('Enter a sentence: '), nl,
    read_line_to_string(user_input, Sentence), % Read sentence from user input
    split_string(Sentence, " ", "", Words),    % Split the sentence into words
    msort(Words, SortedWords),                 % Sort words alphabetically
    atomic_list_concat(SortedWords, ' ', SortedSentence), % Combine sorted words back into a sentence
    write('Sorted sentence: '), writeln(SortedSentence).

% To run:
% ?- sort_sentence.
% Then input your sentence when prompted.
