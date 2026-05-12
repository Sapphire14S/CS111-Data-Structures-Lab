#include <stdio.h>
#include <stdlib.h>

/* Structure Definition */
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

/* Create new node */
struct Node* createNode(int value) {

    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

/* Insert node into BST */
struct Node* insert(struct Node *root, int value) {

    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

/* Print elements within range */
void printRange(struct Node *root, int k1, int k2) {

    if (root == NULL) {
        return;
    }

    /* Traverse left subtree */
    if (k1 < root->data) {
        printRange(root->left, k1, k2);
    }

    /* Print current node */
    if (root->data >= k1 &&
        root->data <= k2) {
        printf("%d ", root->data);
    }

    /* Traverse right subtree */
    if (k2 > root->data) {
        printRange(root->right, k1, k2);
    }
}

int main() {

    struct Node *root = NULL;

    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 25);
    root = insert(root, 35);

    int k1 = 10;
    int k2 = 30;

    printf("Elements in range [%d, %d]:\n", k1, k2);

    printRange(root, k1, k2);

    printf("\n");

    return 0;
}