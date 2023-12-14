#include <stdio.h>
#include <stdlib.h>

// Define the Node structure for the singly linked list
typedef struct NODE {
    char usn[20];
    char name[20];
    char branch[20];
    char sem[20];
    char phone[20];
    struct NODE *next;
} Node;

Node *start = NULL; // Head of the list
int flag = 0;       // Flag to check if list is created

// Function to get input from the user
void get(char *prompt, char *s) {
    printf("Enter %s: ", prompt);
    scanf("%s", s);
}

// Function to create a new node with user input
Node* info() {
    Node *s = malloc(sizeof(Node));
    get("USN", s->usn);
    get("Name", s->name);
    get("Branch", s->branch);
    get("Semester", s->sem);
    get("Phone", s->phone);
    s->next = NULL;
    return s;
}

// Function to insert a node at the front of the list
void insert_front() {
    Node *student = info();
    if (start == NULL) {
        start = student;
        return;
    }
    student->next = start;
    start = student;
}

// Function to insert a node at the end of the list
void insert_end() {
    Node *p, *student = info();
    if (start == NULL) {
        start = student;
        return;
    }
    p = start;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = student;
}

// Function to delete a node from the front of the list
void delete_front() {
    if (start == NULL) {
        printf("The list is empty.\n");
        return;
    }
    Node *p = start;
    start = start->next;
    printf("Deleted Student USN is %s\n\n", p->usn);
    free(p);
}

// Function to delete a node from the end of the list
void delete_end() {
    if (start == NULL) {
        printf("The list is empty.\n");
        return;
    }
    if (start->next == NULL) {
        printf("Deleted Student USN is %s\n\n", start->usn);
        free(start);
        start = NULL;
        return;
    }
    Node *p = start, *q;
    while (p->next != NULL) {
        q = p;
        p = p->next;
    }
    q->next = NULL;
    printf("Deleted Student USN is %s\n\n", p->usn);
    free(p);
}

// Function to display all nodes in the list
void display() {
    Node *p = start;
    int n = 1;
    while (p != NULL) {
        printf("%d. %s %s %s %s %s\n", n, p->usn, p->name, p->branch, p->sem, p->phone);
        p = p->next;
        n++;
    }
}

// Function to create the list with a given number of students
void create() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        printf("\nStudent %d details\n", i);
        insert_front();
    }
}

// Main function with menu for operations
int main() {
    int choice;
    struct MENU {
        char *name;
        void (*func)();
    } menu[] = {
        {"Done", exit},
        {"Create", create},
        {"Insert front", insert_front},
        {"Insert end", insert_end},
        {"Delete front", delete_front},
        {"Delete end", delete_end},
        {"Display", display}
    };

    int size = sizeof(menu) / sizeof(menu[0]);
    while (1) {
        printf("\n-------SLL Menu-------\n");
        for (int i = 1; i < size; i++) {
            printf("%d. %s\n", i, menu[i].name);
        }
        printf("---------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        menu[choice].func();
    }
}
