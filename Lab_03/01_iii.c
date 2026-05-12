#include <stdio.h>
#include <stdlib.h>

/* Structure Definition */
struct Node {
    int data;
    struct Node *next;
};

/* Function to print every second node */
void printAlternateNodes(struct Node *head) {
    int position = 1;

    printf("Every Second Node:\n");

    while (head != NULL) {

        if (position % 2 == 0) {
            printf("%d ", head->data);
        }

        head = head->next;
        position++;
    }

    printf("\n");
}

int main() {
    struct Node *head = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;
    struct Node *fourth = NULL;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 10;
    second->data = 20;
    third->data = 30;
    fourth->data = 40;

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = NULL;

    printAlternateNodes(head);

    return 0;
}