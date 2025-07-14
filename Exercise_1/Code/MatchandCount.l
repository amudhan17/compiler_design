%{
#include <stdio.h>
int number_count = 0;
%}

%%
[0-9]+   { number_count++; }
.|\n     ;
%%

int yywrap() { return 1; }

int main() {
    yylex();
    printf("Total numbers: %d\n", number_count);
    return 0;
}
