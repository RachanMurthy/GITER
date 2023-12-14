#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

int stack[SIZE];
int top = -1;

// Function to push an item to the stack
void push(int item) {
    if (top != SIZE - 1) {
        stack[++top] = item;
    } else {
        printf("Stack Overflow\n");
    }
}

// Function to pop an item from the stack
int pop() {
    if (top != -1) {
        return stack[top--];
    } else {
        printf("Stack Underflow\n");
        return -1; // Added return statement for stack underflow
    }
}

// Function to display the stack
void display() {
    if (top == -1) {
        printf("Stack EMPTY\n");
        return;
    }
    printf("The Stack status is \n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

// Function to check if a number is a palindrome
void palindrome() {
    int d;
    char s[10];
    printf("Enter number for palindrome check: ");
    scanf("%s", s);
    int n = 0;
    for (int i = 0; s[i]; i++) {
        d = s[i] - '0';
        n = n * 10 + d;
        push(d);
    }
    int r = 0;
    while (top != -1) {
        d = pop();
        r = r * 10 + d;
    }
    if (r == n)
        printf("Palindrome number\n");
    else
        printf("Not Palindrome number\n");
}

// Function to insert an item to the stack
void insert() {
    int item;
    printf("Enter item to be pushed: ");
    scanf("%d", &item);
    push(item);
}

// Function to delete an item from the stack
void delete() {
    int item = pop();
    if(item != -1) {
        printf("Popped element is %d\n", item);
    }
}

int main() {
    int choice;
    struct MENU {
        char *name;
        void (*func)();
    } menu[] = {
        {"Done", exit},
        {"Push", insert},
        {"Pop", delete},
        {"Display", display},
        {"Palindrome", palindrome}
    };

    int size = sizeof(menu) / sizeof(menu[0]);
    for (;;) {
        printf("\n-------Stack Menu-------\n");
        for (int i = 1; i < size; i++) {
            printf("%d. %s\n", i, menu[i].name);
        }
        printf("---------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice >= 0 && choice < size) {
            menu[choice].func();
        } else {
            printf("Invalid choice\n");
        }
    }
    return 0;
}
