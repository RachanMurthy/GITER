#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int count = 0;

struct node {
    char ssn[20], name[20], dept[20], desig[20], sal[20], phno[20];
    struct node *llink, *rlink;
};

struct node *first = NULL;

struct node *read() {
    struct node *newnode;
    char ssn[20], name[20], dept[20], desig[20], sal[20], phno[20];
    printf("Enter ssn, name, dept, desig, sal, phno\n");
    scanf("%s %s %s %s %s %s", ssn, name, dept, desig, sal, phno);
    newnode = (struct node *)malloc(sizeof(struct node));
    strcpy(newnode->ssn, ssn);
    strcpy(newnode->name, name);
    strcpy(newnode->dept, dept);
    strcpy(newnode->desig, desig);
    strcpy(newnode->sal, sal);
    strcpy(newnode->phno, phno);
    newnode->llink = NULL;
    newnode->rlink = NULL;
    return newnode;
}

void insertfront() {
    struct node *newnode = read();
    if (first != NULL) {
        first->llink = newnode;
    }
    newnode->rlink = first;
    first = newnode;
    count++;
}

void insertrear() {
    struct node *newnode = read();
    if (first == NULL) {
        first = newnode;
    } else {
        struct node *cur = first;
        while (cur->rlink != NULL) {
            cur = cur->rlink;
        }
        cur->rlink = newnode;
        newnode->llink = cur;
    }
    count++;
}

void deletefront() {
    if (first == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node *temp = first;
    first = first->rlink;
    if (first != NULL) {
        first->llink = NULL;
    }
    printf("Deleted item: %s %s %s %s %s %s\n", temp->ssn, temp->name, temp->dept, temp->desig, temp->sal, temp->phno);
    free(temp);
    count--;
}

void deleterear() {
    if (first == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node *temp = first;
    if (temp->rlink == NULL) {
        first = NULL;
    } else {
        while (temp->rlink != NULL) {
            temp = temp->rlink;
        }
        temp->llink->rlink = NULL;
    }
    printf("Deleted item: %s %s %s %s %s %s\n", temp->ssn, temp->name, temp->dept, temp->desig, temp->sal, temp->phno);
    free(temp);
    count--;
}

void display() {
    if (first == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node *temp = first;
    while (temp != NULL) {
        printf("%s %s %s %s %s %s\n", temp->ssn, temp->name, temp->dept, temp->desig, temp->sal, temp->phno);
        temp = temp->rlink;
    }
}

int main() {
    int ch;
    while (1) {
        printf("\n1.Create (Insert_Rear)\n2.INSERT_FRONT\n3.INSERT_REAR\n4.DELETE_FRONT\n");
        printf("5.DELETE_REAR\n6.DISPLAY\n7.EXIT\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
            case 3: insertrear(); break;
            case 2: insertfront(); break;
            case 4: deletefront(); break;
            case 5: deleterear(); break;
            case 6: 
                printf("Number of students: %d\n", count);
                printf("Contents of the list:\n");
                display();
                break;
            case 7: 
                exit(0);
            default: 
                printf("Invalid choice.\n");
        }
    }
    return 0;
}

