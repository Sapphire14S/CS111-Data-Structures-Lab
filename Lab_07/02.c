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

/* Search value in inorder array */
int search(int inorder[], int start, int end, int value) {

    int i;

    for (i = start; i <= end; i++) {

        if (inorder[i] == value) {
            return i;
        }
    }

    return -1;
}

int preorderIndex = 0;

/* Construct binary tree */
struct Node* buildTree(int preorder[], int inorder[], int start, int end) {

    if (start > end) {
        return NULL;
    }

    int current = preorder[preorderIndex++];

    struct Node *node = createNode(current);

    if (start == end) {
        return node;
    }

    int inorderIndex = search(inorder, start, end, current);

    node->left = buildTree(preorder, inorder, start, inorderIndex - 1);

    node->right = buildTree(preorder, inorder, inorderIndex + 1, end);

    return node;
}

/* Inorder traversal */
void inorderTraversal(struct Node *root) {

    if (root == NULL) {
        return;
    }

    inorderTraversal(root->left);

    printf("%d ", root->data);

    inorderTraversal(root->right);
}

int main() {

    int preorder[] = {1, 2, 4, 5, 3, 6, 7};
    int inorder[]  = {4, 2, 5, 1, 6, 3, 7};

    int n = sizeof(preorder) / sizeof(preorder[0]);

    struct Node *root = buildTree(preorder, inorder, 0, n - 1);

    printf("Inorder Traversal of Constructed Tree:\n");

    inorderTraversal(root);

    printf("\n");

    return 0;
}