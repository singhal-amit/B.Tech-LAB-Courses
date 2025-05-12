%{
#include <stdio.h>
#include <stdlib.h>
%}

%token NUMBER
%left PLUS MINUS
%left MULT DIV
%%
expr:
      expr PLUS term  { printf("%d\n", $1 + $3); }
    | expr MINUS term { printf("%d\n", $1 - $3); }
    | term;

term:
      term MULT factor { printf("%d\n", $1 * $3); }
    | term DIV factor  { printf("%d\n", $1 / $3); }
    | factor;

factor:
      NUMBER;
%%
int main() {
    printf("\nEnter any Arithmetic Expression which can have operations - Addition, Subtraction, Multiplication, Division:\n");
    yyparse();
    return 0;
}

int yyerror() {
    printf("Error\n");
    return 1;
}
