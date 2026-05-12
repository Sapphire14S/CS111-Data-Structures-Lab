#include <stdio.h>

#define MAX 100

/* Function to sort array in descending order */
void sortDescending(int arr[], int n) {
    int i, j, temp;

    for (i = 0; i < n - 1; i++) {

        for (j = 0; j < n - i - 1; j++) {

            if (arr[j] < arr[j + 1]) {

                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

/* Function to check if value already exists */
int exists(int arr[], int size, int value) {
    int i;

    for (i = 0; i < size; i++) {

        if (arr[i] == value) {
            return 1;
        }
    }

    return 0;
}

int main() {
    int first[MAX], second[MAX], output[MAX];
    int n1, n2;
    int i, j, k = 0;

    printf("Enter size of first array: ");
    scanf("%d", &n1);

    printf("Enter elements of first array:\n");

    for (i = 0; i < n1; i++) {
        scanf("%d", &first[i]);
    }

    printf("Enter size of second array: ");
    scanf("%d", &n2);

    printf("Enter elements of second array:\n");

    for (i = 0; i < n2; i++) {
        scanf("%d", &second[i]);
    }

    /* Add common elements in first array order */
    for (i = 0; i < n1; i++) {

        for (j = 0; j < n2; j++) {

            if (first[i] == second[j] &&
                !exists(output, k, first[i])) {

                output[k++] = first[i];
                break;
            }
        }
    }

    /* Store remaining elements */
    int remaining[MAX];
    int remCount = 0;

    for (i = 0; i < n2; i++) {

        if (!exists(output, k, second[i])) {
            remaining[remCount++] = second[i];
        }
    }

    /* Remove duplicates from remaining */
    int unique[MAX];
    int uniqueCount = 0;

    for (i = 0; i < remCount; i++) {

        if (!exists(unique, uniqueCount, remaining[i])) {
            unique[uniqueCount++] = remaining[i];
        }
    }

    /* Sort remaining elements in descending order */
    sortDescending(unique, uniqueCount);

    /* Append remaining elements */
    for (i = 0; i < uniqueCount; i++) {
        output[k++] = unique[i];
    }

    printf("\nFinal Output Array:\n");

    for (i = 0; i < k; i++) {
        printf("%d ", output[i]);
    }

    printf("\n");

    return 0;
}