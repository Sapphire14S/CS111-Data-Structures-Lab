#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int queue[MAX];

int front = -1;
int rear = -1;

/* BFS Queue Operations */
void enqueue(int value) {

    if (rear == MAX - 1) {
        return;
    }

    if (front == -1) {
        front = 0;
    }

    queue[++rear] = value;
}

int dequeue() {

    if (front == -1 ||
        front > rear) {

        return -1;
    }

    return queue[front++];
}

/* Depth First Search */
void DFS(int vertex, int n) {

    int i;

    visited[vertex] = 1;

    printf("%d ", vertex);

    for (i = 0; i < n; i++) {

        if (graph[vertex][i] == 1 && !visited[i]) {

            DFS(i, n);
        }
    }
}

/* Breadth First Search */
void BFS(int start, int n) {

    int i;

    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

    enqueue(start);

    visited[start] = 1;

    while (front <= rear) {

        int current = dequeue();

        printf("%d ", current);

        for (i = 0; i < n; i++) {

            if (graph[current][i] == 1 && !visited[i]) {

                enqueue(i);

                visited[i] = 1;
            }
        }
    }
}

int main() {

    int n, i, j;
    int start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for (i = 0; i < n; i++) {

        for (j = 0; j < n; j++) {

            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    /* DFS */
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("\nDFS Traversal:\n");

    DFS(start, n);

    /* Reset queue */
    front = -1;
    rear = -1;

    printf("\n\nBFS Traversal:\n");

    BFS(start, n);

    printf("\n");

    return 0;
}