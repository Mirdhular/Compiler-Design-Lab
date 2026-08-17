\# Experiment 6 – Calculator using LEX and YACC



\## Aim



To implement a calculator using LEX and YACC.



\## Files



\- `cal.l` – LEX program

\- `cal.y` – YACC program

\- `output.txt` – Sample output



\## Compilation



```bash

bison -d cal.y

flex cal.l

gcc cal.tab.c lex.yy.c -o calc.exe

