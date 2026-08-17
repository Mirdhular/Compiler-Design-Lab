\# Experiment 8 – Type Checking using LEX and YACC



\## Aim



To implement type checking using LEX and YACC.



\## Files



\- `typecheck.l` – LEX program

\- `typecheck.y` – YACC program

\- `output.txt` – Sample output



\## Compilation



```bash

bison -d typecheck.y

flex typecheck.l

gcc typecheck.tab.c lex.yy.c -o typecheck.exe

