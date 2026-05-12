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

/* Display doubly linked list */
void display(struct Node *head) {

    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }

    printf("NULL\n");
}

/* Remove duplicate nodes */
void removeDuplicates(struct Node *head) {

    struct Node *current, *index, *duplicate;

    current = head;

    while (current != NULL) {

        index = current->next;

        while (index != NULL) {

            if (current->data == index->data) {

                duplicate = index;

                index->prev->next = index->next;

                if (index->next != NULL) {
                    index->next->prev = index->prev;
                }

                index = index->next;

                free(duplicate);
            }
            else {
                index = index->next;
            }
        }

        current = current->next;
    }
}

int main() {
    struct Node *head = NULL;

    int n, value, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter node values:\n");

    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        insertEnd(&head, value);
    }

    printf("\nOriginal Doubly Linked List:\n");
    display(head);

    removeDuplicates(head);

    printf("\nLinked List after removing duplicates:\n");
    display(head);

    return 0;
}