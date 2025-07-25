%{
#include <stdio.h>
int count = 0;
%}

%%
[A-Z] { printf("%s capital letter\n", yytext); count++; }
.     { printf("%s not a capital letter\n", yytext); }
\n    { return 0; }
%%

int yywrap() { return 1; }

int main() {
    yylex();
    printf("\nNumber of Capital letters in the given input - %d\n", count);
    return 0;
}
