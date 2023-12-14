#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define SIZE 50 // Size of Stack

typedef struct {
    int items[SIZE];
    int top;
} Stack;

void push(Stack *s, int elem) {
    if (s->top < SIZE - 1) {
        s->items[++s->top] = elem;
    } else {
        printf("Stack Overflow\n");
    }
}

int pop(Stack *s) {
    if (s->top >= 0) {
        return s->items[s->top--];
    } else {
        printf("Stack Underflow\n");
        return -1; // or some error code
    }
}

void suffix() {
    Stack s = { .top = -1 };
    char exp[50];
    int num1, num2;

    printf("Enter suffix expression: ");
    scanf("%s", exp);

    for (int i = 0; exp[i]; i++) {
        if (isdigit(exp[i])) {
            push(&s, exp[i] - '0');
        } else {
            num2 = pop(&s);
            num1 = pop(&s);
            switch (exp[i]) {
                case '+': push(&s, num1 + num2); break;
                case '-': push(&s, num1 - num2); break;
                case '*': push(&s, num1 * num2); break;
                case '/': push(&s, num1 / num2); break;
                case '%': push(&s, num1 % num2); break;
                case '^': push(&s, pow(num1, num2)); break;
            }
        }
    }
    printf("Result: %d\n", pop(&s));
}

void toh(int n, char beg, char aux, char end) {
    if (n == 1) {
        printf("%c --> %c\n", beg, end);
        return;
    }
    toh(n - 1, beg, end, aux); // Move n-1 disks from beg to aux
    printf("%c --> %c\n", beg, end); // Move remaining disk from beg to end
    toh(n - 1, aux, beg, end); // Move n-1 disks from aux to end
}

void tower() {
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);
    toh(n, 'b', 'a', 'e');
}

int main() {
    int choice;
    struct MENU {
        char *name;
        void (*func)();
    } menu[] = {
        {"Done", NULL},
        {"Suffix", suffix},
        {"Tower", tower}
    };

    int size = sizeof(menu) / sizeof(menu[0]);
    while (1) {
        printf("\n-------Array Menu-------\n");
        for (int i = 1; i < size; i++) {
            printf("%d. %s\n", i, menu[i].name);
        }
        printf("---------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice <= 0 || choice >= size) {
            printf("Invalid choice\n");
            continue;
        }

        if (menu[choice].func == NULL) break;
        menu[choice].func();
    }
    return 0;
}