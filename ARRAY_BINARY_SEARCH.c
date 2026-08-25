#include <stdio.h>

int main()
{
    int arr[100], n, i, key;
    int low, high, mid, found = 0;

    // Input number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Input sorted array elements
    printf("Enter %d elements in sorted order:\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Input element to search
    printf("Enter the element to search: ");
    scanf("%d", &key);

    // Binary Search
    low = 0;
    high = n - 1;

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(arr[mid] == key)
        {
            found = 1;
            break;
        }
        else if(key < arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    // Display result
    if(found == 1)
    {
        printf("Element %d found at position %d.\n", key, mid +1);
    }
    else
    {
        printf("Element %d not found in the array.\n", key);
    }

    return 0;
}