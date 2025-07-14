%{
#include <stdio.h>
int vowels = 0, consonants = 0;
%}

%%
[aAeEiIoOuU]    { vowels++; }
[a-zA-Z]        { consonants++; }
.|\n            ;
%%

int yywrap() { return 1; }

int main() {
    yylex();
    printf("Vowels: %d, Consonants: %d\n", vowels, consonants);
    return 0;
}