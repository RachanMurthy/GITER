#include <stdio.h>
#include <stdlib.h>

typedef struct NODE Node;
struct NODE {
    char ssn[20];
    char name[20];
    char dept[20];
    char desig[20];
    char salary[10];
    char phone[12];
    Node *next;
    Node *prev;
};

void get(char *prompt, char *s) {
    printf("Enter %s: ", prompt);
    scanf("%s", s);
}

Node *start = NULL;

Node *info() {
    Node *s = malloc(sizeof(Node));
    printf("Enter employee's info:\n");
    get("SSN", s->ssn);
    get("Name", s->name);
    get("Dept", s->dept);
    get("Designation", s->desig);
    get("Salary", s->salary);
    get("Phone", s->phone);
    s->next = NULL;
    s->prev = NULL;
    return s;
}

void insert_front() {
    Node *student = info();
    if (start == NULL) {
        start = student;
    } else {
        student->next = start;
        start->prev = student;
        start = student;
    }
}

void insert_end() {
    Node *student = info();
    if (start == NULL) {
        start = student;
    } else {
        Node *p = start;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = student;
        student->prev = p;
    }
}

void delete_front() {
    if (start == NULL) {
        printf("The DLL list is empty.\n");
        return;
    }
    Node *p = start;
    if (start->next == NULL) {
        start = NULL;
    } else {
        start = start->next;
        start->prev = NULL;
    }
    printf("Deleted Employee SSN is %s\n\n", p->ssn);
    free(p);
}

void delete_end() {
    if (start == NULL) {
        printf("The DLL list is empty.\n");
        return;
    }
    Node *p = start;
    if (start->next == NULL) {
        start = NULL;
    } else {
        while (p->next != NULL) {
            p = p->next;
        }
        if (p->prev != NULL) {
            p->prev->next = NULL;
        }
    }
    printf("Deleted Employee SSN is %s\n\n", p->ssn);
    free(p);
}

void display() {
    if (start == NULL) {
        printf("The list is empty.\n");
        return;
    }
    int n = 0;
    Node *p = start;
    while (p != NULL) {
        n++;
        printf("%d. %s %s %s %s %s %s\n", n, p->ssn, p->name, p->dept, p->desig, p->salary, p->phone);
        p = p->next;
    }
}

void create() {
    int n;
    printf("Enter number of Employees: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        printf("\nEmployee %d details:\n", i);
        insert_end();
    }
}

int main() {
    struct STRUCT {
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
        printf("\n-------DLL Menu-------\n");
        for (int i = 1; i < size; i++) {
            printf("%d. %s\n", i, menu[i].name);
        }
        printf("---------------------------------\n");
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice < 1 || choice >= size) {
            printf("Invalid choice. Please try again.\n");
            continue;
        }
        menu[choice].func();
    }
    return 0; // Added return statement for main
}
