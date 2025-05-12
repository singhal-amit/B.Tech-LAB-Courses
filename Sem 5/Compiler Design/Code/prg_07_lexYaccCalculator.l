%{
#include "y.tab.h"
%}

%%
[0-9]+      { yylval = atoi(yytext); return NUMBER; }
[\n]        { return 0; }
"+"         { return PLUS; }
"-"         { return MINUS; }
"*"         { return MULT; }
"/"         { return DIV; }
[\t ]+      { /* Ignore whitespace */ }
.           { printf("Unexpected character: %s\n", yytext); return 1; }
%%
int yywrap() {
    return 1;
}
