#include <stdio.h>

int main() {
    int n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int maximum = arr[0];
    int minimum = arr[0];

    for (i = 1; i < n; i++) {

        if (arr[i] > maximum) {
            maximum = arr[i];
        }

        if (arr[i] < minimum) {
            minimum = arr[i];
        }
    }

    printf("\nMaximum Element = %d\n", maximum);
    printf("Minimum Element = %d\n", minimum);

    return 0;
}