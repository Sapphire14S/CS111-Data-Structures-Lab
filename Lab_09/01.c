#include <stdio.h>
#include <stdlib.h>

/* Comparison function for qsort */
int compare(const void *a, const void *b) {

    return (*(int *)a - *(int *)b);
}

int main() {

    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array elements:\n");

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    /* Sort array: O(n log n) */
    qsort(arr, n, sizeof(int), compare);

    int maxElement = arr[0];
    int maxCount = 1;

    int currentElement = arr[0];
    int currentCount = 1;

    for (i = 1; i < n; i++) {

        if (arr[i] == currentElement) {
            currentCount++;
        } else {

            if (currentCount > maxCount) {
                maxCount = currentCount;
                maxElement = currentElement;
            }

            currentElement = arr[i];
            currentCount = 1;
        }
    }

    /* Final check */
    if (currentCount > maxCount) {
        maxCount = currentCount;
        maxElement = currentElement;
    }

    printf("\nElement occurring maximum times = %d\n", maxElement);

    printf("Frequency = %d\n", maxCount);

    return 0;
}