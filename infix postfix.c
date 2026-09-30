#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

/* Push into stack */
void push(char ch)
{
    top++;
    stack[top] = ch;
}

/* Pop from stack */
char pop()
{
    char ch = stack[top];
    top--;
    return ch;
}

/* Return precedence of operator */
int precedence(char ch)
{
    if (ch == '^')
        return 3;

    if (ch == '*' || ch == '/')
        return 2;

    if (ch == '+' || ch == '-')
        return 1;

    return 0;
}

int main()
{
    char infix[MAX], postfix[MAX];
    int i = 0, j = 0;
    char ch;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    while (infix[i] != '\0')
    {
        ch = infix[i];

        /* If operand, add directly to postfix */
        if (isalnum(ch))
        {
            postfix[j] = ch;
            j++;
        }

        /* If opening bracket */
        else if (ch == '(')
        {
            push(ch);
        }

        /* If closing bracket */
        else if (ch == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                postfix[j] = pop();
                j++;
            }

            pop();   // Remove '('
        }

        /* If operator */
        else
        {
            while (top != -1 &&
                   stack[top] != '(' &&
                   precedence(stack[top]) >= precedence(ch))
            {
                postfix[j] = pop();
                j++;
            }

            push(ch);
        }

        i++;
    }

    /* Pop remaining operators */
    while (top != -1)
    {
        postfix[j] = pop();
        j++;
    }

    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);

    return 0;
}