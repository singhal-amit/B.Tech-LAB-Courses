%{
    #include <stdio.h>
    #include <string.h>

    // Array of C keywords
    char keyword[32][10] = {
        "auto", "double", "int", "struct", "break", "else", "long",
        "switch", "case", "enum", "register", "typedef", "char",
        "extern", "return", "union", "const", "float", "short",
        "unsigned", "continue", "for", "signed", "void", "default",
        "goto", "sizeof", "volatile", "do", "if", "static", "while"
    };

    int is_keyword(char *str) {
        for(int i = 0; i < 32; i++) {
            if(strcmp(str, keyword[i]) == 0)
                return 1;
        }
        return 0;
    }
%}

%%

[a-zA-Z]+ {
    if (is_keyword(yytext)) {
        printf("%s is a keyword\n", yytext);
    } else {
        printf("%s is not a keyword\n", yytext);
    }
}

[0-9]+ {
    printf("%s is a number\n", yytext);
}

\n { return 0; }   // Stops reading after a newline

.|\n { /* ignore any other characters */ }

%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter the string: ");
    yylex();
    return 0;
}

