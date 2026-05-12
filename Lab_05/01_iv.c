#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

/* Stack structure */
struct Stack {
    int items[MAX];
    int top;
};

/* Push operation */
void push(struct Stack *stack, int value) {
    stack->items[++stack->top] = value;
}

/* Pop operation */
int pop(struct Stack *stack) {

    if (stack->top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }

    return stack->items[stack->top--];
}

/* Evaluate postfix expression */
int evaluatePostfix(char expression[]) {

    struct Stack stack;
    stack.top = -1;

    int i;

    for (i = 0; expression[i] != '\0'; i++) {

        char ch = expression[i];

        if (isdigit(ch)) {

            push(&stack, ch - '0');
        }
        else if (ch == '+' ||
                 ch == '-' ||
                 ch == '*' ||
                 ch == '/') {

            int operand2 = pop(&stack);
            int operand1 = pop(&stack);

            switch (ch) {

                case '+':
                    push(&stack, operand1 + operand2);
                    break;

                case '-':
                    push(&stack, operand1 - operand2);
                    break;

                case '*':
                    push(&stack, operand1 * operand2);
                    break;

                case '/':
                    push(&stack, operand1 / operand2);
                    break;
            }
        }
    }

    return pop(&stack);
}

int main() {

    char postfix[] = "1273--/215+*+";

    int result = evaluatePostfix(postfix);

    printf("Postfix Expression: 12 7 3 - - / 2 1 5 + * +\n");

    printf("Result = %d\n", result);

    return 0;
}