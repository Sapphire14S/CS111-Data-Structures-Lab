#include <stdio.h>

int isSubset(int arr1[], int size1, int arr2[], int size2) {
    int i, j, found;

    for (i = 0; i < size2; i++) {
        found = 0;

        for (j = 0; j < size1; j++) {
            if (arr2[i] == arr1[j]) {
                found = 1;
                break;
            }
        }

        if (!found) {
            return 0;
        }
    }

    return 1;
}

int main() {
    int size1, size2, i;

    printf("Enter size of first array: ");
    scanf("%d", &size1);

    int arr1[size1];

    printf("Enter elements of first array:\n");
    for (i = 0; i < size1; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter size of second array: ");
    scanf("%d", &size2);

    int arr2[size2];

    printf("Enter elements of second array:\n");
    for (i = 0; i < size2; i++) {
        scanf("%d", &arr2[i]);
    }

    if (isSubset(arr1, size1, arr2, size2)) {
        printf("\nSecond array is a subset of the first array.\n");
    } else {
        printf("\nSecond array is NOT a subset of the first array.\n");
    }

    return 0;
}