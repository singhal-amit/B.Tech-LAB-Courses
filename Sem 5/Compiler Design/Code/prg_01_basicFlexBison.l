%{
#include <stdio.h>
#include <stdlib.h>
%}

%%

[0-9]     { printf("Welcome\n"); exit(0); }
.         { printf("Wrong\n"); exit(0); }

%%

int yywrap() { return 1; }

int main() {
    printf("Enter: ");
    yylex();  // Start the lexer
    return 0;
}

