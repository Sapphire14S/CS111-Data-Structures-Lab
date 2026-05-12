#include <stdio.h>

int main() {

    int n, i, j, k;
    int found = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array elements:\n");

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter value of K: ");
    scanf("%d", &k);

    printf("\nPairs with sum %d:\n", k);

    for (i = 0; i < n - 1; i++) {

        for (j = i + 1; j < n; j++) {

            if (arr[i] + arr[j] == k) {

                printf("(%d, %d)\n",
                       arr[i],
                       arr[j]);

                found = 1;
            }
        }
    }

    if (!found) {
        printf("No pair found.\n");
    }

    return 0;
}