#include <stdio.h>

#define SIZE 13

/* Function to copy array */
void copyArray(int source[], int destination[], int n) {

    int i;

    for (i = 0; i < n; i++) {
        destination[i] = source[i];
    }
}

/* Bubble Sort */
int bubbleSort(int arr[], int n) {

    int i, j, temp;
    int swaps = 0;

    for (i = 0; i < n - 1; i++) {

        for (j = 0; j < n - i - 1; j++) {

            if (arr[j] > arr[j + 1]) {

                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swaps++;
            }
        }
    }

    return swaps;
}

/* Selection Sort */
int selectionSort(int arr[], int n) {

    int i, j, minIndex, temp;
    int swaps = 0;

    for (i = 0; i < n - 1; i++) {

        minIndex = i;

        for (j = i + 1; j < n; j++) {

            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {

            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;

            swaps++;
        }
    }

    return swaps;
}

/* Insertion Sort */
int insertionSort(int arr[], int n) {

    int i, j, key;
    int swaps = 0;

    for (i = 1; i < n; i++) {

        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {

            arr[j + 1] = arr[j];
            j--;

            swaps++;
        }

        arr[j + 1] = key;
    }

    return swaps;
}

int main() {

    int original[SIZE] =
    {10, 2, 3, 1, 56, 48, 24, 79, 11, 90, 35, 23, 36};

    int bubble[SIZE];
    int selection[SIZE];
    int insertion[SIZE];

    copyArray(original, bubble, SIZE);
    copyArray(original, selection, SIZE);
    copyArray(original, insertion, SIZE);

    int bubbleSwaps = bubbleSort(bubble, SIZE);

    int selectionSwaps = selectionSort(selection, SIZE);

    int insertionSwaps = insertionSort(insertion, SIZE);

    printf("Bubble Sort Swaps    = %d\n", bubbleSwaps);

    printf("Selection Sort Swaps = %d\n", selectionSwaps);

    printf("Insertion Sort Swaps = %d\n", insertionSwaps);

    printf("\n");

    if (bubbleSwaps <= selectionSwaps && bubbleSwaps <= insertionSwaps) {
        printf("Bubble Sort uses minimum swaps.\n");
    } else if (selectionSwaps <= bubbleSwaps && selectionSwaps <= insertionSwaps) {
        printf("Selection Sort uses minimum swaps.\n");
    }
    else {
        printf("Insertion Sort uses minimum swaps.\n");
    }

    return 0;
}