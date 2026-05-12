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

/* Reverse inorder traversal */
void kthLargest(struct Node *root, int k, int *count, int *result) {

    if (root == NULL || *count >= k) {
        return;
    }

    kthLargest(root->right, k, count, result);

    (*count)++;

    if (*count == k) {
        *result = root->data;
        return;
    }

    kthLargest(root->left, k, count, result);
}

int main() {

    struct Node *root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    int k;

    printf("Enter value of k: ");
    scanf("%d", &k);

    int count = 0;
    int result = -1;

    kthLargest(root, k, &count, &result);

    if (result != -1) {
        printf("%dth largest element = %d\n", k, result);
    } else {
        printf("Invalid value of k.\n");
    }

    return 0;
}