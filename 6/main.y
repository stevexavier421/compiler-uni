%{
  #include<stdio.h>
  #include<stdlib.h>
  
  int n = 2;
  void yyerror();
%}


%start stmt
%token ID NUM
%left '+' '-'
%left '/' '*'

%%
stmt : expr
| ID '=' expr
;

expr : expr '+' expr
| expr '-' expr
| expr '*' expr
| expr '/' expr
| '(' expr ')'
| ID
| NUM
;
%%

void main() {
  while(n) {
    printf("enter an expression: ");
    yyparse();
    printf("validity: valid\n");
  }
}

void yyerror() {
  printf("validity: invalid\n");
  exit(0);
}
