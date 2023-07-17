%{
#include<stdio.h>
int n;
int keywords, strings, identifiers, digits, special_chars, operators;
%}
 
%%
auto|break|case|char|const|continue|default|do|double|else|enum|extern|float|for|goto|if|int|long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while {printf("keyword"); keywords++;}
\".*\"|'.*' {printf("string"); strings++;}
[a-zA-Z_][a-zA-Z_]* {printf("identifier"); identifiers++;}
[+,-]?[0-9]+\.?[0-9]* {printf("digit"); digits++;}
[;]+ {printf("special char"); special_chars++;}
[\+\-\=\!\&\^\*\\] {printf("operator"); operators++;}
 
%%
 
int yywrap() {
	printf("keywords: %d\n", keywords);
	printf("digit: %d\n", digits);
	printf("identifiers: %d\n", identifiers);
	printf("special chars: %d\n", special_chars);
	printf("operators: %d\n", operators);
return 1;
}
 
void main() {
 
	yylex();
}
 
 
