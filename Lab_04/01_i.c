#include <stdio.h>
#include <stdlib.h>

/* Structure Definition */
struct Node {
    int data;
    struct Node *next;
};

/* Function to insert node at end */
void insertAtEnd(struct Node **head, int value) {
    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    temp = *head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

/* Function to display linked list */
void display(struct Node *head) {

    if (head == NULL) {
        printf("Linked List is empty.\n");
        return;
    }

    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }

    printf("NULL\n");
}

/* Function to delete node at given position */
void deleteAtPosition(struct Node **head, int position) {

    if (*head == NULL) {
        printf("Linked List is empty.\n");
        return;
    }

    struct Node *temp = *head;

    /* Delete first node */
    if (position == 1) {
        *head = temp->next;
        free(temp);

        printf("Node deleted successfully.\n");
        return;
    }

    int i;

    for (i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    /* Invalid position */
    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position.\n");
        return;
    }

    struct Node *nextNode = temp->next->next;

    free(temp->next);

    temp->next = nextNode;

    printf("Node deleted successfully.\n");
}

int main() {
    struct Node *head = NULL;

    int n, value, position, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter node values:\n");

    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        insertAtEnd(&head, value);
    }

    printf("\nOriginal Linked List:\n");
    display(head);

    printf("\nEnter position to delete: ");
    scanf("%d", &position);

    deleteAtPosition(&head, position);

    printf("\nUpdated Linked List:\n");
    display(head);

    return 0;
}