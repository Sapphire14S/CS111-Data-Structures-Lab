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

/* Function to insert a node after a given node */
void insertAfter(struct Node *prevNode, int newData) {

    if (prevNode == NULL) {
        printf("Previous node cannot be NULL.\n");
        return;
    }

    struct Node *newNode =
        (struct Node *)malloc(sizeof(struct Node));

    newNode->data = newData;

    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

int main() {
    struct Node *head = NULL;
    struct Node *second = NULL;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = NULL;

    printf("Original Linked List:\n");
    printList(head);

    insertAfter(head, 15);

    printf("\nLinked List after insertion:\n");
    printList(head);

    return 0;
}