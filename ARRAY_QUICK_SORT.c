#include <stdio.h>

int main() {
    int a[100], n, i, j, k;
    int pivot, temp;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Quick Sort
    for (i = 0; i < n ; i++) {
        pivot = a[i];
        j = i + 1;

        for (k = j; k < n; k++) {
            if (a[k] < pivot) {
                temp = a[j];
                a[j] = a[k];
                a[k] = temp;
                j++;
            }
        }

        temp = a[i];
        a[i] = a[j - 1];
        a[j - 1] = temp;
    }

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}