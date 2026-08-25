#include <stdio.h>

void main()
{
    int arr[100], n, i;

    // Input number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Traverse and display the array
    printf("Elements of the array are:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

   
}