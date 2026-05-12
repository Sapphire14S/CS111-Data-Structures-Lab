#include <stdio.h>

void moveZeroesToEnd(int arr[], int n) {
    int i, position = 0, temp;

    /* Move all non-zero elements to the beginning */
    for (i = 0; i < n; i++) {
        if (arr[i] != 0) {
            temp = arr[position];
            arr[position] = arr[i];
            arr[i] = temp;
            position++;
        }
    }
}

int main() {
    int n, i;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    moveZeroesToEnd(arr, n);

    printf("\nArray after moving zeroes to the end:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}