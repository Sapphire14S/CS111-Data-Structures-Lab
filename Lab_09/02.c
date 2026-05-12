#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

/* Check BST using min-max range */
int isBST(struct Node *root, int min, int max) {

    if (root == NULL) {
        return 1;
    }

    if (root->data <= min || root->data >= max) {
        return 0;
    }

    return isBST(root->left, min, root->data)
           &&
           isBST(root->right, root->data, max);
}

int main() {

    /*
             20
            /  \
          10    30
         / \    / \
        5  15  25 35
    */

    struct Node *root = createNode(20);

    root->left = createNode(10);
    root->right = createNode(30);

    root->left->left = createNode(5);
    root->left->right = createNode(15);

    root->right->left = createNode(25);
    root->right->right = createNode(35);

    if (isBST(root, INT_MIN, INT_MAX)) {
        printf("The binary tree is a BST.\n");
    } else {
        printf("The binary tree is NOT a BST.\n");
    }

    return 0;
}