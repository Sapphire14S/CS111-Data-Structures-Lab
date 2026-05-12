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

/* Heapify upward */
void heapifyUp(struct MinHeap *heap, int index) {

    while (index > 0 &&
           heap->arr[(index - 1) / 2] >
           heap->arr[index]) {

        swap(&heap->arr[(index - 1) / 2], &heap->arr[index]);

        index = (index - 1) / 2;
    }
}

/* Heapify downward */
void heapifyDown(struct MinHeap *heap, int index) {

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

        heapifyDown(heap, smallest);
    }
}

/* Insert key */
void insert(struct MinHeap *heap, int value) {

    if (heap->size == MAX) {
        printf("Heap Overflow\n");
        return;
    }

    heap->arr[heap->size] = value;

    heapifyUp(heap, heap->size);

    heap->size++;
}

/* Get minimum element */
int getMin(struct MinHeap *heap) {

    if (heap->size <= 0) {
        return -1;
    }

    return heap->arr[0];
}

/* Extract minimum element */
int extractMin(struct MinHeap *heap) {

    if (heap->size <= 0) {
        return -1;
    }

    int minValue = heap->arr[0];

    heap->arr[0] = heap->arr[heap->size - 1];

    heap->size--;

    heapifyDown(heap, 0);

    return minValue;
}

/* Display heap */
void display(struct MinHeap *heap) {

    int i;

    for (i = 0; i < heap->size; i++) {
        printf("%d ", heap->arr[i]);
    }

    printf("\n");
}

int main() {

    struct MinHeap heap;

    heap.size = 0;

    insert(&heap, 40);
    insert(&heap, 20);
    insert(&heap, 10);
    insert(&heap, 30);
    insert(&heap, 5);

    printf("Min Heap Elements:\n");
    display(&heap);

    printf("\nMinimum Element = %d\n", getMin(&heap));

    printf("Extracted Minimum = %d\n", extractMin(&heap));

    printf("\nHeap after Extraction:\n");
    display(&heap);

    return 0;
}