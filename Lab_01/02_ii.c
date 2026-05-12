#include <stdio.h>

#define MAX 50

/* Function to sort an array using Bubble Sort */
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
    int matrix[MAX][MAX];
    int rows, cols;
    int i, j;

    int target;
    int found = 0;
    int rowIndex, colIndex;

    int neighbors[8];
    int count = 0;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter matrix elements:\n");

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nMatrix:\n");

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nEnter the number to search: ");
    scanf("%d", &target);

    /* Find the target element */
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {

            if (matrix[i][j] == target) {
                rowIndex = i;
                colIndex = j;
                found = 1;
                break;
            }
        }

        if (found) {
            break;
        }
    }

    if (!found) {
        printf("\nElement not found in matrix.\n");
        return 0;
    }

    printf("\nElement found at position (%d, %d)\n", rowIndex, colIndex);

    /* Collect neighbors */
    for (i = rowIndex - 1; i <= rowIndex + 1; i++) {
        for (j = colIndex - 1; j <= colIndex + 1; j++) {

            if (i >= 0 && i < rows &&
                j >= 0 && j < cols &&
                !(i == rowIndex && j == colIndex)) {

                neighbors[count++] = matrix[i][j];
            }
        }
    }

    /* Sort neighbors */
    sortArray(neighbors, count);

    printf("\nNeighbors in sorted order:\n");

    for (i = 0; i < count; i++) {
        printf("%d ", neighbors[i]);
    }

    printf("\n");

    return 0;
}