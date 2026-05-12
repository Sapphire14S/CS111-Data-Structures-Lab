#include <stdio.h>

void moveOddToEnd(int arr[], int n) {
    int i, position = 0, temp;

    /* Move even numbers to the beginning */
    for (i = 0; i < n; i++) {

        if (arr[i] % 2 == 0) {

            temp = arr[position];
            arr[position] = arr[i];
            arr[i] = temp;

            position++;
        }
    }
}

int main() {
    int n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    moveOddToEnd(arr, n);

    printf("\nArray after moving odd numbers to the end:\n");

    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}