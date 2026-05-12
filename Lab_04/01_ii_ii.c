#include <stdio.h>
#include <stdlib.h>

/* Structure Definition */
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

/* Insert at end */
void insertEnd(int value) {

    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

/* Display forward */
void displayForward() {

    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Forward Traversal:\n");

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

/* Display reverse */
void displayReverse() {

    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    printf("Reverse Traversal:\n");

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }

    printf("NULL\n");
}

/* Search element */
void search(int key) {

    struct Node *temp = head;
    int position = 1;

    while (temp != NULL) {

        if (temp->data == key) {
            printf("Element found at position %d\n",
                   position);
            return;
        }

        temp = temp->next;
        position++;
    }

    printf("Element not found.\n");
}

int main() {
    int choice, value;

    while (1) {

        printf("\n===== Doubly Linked List Menu =====\n");
        printf("1. Insert at End\n");
        printf("2. Display Forward\n");
        printf("3. Display Reverse\n");
        printf("4. Search\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter value: ");
                scanf("%d", &value);

                insertEnd(value);
                break;

            case 2:
                displayForward();
                break;

            case 3:
                displayReverse();
                break;

            case 4:
                printf("Enter value to search: ");
                scanf("%d", &value);

                search(value);
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}