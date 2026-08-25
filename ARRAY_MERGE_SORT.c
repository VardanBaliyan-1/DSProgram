#include <stdio.h>

int main() {
    int a[100], temp[100];
    int n, i, j, k, size, left, mid, right;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    // Merge Sort
    for (size = 1; size < n; size = size * 2) {
        for (left = 0; left < n - 1; left += 2 * size) {

            mid = left + size - 1;
            right = left + 2 * size - 1;

            if (mid >= n)// it checks if the left subarray still exists or not
                continue;

            if (right >= n)// it checks if the right subarray still exists or not 
                right = n - 1;

            i = left;// i means beginning of left subarray
            j = mid + 1;//j means beginning of right subarrray
            k = left;// k means where the merged elements should be placed

            while (i <= mid && j <= right) {
                if (a[i] < a[j])
                    temp[k++] = a[i++];
                else
                    temp[k++] = a[j++];
            }

            while (i <= mid)
                temp[k++] = a[i++];

            while (j <= right)
                temp[k++] = a[j++];

            for (i = left; i <= right; i++)
                a[i] = temp[i];
        }
    }

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}