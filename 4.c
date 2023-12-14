#include <stdio.h>
#define SIZE 50

// Stack of characters
char s[SIZE];
int top = -1;

// Function to push an element onto the stack
void push(char elem) {
    s[++top] = elem;
}

// Function to pop an element from the stack
char pop() {
    return s[top--];
}

// Display the stack and part of the postfix expression
void display(int k, char p[]) {
    for (int i = 0; i <= top; i++) {
        printf("%c", s[i]);
    }
    printf("\n");
    for (int i = 0; i < k; i++) {
        printf("%c", p[i]);
    }
}

// Determine the precedence of operators
int precedence(char elem) {
    switch (elem) {
        case '(': return 1;
        case '+':
        case '-': return 2;
        case '*':
        case '/':
        case '%': return 3;
        case '^': return 4;
        default: return 0;
    }
}

// Convert infix expression to postfix expression
void convert(char infix[], char postfix[]) {
    char ch;
    int k = 0;
    push('\0'); // null marker

    for (int i = 0; infix[i]; i++) {
        ch = infix[i];
        switch (ch) {
            case '(':
                push(ch);
                break;
            case ')':
                while ((ch = pop()) != '(') {
                    postfix[k++] = ch;
                }
                break;
            case '+':
            case '-':
            case '/':
            case '*':
            case '%':
            case '^':
                while (precedence(ch) <= precedence(s[top])) {
                    postfix[k++] = pop();
                }
                push(ch);
                break;
            default:
                postfix[k++] = ch;
        }
        // display(k, postfix); // Uncomment to display intermediate steps
    }

    // Empty stack into postfix, checking for '\0' marker
    while ((postfix[k++] = pop()) != '\0');
}

// Main function to read infix and convert to postfix
int main() {
    char infix[100], postfix[100];

    printf("Enter the Infix Expression: ");
    gets(infix); // Note: 'gets' is unsafe, consider using 'fgets'
    convert(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);

    return 0;
}
