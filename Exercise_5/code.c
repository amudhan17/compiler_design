#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char expr[100], c;
    int i = 0;


    printf("Input ending with $ sign: ");
    while ((c = getchar()) != '$' && c != '\n') {
        expr[i++] = c;
    }
    expr[i] = '\0'; 

    printf("\nSymbol Table display\n");
    printf("Symbol\tAddress\t\tType\n");

    for (int j = 0; expr[j] != '\0'; j++) {
        c = expr[j];
        char *ptr = (char *)malloc(sizeof(char));
        *ptr = c;

        if (isalpha(c)) {
            printf("%c\t%p\tidentifier\n", c, (void *)ptr);
        } else if (c == '+' || c == '-' || c == '*' || c == '=') {
            printf("%c\t%p\toperator\n", c, (void *)ptr);
        }
    }

    return 0;
}

