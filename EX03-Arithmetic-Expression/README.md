# Experiment 3 – Arithmetic Expression Validation using LEX and YACC

## Aim

To implement an arithmetic expression validator using LEX and YACC.

## Description

This experiment uses:

- **LEX/Flex** to identify numbers, identifiers, operators, and other symbols.
- **YACC/Bison** to parse the arithmetic expression according to the grammar.
- **GCC** to compile the generated C files.

## Files

- `art_expr.l` – LEX/Flex lexical analyzer
- `art_expr.y` – YACC/Bison grammar
- `output.txt` – Sample execution output

## Tools Used

- Flex 2.6.4
- Bison 3.8.2
- GCC 16.2.0
- MSYS2 UCRT64

## Compilation and Execution

Run the following commands in the experiment directory:

```bash
bison -d art_expr.y
flex art_expr.l
gcc lex.yy.c art_expr.tab.c -o art_expr
./art_expr.exe