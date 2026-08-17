%{
#include "typecheck.tab.h"
#include <string.h>
%}

%option noyywrap

%%

"int"       { return INT; }
"float"     { return FLOAT; }
"char"      { return CHAR; }
"double"    { return DOUBLE; }

[a-zA-Z_][a-zA-Z0-9_]* {
    yylval.str = strdup(yytext);
    return ID;
}

[0-9]+(\.[0-9]+)? {
    yylval.str = strdup(yytext);
    return NUM;
}

[ \t]+      ;
\n          { return '\n'; }

.           { return yytext[0]; }

%%