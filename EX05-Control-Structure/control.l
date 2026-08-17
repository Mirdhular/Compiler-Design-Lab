%{
#include "control.tab.h"
%}

%%

"if"        { return IF; }
"else"      { return ELSE; }
"for"       { return FOR; }
"while"     { return WHILE; }
"switch"    { return SWITCH; }
"case"      { return CASE; }
"default"   { return DEFAULT; }

"=="        { return EQ; }
"<="        { return LE; }
">="        { return GE; }
"<"         { return LT; }
">"         { return GT; }
"="         { return ASSIGN; }

"{"         { return LBRACE; }
"}"         { return RBRACE; }
"("         { return LPAREN; }
")"         { return RPAREN; }
":"         { return COLON; }
";"         { return SEMICOLON; }

[0-9]+      { return NUM; }
[a-zA-Z_][a-zA-Z0-9_]* { return ID; }

[ \t\r\n]+  { /* ignore whitespace */ }

.           { return yytext[0]; }

%%

int yywrap(void)
{
    return 1;
}