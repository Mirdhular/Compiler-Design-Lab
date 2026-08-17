# Experiment 4 – Valid Variable Recognition

## Aim

To write a LEX and YACC program to recognize a valid variable that starts with a letter followed by any number of letters or digits.

## Files

- `valvar.l` – LEX program
- `valvar.y` – YACC program
- `output.txt` – Sample execution output

## Compilation and Execution

```bash
bison -d valvar.y
flex valvar.l
gcc valvar.tab.c lex.yy.c -o valvar.exe
./valvar.exe