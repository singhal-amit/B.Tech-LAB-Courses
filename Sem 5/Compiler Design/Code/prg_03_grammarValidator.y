%{
    #include <stdio.h>
    #include <stdlib.h>

    extern int yylex();
    void yyerror(char *s);
    int valid = 1;
%}

%token A B

%%
str: S '\n' { printf("Parsed with rule ab^n\n"); return 0; };

S: A T;
T: B T | /* empty */;

%%

void yyerror(char *msg) {
    valid = 0;
    fprintf(stderr, "%s\n", msg);
}

int main() {
    printf("Enter the string to check: \n");
    yyparse();
    if (valid) printf("\nValid\n");
    else printf("\nInvalid\n");
    return 0;
}
