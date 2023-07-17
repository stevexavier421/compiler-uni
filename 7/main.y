%{
#include <stdio.h>

void yyerror(const char*);

%}

%token NUMBER
%token EOL

%%

start: expr EOL { printf("\n"); }
     ;

expr: expr '+' term { printf("+ "); }
    | expr '-' term { printf("- "); }
    | term { }
    ;

term: term '*' factor { printf("* "); }
    | term '/' factor { printf("/ "); }
    | factor { }
    ;

factor: NUMBER { printf("%d ", $1); }
       | '(' expr ')' { }
       ;

%%

int main() {
    yyparse();
    return 0;
}

void yyerror(const char* message) {
}

void yywrap() {
}
