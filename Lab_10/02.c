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

/* Insert into BST */
struct Node* insert(struct Node *root, int value) {

    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

/* Store inorder traversal */
void inorderStore(struct Node *root, int arr[], int *index) {

    if (root == NULL) {
        return;
    }

    inorderStore(root->left, arr, index);

    arr[(*index)++] = root->data;

    inorderStore(root->right, arr, index);
}

/* Merge two sorted arrays */
void mergeArrays(int arr1[], int n1, int arr2[], int n2, int merged[], int *size) {

    int i = 0;
    int j = 0;
    int k = 0;

    while (i < n1 && j < n2) {

        if (arr1[i] < arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }

    while (i < n1) {
        merged[k++] = arr1[i++];
    }

    while (j < n2) {
        merged[k++] = arr2[j++];
    }

    *size = k;
}

/* Create balanced BST from sorted array */
struct Node* sortedArrayToBST(int arr[], int start, int end) {

    if (start > end) {
        return NULL;
    }

    int mid = (start + end) / 2;

    struct Node *root =
        createNode(arr[mid]);

    root->left = sortedArrayToBST(arr, start, mid - 1);

    root->right = sortedArrayToBST(arr, mid + 1, end);

    return root;
}

/* Inorder traversal */
void inorder(struct Node *root) {

    if (root == NULL) {
        return;
    }

    inorder(root->left);

    printf("%d ", root->data);

    inorder(root->right);
}

int main() {

    struct Node *root1 = NULL;
    struct Node *root2 = NULL;

    /* First BST */
    root1 = insert(root1, 10);
    root1 = insert(root1, 5);
    root1 = insert(root1, 15);

    /* Second BST */
    root2 = insert(root2, 20);
    root2 = insert(root2, 3);
    root2 = insert(root2, 25);

    int arr1[MAX];
    int arr2[MAX];

    int n1 = 0;
    int n2 = 0;

    inorderStore(root1, arr1, &n1);
    inorderStore(root2, arr2, &n2);

    int merged[MAX];
    int mergedSize;

    mergeArrays(arr1, n1, arr2, n2, merged, &mergedSize);

    struct Node *mergedBST = sortedArrayToBST(merged, 0, mergedSize - 1);

    printf("Inorder Traversal of Merged BST:\n");

    inorder(mergedBST);

    printf("\n");

    return 0;
}