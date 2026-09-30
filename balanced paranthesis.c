#include <stdio.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch)
{
    top++;
    stack[top] = ch;
}

char pop()
{
    char ch = stack[top];
    top--;
    return ch;
}

int isMatching(char open, char close)
{
    if (open == '(' && close == ')')
        return 1;

    if (open == '{' && close == '}')
        return 1;

    if (open == '[' && close == ']')
        return 1;

    return 0;
}

int main()
{
    char exp[MAX];
    int i;
    char ch;

    printf("Enter an expression: ");
    scanf("%s", exp);

    for (i = 0; exp[i] != '\0'; i++)
    {
        ch = exp[i];

        /* Opening brackets */
        if (ch == '(' || ch == '{' || ch == '[')
        {
            push(ch);
        }

        /* Closing brackets */
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (top == -1)
            {
                printf("Not Balanced\n");
                return 0;
            }

            if (!isMatching(pop(), ch))
            {
                printf("Not Balanced\n");
                return 0;
            }
        }
    }

    if (top == -1)
        printf("Balanced\n");
    else
        printf("Not Balanced\n");

    return 0;
}