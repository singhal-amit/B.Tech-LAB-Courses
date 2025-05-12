% Predicate to convert Celsius to Fahrenheit
c_to_f(C, F) :-
    F is (C * 9 / 5) + 32.

% Predicate to check if the temperature is below freezing (0°C or 32°F)
below_freezing(F) :-
    F =< 32.
