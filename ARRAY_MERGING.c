#include <stdio.h>

int main()
{
    int a[50], b[50], c[100];
    int n1, n2, i;

    // Input first array
    printf("Enter the size of first array: ");
    scanf("%d", &n1);

    printf("Enter the elements of first array:\n");
    for(i = 0; i < n1; i++)
    {
        scanf("%d", &a[i]);
    }

    // Input second array
    printf("Enter the size of second array: ");
    scanf("%d", &n2);

    printf("Enter the elements of second array:\n");
    for(i = 0; i < n2; i++)
    {
        scanf("%d", &b[i]);
    }

    // Copy first array into third array
    for(i = 0; i < n1; i++)
    {
        c[i] = a[i];
    }

    // Copy second array into third array
    for(i = 0; i < n2; i++)
    {
        c[n1 + i] = b[i];
    }

    // Display merged array
    printf("Merged Array:\n");
    for(i = 0; i < n1 + n2; i++)
    {
        printf("%d ", c[i]);
    }

    return 0;
}