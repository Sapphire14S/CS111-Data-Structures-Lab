#include <stdio.h>
#include <stdlib.h>

/* Structure Definition */
struct Node {
    int data;
    struct Node *next;
};

/* Function to traverse and print the linked list */
void printList(struct Node *head) {

    if (head == NULL) {
        printf("Linked List is empty.\n");
        return;
    }

    printf("Linked List Elements:\n");

    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }

    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;

    /* Allocate memory */
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    /* Assign data */
    head->data = 10;
    second->data = 20;
    third->data = 30;

    /* Connect nodes */
    head->next = second;
    second->next = third;
    third->next = NULL;

    printList(head);

    return 0;
}