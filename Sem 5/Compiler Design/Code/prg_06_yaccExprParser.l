%{
#include "y.tab.h"
%}

%%
[0-9]+      { yylval = atoi(yytext); return NUMBER; }
[\t ]+      /* Ignore whitespace */
\n          { return 0; }  /* End of input */
.           { return yytext[0]; }
%%

int yywrap(void) {
    return 1;
}
