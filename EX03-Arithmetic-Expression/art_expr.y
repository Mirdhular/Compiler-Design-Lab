%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
void yyerror(const char *s);
%}

%token NUMBER ID

%left '+' '-'
%left '*' '/'

%%

input:
      expr {
          printf("Valid arithmetic expression\n");
          return 0;
      }
    ;

expr:
      expr '+' expr
    | expr '-' expr
    | expr '*' expr
    | expr '/' expr
    | '(' expr ')'
    | NUMBER
    | ID
    ;

%%

void yyerror(const char *s)
{
    printf("Invalid arithmetic expression\n");
}

int main()
{
    printf("Enter an arithmetic expression: ");
    yyparse();
    return 0;
}