#include <stdio.h>
#include <stdlib.h>

/* Structure Definition for Stack Node */
struct Node {
    int data;
    struct Node *next;
};

/* Push operation */
void push(struct Node **top, int value) {

    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = *top;

    *top = newNode;
}

/* Pop operation */
int pop(struct Node **top) {

    if (*top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }

    struct Node *temp = *top;
    int poppedValue = temp->data;

    *top = (*top)->next;

    free(temp);

    return poppedValue;
}

/* Display stack */
void display(struct Node *top) {

    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    while (top != NULL) {
        printf("%d\n", top->data);
        top = top->next;
    }
}

/* Copy stack */
void copyStack(struct Node *source, struct Node **destination) {

    struct Node *tempStack = NULL;
    struct Node *temp = source;

    /* Reverse source into temp stack */
    while (temp != NULL) {
        push(&tempStack, temp->data);
        temp = temp->next;
    }

    /* Restore original order into destination */
    while (tempStack != NULL) {
        push(destination, pop(&tempStack));
    }
}

int main() {

    struct Node *stack1 = NULL;
    struct Node *stack2 = NULL;

    push(&stack1, 10);
    push(&stack1, 20);
    push(&stack1, 30);
    push(&stack1, 40);

    printf("Original Stack:\n");
    display(stack1);

    copyStack(stack1, &stack2);

    printf("\nCopied Stack:\n");
    display(stack2);

    return 0;
}