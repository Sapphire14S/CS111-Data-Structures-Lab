#include <stdio.h>

int main() {

    int n, i, j;
    int foundDuplicate;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array elements:\n");

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nRepeating Elements:\n");

    for (i = 0; i < n; i++) {

        foundDuplicate = 0;

        /* Check whether element already printed */
        for (j = 0; j < i; j++) {

            if (arr[i] == arr[j]) {
                foundDuplicate = 1;
                break;
            }
        }

        if (foundDuplicate) {
            continue;
        }

        /* Count occurrences */
        int count = 1;

        for (j = i + 1; j < n; j++) {

            if (arr[i] == arr[j]) {
                count++;
            }
        }

        if (count > 1) {
            printf("%d ", arr[i]);
        }
    }

    printf("\n");

    return 0;
}