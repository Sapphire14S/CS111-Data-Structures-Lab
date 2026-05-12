#include <stdio.h>
#include <stdlib.h>

/* Structure Definition */
struct Node {
    int data;
    struct Node *next;
};

struct Node *last = NULL;

/* Insert at end */
void insertEnd(int value) {
    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (last == NULL) {
        last = newNode;
        last->next = last;
        return;
    }

    newNode->next = last->next;
    last->next = newNode;
    last = newNode;
}

/* Display list */
void display() {

    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = last->next;

    printf("Circular Linked List:\n");

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);

    printf("(HEAD)\n");
}

/* Search element */
void search(int key) {

    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = last->next;
    int position = 1;
    int found = 0;

    do {

        if (temp->data == key) {
            found = 1;
            break;
        }

        temp = temp->next;
        position++;

    } while (temp != last->next);

    if (found) {
        printf("Element found at position %d\n", position);
    } else {
        printf("Element not found.\n");
    }
}

int main() {
    int choice, value;

    while (1) {

        printf("\n===== Circular Linked List Menu =====\n");
        printf("1. Insert at End\n");
        printf("2. Display\n");
        printf("3. Search\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter value: ");
                scanf("%d", &value);

                insertEnd(value);
                break;

            case 2:
                display();
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);

                search(value);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}