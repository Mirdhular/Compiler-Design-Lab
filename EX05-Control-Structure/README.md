# Experiment 5 – Valid Control Structure Syntax

## Aim

To write a LEX and YACC program to recognize valid C control structure syntax.

## Files

- `control.l` – LEX program
- `control.y` – YACC program
- `output.txt` – Sample execution output

## Compilation

```bash
bison -d control.y
flex control.l
gcc control.tab.c lex.yy.c -o control.exe