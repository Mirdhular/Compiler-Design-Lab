%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
int yyerror(const char *s);
%}

%define api.value.type {double}

%token NUM

%left '+' '-'
%left '*' '/'
%right UMINUS

%%

statement:
    expression '\n'
    {
        printf("Answer: %g\n", $1);
    }
    ;

expression:
      expression '+' expression   { $$ = $1 + $3; }
    | expression '-' expression   { $$ = $1 - $3; }
    | expression '*' expression   { $$ = $1 * $3; }
    | expression '/' expression
      {
          if ($3 == 0)
              yyerror("Division by zero");
          else
              $$ = $1 / $3;
      }
    | '(' expression ')'          { $$ = $2; }
    | '-' expression %prec UMINUS { $$ = -$2; }
    | NUM                          { $$ = $1; }
    ;

%%

int main(void)
{
    printf("Enter the expression:\n");
    yyparse();
    return 0;
}

int yyerror(const char *s)
{
    printf("Error: %s\n", s);
    return 0;
}