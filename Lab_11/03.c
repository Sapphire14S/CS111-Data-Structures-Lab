#include <stdio.h>
#include <stdlib.h>

#define MAX 100

/* Min Heap structure */
struct MinHeap {
    int arr[MAX];
    int size;
};

/* Swap function */
void swap(int *a, int *b) {

    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Heapify downward */
void heapify(struct MinHeap *heap, int index) {

    int smallest = index;

    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size &&
        heap->arr[left] <
        heap->arr[smallest]) {

        smallest = left;
    }

    if (right < heap->size &&
        heap->arr[right] <
        heap->arr[smallest]) {

        smallest = right;
    }

    if (smallest != index) {

        swap(&heap->arr[index], &heap->arr[smallest]);

        heapify(heap, smallest);
    }
}

/* Extract minimum */
int extractMin(struct MinHeap *heap) {

    int minValue = heap->arr[0];

    heap->arr[0] = heap->arr[heap->size - 1];

    heap->size--;

    heapify(heap, 0);

    return minValue;
}

int main() {

    struct MinHeap heap =
    {
        {5, 10, 20, 30, 40, 50},
        6
    };

    int k;

    printf("Enter value of k: ");
    scanf("%d", &k);

    if (k > heap.size || k <= 0) {

        printf("Invalid value of k.\n");
        return 0;
    }

    int result;
    int i;

    for (i = 0; i < k; i++) {

        result = extractMin(&heap);
    }

    printf("%dth smallest element = %d\n", k, result);

    return 0;
}