#include <stdio.h>

int main()
{
    int arr[5], n, i, pos;

    // Input number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Input position to delete
    printf("Enter the position to delete (1 to %d): ", n);
    scanf("%d", &pos);

    // Check for valid position
    if(pos < 1 || pos > n+1)
    {
        printf("Invalid Position!\n");
    }
    else
    {
        // Shift elements to the left
        for(i = pos - 1; i <= n; i++)
        {
            arr[i] = arr[i + 1];
        }

        n--;   // Reduce array size

        // Display updated array
        printf("Array after deletion:\n");
        for(i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}