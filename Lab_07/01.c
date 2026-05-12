#include <stdio.h>
#include <stdlib.h>

#define MAX 100

/* Structure Definition */
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

/* Queue for level order traversal */
struct Node* queue[MAX];
int front = -1;
int rear = -1;

/* Create new node */
struct Node* createNode(int value) {

    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

/* Enqueue */
void enqueue(struct Node *node) {

    if (rear == MAX - 1) {
        return;
    }

    if (front == -1) {
        front = 0;
    }

    queue[++rear] = node;
}

/* Dequeue */
struct Node* dequeue() {

    if (front == -1 || front > rear) {
        return NULL;
    }

    return queue[front++];
}

/* Check if queue is empty */
int isEmpty() {
    return (front == -1 || front > rear);
}

/* Find level with maximum sum */
void findMaxLevelSum(struct Node *root) {

    if (root == NULL) {
        return;
    }

    enqueue(root);

    int maxSum = -99999;
    int maxLevel = 0;
    int currentLevel = 0;

    while (!isEmpty()) {

        int levelSize = rear - front + 1;
        int levelSum = 0;

        currentLevel++;

        while (levelSize--) {

            struct Node *temp = dequeue();

            levelSum += temp->data;

            if (temp->left != NULL) {
                enqueue(temp->left);
            }

            if (temp->right != NULL) {
                enqueue(temp->right);
            }
        }

        printf("Level %d Sum = %d\n", currentLevel, levelSum);

        if (levelSum > maxSum) {
            maxSum = levelSum;
            maxLevel = currentLevel;
        }
    }

    printf("\nLevel with Maximum Sum = %d\n", maxLevel);

    printf("Maximum Sum = %d\n", maxSum);
}

int main() {

    /*
            1
          /   \
         2     3
        / \   / \
       4   5 6   7
    */

    struct Node *root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);

    root->right->left = createNode(6);
    root->right->right = createNode(7);

    findMaxLevelSum(root);

    return 0;
}