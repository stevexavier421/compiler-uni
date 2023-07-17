%{
#include <stdio.h>
%}

%token BINARY

%%
input: /* empty */
     | input line
     ;

line: BINARY '\n'  { printf("%ld\n", $1); }
    ;

%%

int main() {
    yyparse();
    return 0;
}

int yyerror(const char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
    return 0;
}
