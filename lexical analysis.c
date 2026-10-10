
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isKeyword(char word[])
{
    char keywords[32][10] = {
        "auto", "break", "case", "char", "const",
        "continue", "default", "do", "double", "else",
        "enum", "extern", "float", "for", "goto",
        "if", "int", "long", "register", "return",
        "short", "signed", "sizeof", "static", "struct",
        "switch", "typedef", "union", "unsigned", "void",
        "volatile", "while"
    };

    for (int i = 0; i < 32; i++)
        if (strcmp(word, keywords[i]) == 0)
            return 1;

    return 0;
}

int main()
{
    char source[500];
    int i = 0;

    printf("Enter a C statement:\n");
    fgets(source, sizeof(source), stdin);

    printf("\nLexical Analysis:\n");

    while (source[i] != '\0')
    {
        if (isspace((unsigned char)source[i]))
        {
            i++;
        }
        else if (isalpha((unsigned char)source[i]) ||
                 source[i] == '_')
        {
            char word[100];
            int j = 0;

            while (isalnum((unsigned char)source[i]) ||
                   source[i] == '_')
                word[j++] = source[i++];

            word[j] = '\0';

            if (isKeyword(word))
                printf("%s : Keyword\n", word);
            else
                printf("%s : Identifier\n", word);
        }
        else if (isdigit((unsigned char)source[i]))
        {
            char number[100];
            int j = 0;

            while (isdigit((unsigned char)source[i]) ||
                   source[i] == '.')
                number[j++] = source[i++];

            number[j] = '\0';
            printf("%s : Constant\n", number);
        }
        else if (strchr("+-*/%=<>!&|", source[i]))
        {
            printf("%c : Operator\n", source[i]);
            i++;
        }
        else if (strchr(";,(){}[]", source[i]))
        {
            printf("%c : Special Symbol\n", source[i]);
            i++;
        }
        else
        {
            printf("%c : Unknown Symbol\n", source[i]);
            i++;
        }
    }

    return 0;
}
