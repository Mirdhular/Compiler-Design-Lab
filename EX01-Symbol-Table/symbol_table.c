#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct table
{
    char var[10];
    int value;
};

struct table tbl[20];
int n = 0;
void create();
void insert();
void modify();
int search(char variable[]);
void display();
int main()
{
    int ch, result;
    char v[10];

    do
    {
        printf("\n----- SYMBOL TABLE -----\n");
        printf("1. Create\n");
        printf("2. Insert\n");
        printf("3. Modify\n");
        printf("4. Search\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                create();
                break;

            case 2:
                insert();
                break;

            case 3:
                modify();
                break;

            case 4:
                printf("Enter variable to search: ");
                scanf("%s", v);

                result = search(v);

                if (result == -1)
                    printf("Variable not found.\n");
                else
                    printf("Found at location %d\nValue = %d\n",
                           result + 1, tbl[result].value);
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (ch != 6);

    return 0;
}


void create()
{
    int i;

    printf("Enter number of entries: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter variable and value: ");
        scanf("%s%d", tbl[i].var, &tbl[i].value);
    }

    display();
}

void insert()
{
    if (n >= 20)
    {
        printf("Table is full!\n");
        return;
    }

    printf("Enter variable and value: ");
    scanf("%s%d", tbl[n].var, &tbl[n].value);

    n++;

    printf("Inserted successfully.\n");
}

void modify()
{
    char variable[10];
    int pos;

    printf("Enter variable to modify: ");
    scanf("%s", variable);

    pos = search(variable);

    if (pos == -1)
    {
        printf("Variable not found.\n");
        return;
    }

    printf("Enter new variable name and value: ");
    scanf("%s%d", tbl[pos].var, &tbl[pos].value);

    printf("Modified successfully.\n");
}

int search(char variable[])
{
    int i;

    for (i = 0; i < n; i++)
    {
        if (strcmp(tbl[i].var, variable) == 0)
            return i;
    }

    return -1;
}

void display(){

    int i;

    if (n == 0)
    {
        printf("Table is empty.\n");
        return;
    }

    printf("\nVARIABLE\tVALUE\n");

    for (i = 0; i < n; i++)
    {
        printf("%s\t\t%d\n", tbl[i].var, tbl[i].value);
    }
}
