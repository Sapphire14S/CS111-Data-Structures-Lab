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

/* Count half nodes */
int countHalfNodes(struct Node *root) {

    if (root == NULL) {
        return 0;
    }

    int count = 0;

    if ((root->left == NULL &&
         root->right != NULL) ||

        (root->left != NULL &&
         root->right == NULL)) {

        count = 1;
    }

    return count + countHalfNodes(root->left) + countHalfNodes(root->right);
}

int main() {

    /*
            1
          /   \
         2     3
        /
       4
    */

    struct Node *root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);

    int result = countHalfNodes(root);

    printf("Number of Half Nodes = %d\n", result);

    return 0;
}