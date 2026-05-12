#include <stdio.h>
#include <stdlib.h>

/* Structure Definition */
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

/* Create New Node */
struct Node* createNode(int value) {

    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

/* Insert Node */
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

/* Inorder Traversal */
void inorder(struct Node *root) {

    if (root == NULL) {
        return;
    }

    inorder(root->left);

    printf("%d ", root->data);

    inorder(root->right);
}

/* Preorder Traversal */
void preorder(struct Node *root) {

    if (root == NULL) {
        return;
    }

    printf("%d ", root->data);

    preorder(root->left);

    preorder(root->right);
}

/* Postorder Traversal */
void postorder(struct Node *root) {

    if (root == NULL) {
        return;
    }

    postorder(root->left);

    postorder(root->right);

    printf("%d ", root->data);
}

/* Search Node */
struct Node* search(struct Node *root, int key) {

    if (root == NULL ||
        root->data == key) {
        return root;
    }

    if (key < root->data) {
        return search(root->left, key);
    }

    return search(root->right, key);
}

/* Find Minimum Value Node */
struct Node* findMin(struct Node *root) {

    while (root->left != NULL) {
        root = root->left;
    }

    return root;
}

/* Delete Node */
struct Node* deleteNode(struct Node *root, int key) {

    if (root == NULL) {
        return root;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    }
    else {

        /* Node with one or no child */
        if (root->left == NULL) {

            struct Node *temp = root->right;

            free(root);

            return temp;
        }
        else if (root->right == NULL) {

            struct Node *temp = root->left;

            free(root);

            return temp;
        }

        /* Node with two children */
        struct Node *temp = findMin(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

int main() {

    struct Node *root = NULL;

    int choice, value;

    while (1) {

        printf("\n===== Binary Search Tree Menu =====\n");

        printf("1. Insert Node\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Delete Node\n");
        printf("6. Search Node\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:

                printf("Enter value to insert: ");
                scanf("%d", &value);

                root = insert(root, value);

                printf("Node inserted successfully.\n");

                break;

            case 2:

                printf("Inorder Traversal:\n");

                inorder(root);

                printf("\n");

                break;

            case 3:

                printf("Preorder Traversal:\n");

                preorder(root);

                printf("\n");

                break;

            case 4:

                printf("Postorder Traversal:\n");

                postorder(root);

                printf("\n");

                break;

            case 5:

                printf("Enter value to delete: ");
                scanf("%d", &value);

                root = deleteNode(root, value);

                printf("Node deleted successfully.\n");

                break;

            case 6:

                printf("Enter value to search: ");
                scanf("%d", &value);

                if (search(root, value) != NULL) {

                    printf("Node found.\n");
                }
                else {

                    printf("Node not found.\n");
                }

                break;

            case 7:

                printf("Program terminated.\n");

                exit(0);

            default:

                printf("Invalid choice.\n");
        }
    }

    return 0;
}