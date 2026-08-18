#include <stdio.h>
#include <string.h>

int main()
{
    char line[100];
    char result[20], op1[20], op2[20], op;
    
    printf("Enter Three Address Code (type END to finish):\n\n");

    printf("8086 Assembly Code:\n");

    while (fgets(line, sizeof(line), stdin))
    {
        if (strncmp(line, "END", 3) == 0)
            break;

        line[strcspn(line, "\n")] = '\0';

        if (sscanf(line, "%19s = %19s %c %19s",
                   result, op1, &op, op2) == 4)
        {
            printf("MOV AX, %s\n", op1);

            switch (op)
            {
                case '+':
                    printf("ADD AX, %s\n", op2);
                    break;

                case '-':
                    printf("SUB AX, %s\n", op2);
                    break;

                case '*':
                    printf("MOV BX, %s\n", op2);
                    printf("MUL BX\n");
                    break;

                case '/':
                    printf("MOV BX, %s\n", op2);
                    printf("XOR DX, DX\n");
                    printf("DIV BX\n");
                    break;

                default:
                    printf("; Unsupported operator\n");
            }

            printf("MOV %s, AX\n\n", result);
        }
        else if (sscanf(line, "%19s = %19s", result, op1) == 2)
        {
            printf("MOV AX, %s\n", op1);
            printf("MOV %s, AX\n\n", result);
        }
        else
        {
            printf("; Invalid TAC: %s\n", line);
        }
    }

    return 0;
}