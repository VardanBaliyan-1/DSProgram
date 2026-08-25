#include <stdio.h>

int main() {
    int a[100], n, i, k;
    int max, exp = 1;
    int output[100], count[10];

    //exp indicates which digit we are currently processing. eg. exp =1 means unit digit, exp = 10 means tens digit and so on

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    max = a[0];

    for (i = 1; i < n; i++) {
        if (a[i] > max)
            max = a[i];
    }

    // Radix Sort
    while (max / exp > 0) {

        // Initialize count array
        for (i = 0; i < 10; i++)
            count[i] = 0;

        // Count digits
        for (i = 0; i < n; i++)
            count[(a[i] / exp) % 10]++;
        //  Example: if i= 170 then 
        //  a[i] = 170
        //  exp = 1
        //  170 / 1 = 170
        //  170 % 10 = 0     So units digit = 0.
        // Cumulative count
        for (i = 1; i < 10; i++)
            count[i] += count[i - 1];

        // Store elements in output--we used to store the from right to left
        for (i = n - 1; i >= 0; i--) {
            k = (a[i] / exp) % 10;
            output[count[k] - 1] = a[i];
            count[k]--;
        }

        // Copy output to original array
        for (i = 0; i < n; i++)
            a[i] = output[i];

        // Move to next digit
        exp = exp * 10;
    }

    printf("Sorted array: ");

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}