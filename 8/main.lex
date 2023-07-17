%{
#include "y.tab.h"
%}

%%
[01]+  { yylval = strtol(yytext, NULL, 2); return BINARY; }
.|\n   { return yytext[0]; }
%%

int yywrap() {
    return 1;
}
