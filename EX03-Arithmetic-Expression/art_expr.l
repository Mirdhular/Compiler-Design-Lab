%{
#include "art_expr.tab.h"
%}

%%
[0-9]+              { return NUMBER; }
[a-zA-Z][a-zA-Z0-9]* { return ID; }
[ \t]               ;
\n                  { return '\n'; }
.                   { return yytext[0]; }
%%

int yywrap()
{
    return 1;
}