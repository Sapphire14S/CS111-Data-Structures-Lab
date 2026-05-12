#include <stdio.h>

/* Swap function */
void swap(int *a, int *b) {

    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Heapify function */
void heapify(int arr[], int n, int i) {

    int largest = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {

        swap(&arr[i], &arr[largest]);

        heapify(arr, n, largest);
    }
}

/* Heap Sort */
void heapSort(int arr[], int n) {

    int i;

    /* Build Max Heap */
    for (i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    /* Extract elements one by one */
    for (i = n - 1; i > 0; i--) {

        swap(&arr[0], &arr[i]);

        heapify(arr, i, 0);
    }
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

    heapSort(arr, n);

    printf("\nSorted Array:\n");

    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}