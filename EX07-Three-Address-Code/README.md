\# Experiment 7 – Three Address Code



\## Aim



To write a program using LEX and YACC to generate three-address code (TAC) for a simple arithmetic expression.



\## Files



\- `tac.l` – LEX program

\- `tac.y` – YACC program

\- `output.txt` – Sample output



\## Compilation



```bash

bison -d tac.y

flex tac.l

gcc tac.tab.c lex.yy.c -o tac.exe

