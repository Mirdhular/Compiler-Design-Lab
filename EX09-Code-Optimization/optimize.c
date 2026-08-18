#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int is_number(char *s)
{
    int i;

    for (i = 0; s[i] != '\0'; i++) {
        if (!isdigit((unsigned char)s[i]))
            return 0;
    }

    return i > 0;
}

int main()
{
    char code[100][100];
    int n = 0;
    char line[100];

    printf("Enter Three Address Code (type END to finish):\n");

    while (n < 100 && fgets(line, sizeof(line), stdin)) {
        line[strcspn(line, "\n")] = '\0';

        if (strcmp(line, "END") == 0)
            break;

        if (strlen(line) > 0) {
            strcpy(code[n], line);
            n++;
        }
    }

    printf("\nUnoptimized Code:\n");

    for (int i = 0; i < n; i++)
        printf("%s\n", code[i]);

    printf("\nOptimized Code:\n");

    for (int i = 0; i < n; i++) {
        char lhs[20], op1[20], op2[20], opr;

        if (sscanf(code[i], "%19[^=]=%19[^+*/-]%c%19s",
                   lhs, op1, &opr, op2) == 4) {

            if (is_number(op1) && is_number(op2)) {
                int a = atoi(op1);
                int b = atoi(op2);
                int result = 0;

                switch (opr) {
                    case '+': result = a + b; break;
                    case '-': result = a - b; break;
                    case '*': result = a * b; break;
                    case '/':
                        if (b != 0)
                            result = a / b;
                        else {
                            printf("%s\n", code[i]);
                            continue;
                        }
                        break;
                    default:
                        printf("%s\n", code[i]);
                        continue;
                }

                printf("%s=%d\n", lhs, result);
            }
            else if (strcmp(op2, "1") == 0 &&
                    (opr == '*' || opr == '/')) {
                printf("%s=%s\n", lhs, op1);
            }
            else if (strcmp(op2, "0") == 0 &&
                    (opr == '+' || opr == '-')) {
                printf("%s=%s\n", lhs, op1);
            }
            else if (strcmp(op1, "1") == 0 && opr == '*') {
                printf("%s=%s\n", lhs, op2);
            }
            else if (strcmp(op1, "0") == 0 && opr == '+') {
                printf("%s=%s\n", lhs, op2);
            }
            else {
                printf("%s\n", code[i]);
            }
        }
        else {
            printf("%s\n", code[i]);
        }
    }

    return 0;
}