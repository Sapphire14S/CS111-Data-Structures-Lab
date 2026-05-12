#include <stdio.h>

#define MAX 100

/* Function to sort array in ascending order */
void sortArray(int arr[], int n) {
    int i, j, temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {

            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int first[MAX], second[MAX];
    int output[MAX];

    int n1, n2;
    int i, j, k = 0;

    int visited[MAX] = {0};

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

    /* Arrange elements according to first array */
    for (i = 0; i < n1; i++) {

        for (j = 0; j < n2; j++) {

            if (first[i] == second[j] && !visited[j]) {
                output[k++] = second[j];
                visited[j] = 1;
            }
        }
    }

    /* Store remaining elements */
    int remaining[MAX];
    int remCount = 0;

    for (i = 0; i < n2; i++) {

        if (!visited[i]) {
            remaining[remCount++] = second[i];
        }
    }

    /* Sort remaining elements */
    sortArray(remaining, remCount);

    /* Append remaining sorted elements */
    for (i = 0; i < remCount; i++) {
        output[k++] = remaining[i];
    }

    printf("\nReordered array:\n");

    for (i = 0; i < k; i++) {
        printf("%d ", output[i]);
    }

    printf("\n");

    return 0;
}