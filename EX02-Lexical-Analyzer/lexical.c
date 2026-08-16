#include <stdio.h>
#include <string.h>
#include <ctype.h>
char *keywords[] = {
    "int","float","char","double","void","if","else","for",
    "while","do","return","break","continue","switch","case",
    "default","struct","long","short","unsigned"
};
int isKeyword(char str[])
{
    int i;
    for(i = 0; i < 20; i++)
    {
        if(strcmp(str, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int isOperator(char ch)
{
    return (ch=='+' || ch=='-' || ch=='*' || ch=='/' ||
            ch=='=' || ch=='%' || ch=='<' || ch=='>' ||
            ch=='!');
}

int isDelimiter(char ch)
{
    return (ch==' ' || ch=='\n' || ch=='\t' ||
            ch==',' || ch==';' || ch=='(' ||
            ch==')' || ch=='{' || ch=='}' ||
            ch=='[' || ch==']');
}

int main(){

    FILE *fp;
    char filename[100];
    char ch;
    char token[100];
    int i = 0;

    printf("Enter C file name: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if(fp == NULL)
    {
        printf("Cannot open file.\n");
        return 0;
    }

    while((ch = fgetc(fp)) != EOF)
    {
        /* Skip single-line comments */
        if(ch == '/')
        {
            char next = fgetc(fp);

            if(next == '/')
            {
                while((ch = fgetc(fp)) != '\n' && ch != EOF);
                continue;
            }
            else if(next == '*')
            {
                char prev = 0;
                while((ch = fgetc(fp)) != EOF)
                {
                    if(prev == '*' && ch == '/')
                        break;
                    prev = ch;
                }
                continue;
            }
            else
            {
                ungetc(next, fp);
            }
        }

        if(isalpha(ch) || ch == '_')
        {
            token[i++] = ch;

            while((ch = fgetc(fp)) != EOF &&
                  (isalnum(ch) || ch == '_'))
            {
                token[i++] = ch;
            }

            token[i] = '\0';
            i = 0;

            if(isKeyword(token))
                printf("Keyword\t\t: %s\n", token);
            else
                printf("Identifier\t: %s\n", token);

            if(ch != EOF)
                ungetc(ch, fp);
        }

        else if(isdigit(ch))
        {
            token[i++] = ch;

            while((ch = fgetc(fp)) != EOF &&
                 (isdigit(ch) || ch == '.'))
            {
                token[i++] = ch;
            }

            token[i] = '\0';
            i = 0;

            printf("Number\t\t: %s\n", token);

            if(ch != EOF)
                ungetc(ch, fp);
        }

        else if(isOperator(ch))
        {
            printf("Operator\t: %c\n", ch);
        }

        else if(isDelimiter(ch))
        {
            if(ch != ' ' && ch != '\n' && ch != '\t')
                printf("Delimiter\t: %c\n", ch);
        }
    }

    fclose(fp);

    printf("\nEnd of file.\n");

    return 0;
}
