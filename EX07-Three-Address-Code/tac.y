%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int yylex(void);
int yyerror(const char *s);

int temp_count = 0;

char *new_temp()
{
    char *temp = malloc(20);
    sprintf(temp, "t%d", ++temp_count);
    return temp;
}
%}

%union {
    char *str;
}

%token <str> ID NUM
%type <str> expr

%left '+' '-'
%left '*' '/'
%right UMINUS

%%

program:
    ID '=' expr '\n'
    {
        printf("%s = %s\n", $1, $3);
        free($1);
        free($3);
    }
    ;

expr:
      expr '+' expr
      {
          char *t = new_temp();
          printf("%s = %s + %s\n", t, $1, $3);
          $$ = t;
          free($1);
          free($3);
      }

    | expr '-' expr
      {
          char *t = new_temp();
          printf("%s = %s - %s\n", t, $1, $3);
          $$ = t;
          free($1);
          free($3);
      }

    | expr '*' expr
      {
          char *t = new_temp();
          printf("%s = %s * %s\n", t, $1, $3);
          $$ = t;
          free($1);
          free($3);
      }

    | expr '/' expr
      {
          char *t = new_temp();
          printf("%s = %s / %s\n", t, $1, $3);
          $$ = t;
          free($1);
          free($3);
      }

    | '(' expr ')'
      {
          $$ = $2;
      }

    | ID
      {
          $$ = $1;
      }

    | NUM
      {
          $$ = $1;
      }
    ;

%%

int main()
{
    printf("Enter an assignment expression:\n");
    yyparse();
    return 0;
}

int yyerror(const char *s)
{
    printf("Invalid expression\n");
    return 0;
}