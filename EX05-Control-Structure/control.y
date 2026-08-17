%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
int yyerror(const char *s);
%}

%token IF ELSE FOR WHILE SWITCH CASE DEFAULT
%token ID NUM
%token LBRACE RBRACE LPAREN RPAREN
%token COLON SEMICOLON
%token EQ LE GE LT GT ASSIGN

%%

program:
    IF LPAREN condition RPAREN block
    {
        printf("Valid control structure syntax.\n");
    }
    ;

block:
    LBRACE assignment RBRACE
    ;

assignment:
    ID ASSIGN NUM SEMICOLON
    ;

condition:
    ID relation NUM
    ;

relation:
      EQ
    | LE
    | GE
    | LT
    | GT
    ;

%%

int main(void)
{
    printf("Enter a C control structure syntax:\n");
    yyparse();
    return 0;
}

int yyerror(const char *s)
{
    printf("Invalid control structure syntax.\n");
    return 0;
}