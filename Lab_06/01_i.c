#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

/* Enqueue operation */
void enqueue(int value) {

    /* Queue Full Condition */
    if ((rear + 1) % MAX == front) {
        printf("Queue Overflow\n");
        return;
    }

    /* First element insertion */
    if (front == -1) {
        front = 0;
        rear = 0;
    }
    else {
        rear = (rear + 1) % MAX;
    }

    queue[rear] = value;

    printf("%d inserted into queue.\n", value);
}

/* Dequeue operation */
void dequeue() {

    if (front == -1) {
        printf("Queue Underflow\n");
        return;
    }

    int deletedValue = queue[front];

    /* Single element deletion */
    if (front == rear) {
        front = -1;
        rear = -1;
    }
    else {
        front = (front + 1) % MAX;
    }

    printf("%d deleted from queue.\n", deletedValue);
}

/* Display queue */
void display() {

    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }

    int i = front;

    printf("Queue Elements:\n");

    while (1) {

        printf("%d ", queue[i]);

        if (i == rear) {
            break;
        }

        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main() {

    int choice, value;

    while (1) {

        printf("\n===== Circular Queue Menu =====\n");
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