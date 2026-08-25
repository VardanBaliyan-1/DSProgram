#include <stdio.h>

int main()
{
    int a[10][10], b[10][10], product[10][10];
    int r1, c1, r2, c2;
    int i, j, k;

    // Input dimensions of first matrix
    printf("Enter rows and columns of first matrix: ");
    scanf("%d %d", &r1, &c1);

    // Input dimensions of second matrix
    printf("Enter rows and columns of second matrix: ");
    scanf("%d %d", &r2, &c2);

    // Check if multiplication is possible
    if(c1 != r2)
    {
        printf("Matrix multiplication is not possible.\n");
        return 0;
    }

    // Input first matrix
    printf("Enter elements of first matrix:\n");
    for(i = 0; i < r1; i++)
    {
        for(j = 0; j < c1; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    // Input second matrix
    printf("Enter elements of second matrix:\n");
    for(i = 0; i < r2; i++)
    {
        for(j = 0; j < c2; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

    // Initialize product matrix to 0
    for(i = 0; i < r1; i++)
    {
        for(j = 0; j < c2; j++)
        {
            product[i][j] = 0;
        }
    }

    // Multiply matrices
    for(i = 0; i < r1; i++)
    {
        for(j = 0; j < c2; j++)
        {
            for(k = 0; k < c1; k++)
            {
                product[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    // Display product matrix
    printf("Product of the matrices:\n");
    for(i = 0; i < r1; i++)
    {
        for(j = 0; j < c2; j++)
        {
            printf("%d\t", product[i][j]);
        }
        printf("\n");
    }

    return 0;
}