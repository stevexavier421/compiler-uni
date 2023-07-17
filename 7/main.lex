%{
#include "y.tab.h"
%}

%%

[ \t]           /* Ignore whitespace */
[0-9]+          { yylval = atoi(yytext); return NUMBER; }
[-+\*/\(\)]     { return *yytext; }
\n              { return EOL; }

%%
