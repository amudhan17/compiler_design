%{
#include <stdio.h>
int words = 0, digits = 0, specials = 0, lines = 0;
%}

%%
[ \t]+           ;               // Ignore whitespace
[a-zA-Z]+        { words++; }
[0-9]+           { digits++; }
\n               { lines++; }
.                { specials++; }
%%

int yywrap() { return 1; }

int main() {
    yylex();
    printf("\nWords: %d\nDigits: %d\nSpecial Characters: %d\nLines: %d\n", words, digits, specials, lines);
    return 0;
}
