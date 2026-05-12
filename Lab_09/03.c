#include <stdio.h>
#include <stdlib.h>

#define MAX 100

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

/* Store inorder traversal */
void inorder(struct Node *root, int arr[], int *index) {

    if (root == NULL) {
        return;
    }

    inorder(root->left, arr, index);

    arr[(*index)++] = root->data;

    inorder(root->right, arr, index);
}

/* Compare arrays */
int compareArrays(int arr1[], int arr2[], int n1, int n2) {

    if (n1 != n2) {
        return 0;
    }

    int i;

    for (i = 0; i < n1; i++) {
        if (arr1[i] != arr2[i]) {
            return 0;
        }
    }

    return 1;
}

int main() {

    struct Node *root1 = NULL;
    struct Node *root2 = NULL;

    int bst1[] = {10, 5, 20, 15, 30};
    int bst2[] = {10, 20, 15, 30, 5};

    int n = 5;
    int i;

    for (i = 0; i < n; i++) {
        root1 = insert(root1, bst1[i]);
        root2 = insert(root2, bst2[i]);
    }

    int inorder1[MAX];
    int inorder2[MAX];

    int index1 = 0;
    int index2 = 0;

    inorder(root1, inorder1, &index1);
    inorder(root2, inorder2, &index2);

    if (compareArrays(inorder1, inorder2, index1, index2)) {
        printf("Both BSTs contain same elements.\n");
    } else {
        printf("Both BSTs do NOT contain same elements.\n");
    }

    return 0;
}