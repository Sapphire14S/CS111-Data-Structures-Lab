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

/* Find LCA in BST */
struct Node* findLCA(struct Node *root, int n1, int n2) {

    if (root == NULL) {
        return NULL;
    }

    if (n1 < root->data && n2 < root->data) {
        return findLCA(root->left, n1, n2);
    }

    if (n1 > root->data && n2 > root->data) {
        return findLCA(root->right, n1, n2);
    }

    return root;
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

    int n1 = 5;
    int n2 = 15;

    struct Node *lca = findLCA(root, n1, n2);

    if (lca != NULL) {
        printf("Lowest Common Ancestor of %d and %d = %d\n", n1, n2, lca->data);
    }

    return 0;
}