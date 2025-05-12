%{
#include <stdio.h>
#include <stdlib.h>

int token_count = 0;
%}

%%
[a-zA-Z_][a-zA-Z0-9_]*   { token_count++; }  // Identifiers
[0-9]+                   { token_count++; }  // Numbers
"+"|"-"|"*"|"/"          { token_count++; }  // Operators
";"|"{"|"}"|"("|")"      { token_count++; }  // Punctuation
[ \t\n]+                 { /* Ignore whitespace */ }
.                        { /* Ignore other characters */ }
%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter a string: ");
    yylex();  // Start lexing
    printf("\nNumber of tokens: %d\n", token_count);
    return 0;
}
