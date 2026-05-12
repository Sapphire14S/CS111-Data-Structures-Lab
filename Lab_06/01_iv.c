#include <stdio.h>
#include <stdlib.h>

#define MAX 100

/* Stack structure */
struct Stack {
    int items[MAX];
    int top;
};

struct Stack stack1 = {.top = -1};
struct Stack stack2 = {.top = -1};

/* Push operation */
void push(struct Stack *stack, int value) {

    if (stack->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }

    stack->items[++stack->top] = value;
}

/* Pop operation */
int pop(struct Stack *stack) {

    if (stack->top == -1) {
        return -1;
    }

    return stack->items[stack->top--];
}

/* Check if stack is empty */
int isEmpty(struct Stack *stack) {
    return (stack->top == -1);
}

/* Enqueue operation */
void enqueue(int value) {

    push(&stack1, value);

    printf("%d inserted into queue.\n", value);
}

/* Dequeue operation */
void dequeue() {

    if (isEmpty(&stack1) && isEmpty(&stack2)) {
        printf("Queue Underflow\n");
        return;
    }

    /* Transfer elements if stack2 is empty */
    if (isEmpty(&stack2)) {

        while (!isEmpty(&stack1)) {
            push(&stack2, pop(&stack1));
        }
    }

    int deletedValue = pop(&stack2);

    printf("%d deleted from queue.\n", deletedValue);
}

/* Display queue */
void display() {

    int i;

    if (isEmpty(&stack1) && isEmpty(&stack2)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue Elements:\n");

    /* Display elements from stack2 */
    for (i = stack2.top; i >= 0; i--) {
        printf("%d ", stack2.items[i]);
    }

    /* Display elements from stack1 */
    for (i = 0; i <= stack1.top; i++) {
        printf("%d ", stack1.items[i]);
    }

    printf("\n");
}

int main() {

    int choice, value;

    while (1) {

        printf("\n===== Queue Using Two Stacks =====\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);

                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Program terminated.\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}