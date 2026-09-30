#include <stdio.h>

int fibonacci(int n)
{
    int a = 0, b = 1, c;

    if (n == 0)
        return a;

    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }

    return b;
}

int main()
{
    int n = 7;

    printf("Fibonacci number = %d", fibonacci(n));

    return 0;
}