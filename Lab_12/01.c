#include <stdio.h>
#include <stdlib.h>

/* Structure Definition */
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    int height;
};

/* Utility Functions */

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(struct Node *node) {

    if (node == NULL) {
        return 0;
    }

    return node->height;
}

int getBalance(struct Node *node) {

    if (node == NULL) {
        return 0;
    }

    return height(node->left) - height(node->right);
}

/* Create New Node */
struct Node* createNode(int value) {

    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;

    return newNode;
}

/* Right Rotation */
struct Node* rightRotate(struct Node *y) {

    struct Node *x = y->left;
    struct Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;

    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

/* Left Rotation */
struct Node* leftRotate(struct Node *x) {

    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;

    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

/* Insert Node */
struct Node* insert(struct Node *node, int value) {

    if (node == NULL) {
        return createNode(value);
    }

    if (value < node->data) {
        node->left = insert(node->left, value);
    }
    else if (value > node->data) {
        node->right = insert(node->right, value);
    }
    else {
        return node;
    }

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    /* Left Left Case */
    if (balance > 1 &&
        value < node->left->data) {

        return rightRotate(node);
    }

    /* Right Right Case */
    if (balance < -1 &&
        value > node->right->data) {

        return leftRotate(node);
    }

    /* Left Right Case */
    if (balance > 1 &&
        value > node->left->data) {

        node->left = leftRotate(node->left);

        return rightRotate(node);
    }

    /* Right Left Case */
    if (balance < -1 &&
        value < node->right->data) {

        node->right = rightRotate(node->right);

        return leftRotate(node);
    }

    return node;
}

/* Find Minimum Node */
struct Node* minValueNode(struct Node *node) {

    struct Node *current = node;

    while (current->left != NULL) {
        current = current->left;
    }

    return current;
}

/* Delete Node */
struct Node* deleteNode(struct Node *root, int value) {

    if (root == NULL) {
        return root;
    }

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {

        if ((root->left == NULL) ||
            (root->right == NULL)) {

            struct Node *temp = root->left ? root->left : root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else {
                *root = *temp;
            }

            free(temp);
        }
        else {

            struct Node *temp = minValueNode(root->right);

            root->data = temp->data;

            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (root == NULL) {
        return root;
    }

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    /* Left Left */
    if (balance > 1 &&
        getBalance(root->left) >= 0) {

        return rightRotate(root);
    }

    /* Left Right */
    if (balance > 1 &&
        getBalance(root->left) < 0) {

        root->left = leftRotate(root->left);

        return rightRotate(root);
    }

    /* Right Right */
    if (balance < -1 &&
        getBalance(root->right) <= 0) {

        return leftRotate(root);
    }

    /* Right Left */
    if (balance < -1 &&
        getBalance(root->right) > 0) {

        root->right = rightRotate(root->right);

        return leftRotate(root);
    }

    return root;
}

/* Search Node */
int search(struct Node *root, int key) {

    if (root == NULL) {
        return 0;
    }

    if (root->data == key) {
        return 1;
    }

    if (key < root->data) {

        return search(root->left, key);
    }

    return search(root->right, key);
}

/* Display Tree */
void display(struct Node *root) {

    if (root == NULL) {
        return;
    }

    printf("Node: %d ", root->data);

    if (root->left != NULL) {
        printf(" Left Child: %d ", root->left->data);
    } else {
        printf(" Left Child: NULL ");
    }

    if (root->right != NULL) {
        printf(" Right Child: %d", root->right->data);
    } else {
        printf(" Right Child: NULL");
    }

    printf("\n");

    display(root->left);
    display(root->right);
}

/* Display Balance Factors */
void displayBalance(struct Node *root) {

    if (root == NULL) {
        return;
    }

    printf("Node %d -> Balance Factor = %d\n", root->data, getBalance(root));

    displayBalance(root->left);
    displayBalance(root->right);
}

int main() {

    struct Node *root = NULL;

    int choice, value;

    while (1) {

        printf("\n===== AVL Tree Menu =====\n");

        printf("1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Search Element\n");
        printf("4. Display Tree\n");
        printf("5. Display Balance Factors\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:

                printf("Enter value to insert: ");
                scanf("%d", &value);

                root = insert(root, value);

                printf("Element inserted.\n");

                break;

            case 2:

                printf("Enter value to delete: ");
                scanf("%d", &value);

                root = deleteNode(root, value);

                printf("Element deleted.\n");

                break;

            case 3:

                printf("Enter value to search: ");
                scanf("%d", &value);

                if (search(root, value)) {
                    printf("Element found.\n");
                } else {
                    printf("Element not found.\n");
                }

                break;

            case 4:

                printf("\nAVL Tree:\n");

                display(root);

                break;

            case 5:

                printf("\nBalance Factors:\n");

                displayBalance(root);

                break;

            case 6:

                printf("Program terminated.\n");

                exit(0);

            default:

                printf("Invalid choice.\n");
        }
    }

    return 0;
}