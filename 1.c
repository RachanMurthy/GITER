#include <stdio.h>
#include <stdlib.h>

int a[20];
int n = 0;

// Function to create an array
void create() {
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter the elements for the array:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
}

// Function to display array elements
void display() {
    printf("The array elements are:\n");
    for(int i = 0; i < n; i++) {
        printf("%d\n", a[i]);
    }
}

// Function to insert an element in the array
void insert() {
    int pos, value;

    printf("Enter the index position for the new element: ");
    scanf("%d", &pos);

    printf("Enter the element to be inserted: ");
    scanf("%d", &value);

    for(int i = n - 1; i >= pos; i--) {
        a[i + 1] = a[i];
    }

    a[pos] = value;
    n = n + 1;
}

// Function to delete an element from the array
void delete() {
    int pos, value;

    printf("Enter the index position of the element to be deleted: ");
    scanf("%d", &pos);

    value = a[pos];
    for(int i = pos + 1; i < n; i++) {
        a[i - 1] = a[i];
    }

    n = n - 1;
    printf("The deleted element is = %d", value);
}

// Main function implementing a menu
int main() {
    int choice;

    struct MENU {
        char *name;
        void (*func)();
    } menu[] = {
        {"Done", exit},
        {"Create", create},
        {"Insert", insert},
        {"Delete", delete},
        {"Display", display}
    };

    setvbuf(stdout, (char *) NULL, _IONBF, 0);
    for(;;) {
        printf("\n-------Array Menu-------\n");
        for(int i = 1; i < 5; i++) {
            printf("%d. %s\n", i, menu[i].name);
        }

        printf("---------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        menu[choice].func();
    }
}
