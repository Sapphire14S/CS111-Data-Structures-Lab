#include <stdio.h>
#include <stdlib.h>

/* Structure Definition */
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

/* Insert node at end */
void insertEnd(struct Node **head, int value) {

    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->prev = NULL;
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
    newNode->prev = temp;
}

/* Display list */
void display(struct Node *head) {

    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }

    printf("NULL\n");
}

/* Split doubly linked list */
void splitList(struct Node *head,
               struct Node **head1,
               struct Node **head2,
               int position) {

    int count = 1;

    struct Node *temp = head;

    while (temp != NULL && count < position) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Invalid position.\n");
        return;
    }

    *head1 = head;
    *head2 = temp->next;

    if (temp->next != NULL) {
        temp->next->prev = NULL;
    }

    temp->next = NULL;
}

int main() {
    struct Node *head = NULL;
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;

    int n, value, position, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter node values:\n");

    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        insertEnd(&head, value);
    }

    printf("\nOriginal Doubly Linked List:\n");
    display(head);

    printf("\nEnter split position: ");
    scanf("%d", &position);

    splitList(head, &head1, &head2, position);

    printf("\nFirst Linked List:\n");
    display(head1);

    printf("\nSecond Linked List:\n");
    display(head2);

    return 0;
}