#include <stdio.h>
#include <string.h>

#define MAX 100

/* Stack structure */
struct Stack {
    char items[MAX];
    int top;
};

/* Push operation */
void push(struct Stack *stack, char value) {
    stack->items[++stack->top] = value;
}

/* Pop operation */
char pop(struct Stack *stack) {

    if (stack->top == -1) {
        return '\0';
    }

    return stack->items[stack->top--];
}

/* Function to check matching brackets */
int isMatchingPair(char open, char close) {

    return ((open == '(' && close == ')') ||
            (open == '{' && close == '}') ||
            (open == '[' && close == ']'));
}

/* Function to check balanced parentheses */
int isBalanced(char expression[]) {

    struct Stack stack;
    stack.top = -1;

    int i;

    for (i = 0; expression[i] != '\0'; i++) {

        char ch = expression[i];

        if (ch == '(' || ch == '{' || ch == '[') {

            push(&stack, ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {

            if (stack.top == -1) {
                return 0;
            }

            char topElement = pop(&stack);

            if (!isMatchingPair(topElement, ch)) {
                return 0;
            }
        }
    }

    return (stack.top == -1);
}

int main() {

    char expression[MAX];

    printf("Enter an expression: ");
    scanf("%s", expression);

    if (isBalanced(expression)) {
        printf("The expression is well formed.\n");
    }
    else {
        printf("The expression is NOT well formed.\n");
    }

    return 0;
}