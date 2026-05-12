#include <stdio.h>

#define MAX 100

/* Compare degree sequence */
void sort(int arr[], int n) {

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

    int n;
    int graph1[MAX][MAX];
    int graph2[MAX][MAX];

    int degree1[MAX] = {0};
    int degree2[MAX] = {0};

    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter adjacency matrix of Graph 1:\n");

    for (i = 0; i < n; i++) {

        for (j = 0; j < n; j++) {

            scanf("%d", &graph1[i][j]);

            degree1[i] += graph1[i][j];
        }
    }

    printf("\nEnter adjacency matrix of Graph 2:\n");

    for (i = 0; i < n; i++) {

        for (j = 0; j < n; j++) {

            scanf("%d", &graph2[i][j]);

            degree2[i] += graph2[i][j];
        }
    }

    sort(degree1, n);
    sort(degree2, n);

    int isomorphic = 1;

    for (i = 0; i < n; i++) {

        if (degree1[i] != degree2[i]) {

            isomorphic = 0;
            break;
        }
    }

    if (isomorphic) {
        printf("\nGraphs may be Isomorphic.\n");
    } else {
        printf("\nGraphs are NOT Isomorphic.\n");
    }

    return 0;
}