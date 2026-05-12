#include <stdio.h>
#include <stdlib.h>

/* Structure Definition */
struct Node {
    int data;
    struct Node *next;
};

/* Recursive function to count nodes */
int countNodes(struct Node *head) {

    if (head == NULL) {
        return 0;
    }

    return 1 + countNodes(head->next);
}

int main() {
    struct Node *head = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 10;
    second->data = 20;
    third->data = 30;

    head->next = second;
    second->next = third;
    third->next = NULL;

    printf("Number of Nodes = %d\n", countNodes(head));

    return 0;
}