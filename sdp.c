#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char usn[20];
    char name[20];
    char branch[20];
    char sem[20];
    char phone[20];
    struct Node *next;
} Node;

Node *start = Null;
int flag = 0;

Node* info(){
    Node *s = malloc(sizeof(Node))
    get("USN", s->usn);
    get("Name", s->name);
    get("Branch", s->branch);
    get("Semester", s->sem);
    get("Phone", s->phone);
    s->next = NULL;
    return s;
}

void insert_end(){
    Node *student = info();
    Node *p;
    
    if(start == Null){
        start = student;
        return;
    }
    p = start

    while(p->next != Null){
        p = p->next;
    }
    p->next = student;
}

void insert_front(){
    Node *student = info();
    
    if(start == Null){
        start = student;
        return;
    }

    student->next = start;
    start = student;
}

void delete_end(){
    Node *student = info();
    Node *p = start;
    Node *q;


    if(start == Null){
        printf("The list is empty.\n");
        return;
    }
    if(p->next == Null){
        free(start)
        start = Null
        return;
    }

    while(p->next != Null){
        q=p;
        p = p->next;
    }
    q->next = Null
    free(p)
}

void delete_front(){
    Node *student = info();
    Node *hold;

    if(start == Null){
        printf("The list is empty.\n");
        return;
    }
    if(p->next == Null){
        free(start)
        start = Null
        return;
    }
    hold = start;
    start = start->next;
    free(hold)
    
}