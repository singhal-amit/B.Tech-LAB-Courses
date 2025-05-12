%{
#include <stdio.h>
int yylex(void);
void yyerror(const char *s);
%}

%token NUMBER
%left '+' '-'
%left '*' '/'
%%
expr:
      expr '+' expr  { printf("%d + %d = %d\n", $1, $3, $1 + $3); }
    | expr '-' expr  { printf("%d - %d = %d\n", $1, $3, $1 - $3); }
    | expr '*' expr  { printf("%d * %d = %d\n", $1, $3, $1 * $3); }
    | expr '/' expr  {
                      if ($3 == 0) {
                          yyerror("Division by zero!");
                      } else {
                          printf("%d / %d = %d\n", $1, $3, $1 / $3);
                      }
                  }
    | '(' expr ')'   { $$ = $2; }
    | NUMBER         { $$ = $1; }
    ;
%%
void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main(void) {
    printf("Enter the expression: ");
    return yyparse();
}
