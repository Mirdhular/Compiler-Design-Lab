%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int yylex(void);
int yyerror(const char *s);

typedef struct {
    char name[50];
    char type[20];
} Symbol;

Symbol table[100];
int count = 0;

void add_symbol(char *name, char *type)
{
    int i;

    for (i = 0; i < count; i++) {
        if (strcmp(table[i].name, name) == 0) {
            printf("Variable '%s' already declared\n", name);
            return;
        }
    }

    strcpy(table[count].name, name);
    strcpy(table[count].type, type);
    count++;
}

char *get_type(char *name)
{
    int i;

    for (i = 0; i < count; i++) {
        if (strcmp(table[i].name, name) == 0)
            return table[i].type;
    }

    return NULL;
}

void check_assignment(char *lhs, char *rhs)
{
    char *lhs_type = get_type(lhs);
    char *rhs_type = get_type(rhs);

    if (lhs_type == NULL)
        printf("Error: Variable '%s' is not declared\n", lhs);
    else if (rhs_type == NULL)
        printf("Error: Variable '%s' is not declared\n", rhs);
    else if (strcmp(lhs_type, rhs_type) == 0)
        printf("No type mismatch\n");
    else
        printf("Type mismatch\n");
}
%}

%union {
    char *str;
}

%token INT FLOAT CHAR DOUBLE
%token <str> ID NUM

%%

input:
      /* empty */
    | input line
    ;

line:
      declaration '\n'
    | assignment '\n'
    | '\n'
    ;

declaration:
      INT ID ';'
      {
          add_symbol($2, "int");
          free($2);
      }
    | FLOAT ID ';'
      {
          add_symbol($2, "float");
          free($2);
      }
    | CHAR ID ';'
      {
          add_symbol($2, "char");
          free($2);
      }
    | DOUBLE ID ';'
      {
          add_symbol($2, "double");
          free($2);
      }
    ;

assignment:
      ID '=' ID '+' NUM ';'
      {
          char *lhs_type = get_type($1);
          char *rhs_type = get_type($3);

          if (lhs_type == NULL)
              printf("Error: Variable '%s' is not declared\n", $1);
          else if (rhs_type == NULL)
              printf("Error: Variable '%s' is not declared\n", $3);
          else if (strcmp(lhs_type, rhs_type) == 0)
              printf("No type mismatch\n");
          else
              printf("Type mismatch\n");

          free($1);
          free($3);
          free($5);
      }
    | ID '=' ID ';'
      {
          check_assignment($1, $3);
          free($1);
          free($3);
      }
    ;

%%

int main(void)
{
    printf("IMPLEMENTATION OF TYPE CHECKING\n");
    printf("Enter declarations and expressions:\n");
    printf("Example: int a; float b; a = b + 1;\n\n");

    yyparse();

    return 0;
}

int yyerror(const char *s)
{
    printf("Syntax error\n");
    return 0;
}