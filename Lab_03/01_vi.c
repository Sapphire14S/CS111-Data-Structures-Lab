#include <stdio.h>
#include <stdlib.h>

/* Structure Definition */
struct Node {
    int data;
    struct Node *next;
};

/* Function to print linked list */
void printList(struct Node *head) {

    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }

    printf("NULL\n");
}

/* Function to insert node in sorted order */
void sortedInsert(struct Node **head, int value) {

    struct Node *newNode =
        (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    /* Insert at beginning */
    if (*head == NULL || (*head)->data >= value) {

        newNode->next = *head;
        *head = newNode;

        return;
    }

    struct Node *current = *head;

    /* Traverse to correct position */
    while (current->next != NULL &&
           current->next->data < value) {

        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

int main() {
    struct Node *head = NULL;

    sortedInsert(&head, 30);
    sortedInsert(&head, 10);
    sortedInsert(&head, 20);
    sortedInsert(&head, 25);

    printf("Sorted Linked List:\n");
    printList(head);

    return 0;
}