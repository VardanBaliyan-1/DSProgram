#include <stdio.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value)
{
    top++;
    stack[top] = value;
}

int pop()
{
    int value;

    value = stack[top];
    top--;

    return value;
}

int main()
{
    char postfix[MAX];
    int i;
    int a, b, result;

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    for (i = 0; postfix[i] != '\0'; i++)
    {
        /* If operand */
        if (isdigit(postfix[i]))
        {
            push(postfix[i] - '0');
        }

        /* If operator */
        else
        {
            b = pop();
            a = pop();

            switch (postfix[i])
            {
                case '+':
                    result = a + b;
                    break;

                case '-':
                    result = a - b;
                    break;

                case '*':
                    result = a * b;
                    break;

                case '/':
                    result = a / b;
                    break;

                case '%':
                    result = a % b;
                    break;

                default:
                    printf("Invalid operator\n");
                    return 0;
            }

            push(result);
        }
    }

    result = pop();

    printf("Result = %d\n", result);

    return 0;
}