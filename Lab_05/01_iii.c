#include <stdio.h>
#include <string.h>
#include <ctype.h>

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

/* Peek operation */
char peek(struct Stack *stack) {

    if (stack->top == -1) {
        return '\0';
    }

    return stack->items[stack->top];
}

/* Operator precedence */
int precedence(char operator) {

    if (operator == '+' || operator == '-') {
        return 1;
    }

    if (operator == '*' || operator == '/') {
        return 2;
    }

    if (operator == '^') {
        return 3;
    }

    return 0;
}

/* Reverse string */
void reverse(char expression[]) {

    int start = 0;
    int end = strlen(expression) - 1;

    char temp;

    while (start < end) {

        temp = expression[start];
        expression[start] = expression[end];
        expression[end] = temp;

        start++;
        end--;
    }
}

/* Infix to Postfix */
void infixToPostfix(char infix[], char postfix[]) {

    struct Stack stack;
    stack.top = -1;

    int i, k = 0;

    for (i = 0; infix[i] != '\0'; i++) {

        char ch = infix[i];

        if (isalnum(ch)) {

            postfix[k++] = ch;
        }
        else if (ch == '(') {

            push(&stack, ch);
        }
        else if (ch == ')') {

            while (peek(&stack) != '(') {
                postfix[k++] = pop(&stack);
            }

            pop(&stack);
        }
        else {

            while (stack.top != -1 &&
                   precedence(peek(&stack)) >= precedence(ch)) {

                postfix[k++] = pop(&stack);
            }

            push(&stack, ch);
        }
    }

    while (stack.top != -1) {
        postfix[k++] = pop(&stack);
    }

    postfix[k] = '\0';
}

/* Infix to Prefix */
void infixToPrefix(char infix[], char prefix[]) {

    char reversed[MAX];
    char postfix[MAX];

    strcpy(reversed, infix);

    reverse(reversed);

    int i;

    for (i = 0; reversed[i] != '\0'; i++) {

        if (reversed[i] == '(') {
            reversed[i] = ')';
        }
        else if (reversed[i] == ')') {
            reversed[i] = '(';
        }
    }

    infixToPostfix(reversed, postfix);

    reverse(postfix);

    strcpy(prefix, postfix);
}

int main() {

    char infix1[] = "(A-B)*(D/E)";
    char postfix1[MAX], prefix1[MAX];

    char infix2[] = "A*(B+D)/(E-F*(G+H/K))";
    char postfix2[MAX], prefix2[MAX];

    /* Expression 1 */
    infixToPostfix(infix1, postfix1);
    infixToPrefix(infix1, prefix1);

    printf("Expression 1: %s\n", infix1);

    printf("Postfix: %s\n", postfix1);
    printf("Prefix : %s\n\n", prefix1);

    /* Expression 2 */
    infixToPostfix(infix2, postfix2);
    infixToPrefix(infix2, prefix2);

    printf("Expression 2: %s\n", infix2);

    printf("Postfix: %s\n", postfix2);
    printf("Prefix : %s\n", prefix2);

    return 0;
}