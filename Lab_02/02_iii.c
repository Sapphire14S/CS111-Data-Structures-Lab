#include <stdio.h>

#define MAX 50

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    int matrix[MAX][MAX];
    int dp[MAX][MAX];

    int n;
    int i, j;

    printf("Enter size of matrix (N x N): ");
    scanf("%d", &n);

    printf("Enter matrix elements:\n");

    for (i = 0; i < n; i++) {

        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    /* Initialize first cell */
    dp[0][0] = matrix[0][0];

    /* Fill first row */
    for (j = 1; j < n; j++) {
        dp[0][j] = dp[0][j - 1] + matrix[0][j];
    }

    /* Fill first column */
    for (i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][0] + matrix[i][0];
    }

    /* Fill remaining cells */
    for (i = 1; i < n; i++) {

        for (j = 1; j < n; j++) {

            dp[i][j] = matrix[i][j] +
                       min(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    printf("\nMinimum Path Sum = %d\n", dp[n - 1][n - 1]);

    /* Trace path */
    int path[MAX * 2];
    int count = 0;

    i = n - 1;
    j = n - 1;

    while (i > 0 || j > 0) {

        path[count++] = matrix[i][j];

        if (i == 0) {
            j--;
        }
        else if (j == 0) {
            i--;
        }
        else if (dp[i - 1][j] < dp[i][j - 1]) {
            i--;
        }
        else {
            j--;
        }
    }

    path[count++] = matrix[0][0];

    printf("Path: ");

    for (i = count - 1; i >= 0; i--) {

        printf("%d", path[i]);

        if (i != 0) {
            printf(" -> ");
        }
    }

    printf("\n");

    return 0;
}