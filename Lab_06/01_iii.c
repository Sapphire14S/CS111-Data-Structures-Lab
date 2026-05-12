#include <stdio.h>
#include <stdlib.h>

/* Structure Definition */
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

/* Insert node at end */
void insertEnd(int value) {

    struct Node *newNode, *last;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;

    /* First node insertion */
    if (head == NULL) {

        newNode->next = newNode;
        newNode->prev = newNode;

        head = newNode;

        return;
    }

    last = head->prev;

    newNode->next = head;
    newNode->prev = last;

    last->next = newNode;
    head->prev = newNode;
}

/* Display forward */
void displayForward() {

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;

    printf("Forward Traversal:\n");

    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(HEAD)\n");
}

/* Display reverse */
void displayReverse() {

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head->prev;

    printf("Reverse Traversal:\n");

    do {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    } while (temp != head->prev);

    printf("(TAIL)\n");
}

int main() {

    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertEnd(40);

    displayForward();

    printf("\n");

    displayReverse();

    return 0;
}