// #include <stdio.h>
// #include <math.h>
// #include <stdlib.h>
// #define MAX 5
// int a[MAX], pos, elem;
// int n=0;
// void create();
// void display();
// void insert();
// void delete();
// int main(){

//     int choice;
//     while(1){
//         printf("\n----MENU----");
//         printf("\n=>1. CREATE AN ARRAY OF N VALUES");
//         printf("\n=>2. DISPLAY THE ARRAY");
//         printf("\n=>3. INSERT ELEM AT POSITION \'POS\'");
//         printf("\n=>4. DELETE AN ARRAY ELEMENT AT POSITION \'POS\'");
//         printf("\n=>5. EXIT");
//         printf("\n\n ENTER YOUR CHOICE: ");
//         scanf("%d", &choice);
//         switch(choice){
//             case 1 : create();
//                      break;
//             case 2 : display();
//                      break;
//             case 3 : insert();
//                      break;
//             case 4 : delete();
//                      break;
//             case 5 : ;
//             default : exit(1);
            


//         }
//     }

//     return 0;
// }

// void create(){
//     int i;
//     printf("\n enter no of elements");
//     scanf("%d", &n);
//     for(i = 0; i<n; i++){
//         printf("\n--ARRAY ELEMENT--  %d: ", i);
//         scanf("%d", &a[i]);
//     }
// }

// void display(){
//     int i;
//     for(i=0; i<n; i++){
//         printf("\n--ARRAY ELEMENT--  %d : %d", i, a[i]);
//     }
    
// }

// void insert(){
//     int i;
//     do {
//         printf("\n ENTER A POSITION TO INSERT");
//         scanf("%d", &pos);
//     }while(pos>n);
//     printf("\n ENTER THE VALUE TO INSERT");
//     scanf("%d", &elem);
//     for(i=n;i>=pos;i--){
//         a[i+1] = a[i];
//     }
//     a[pos]=elem;
//     n=n+1;
//     display();   
// }

// void delete(){
//     int i;
//     do {
//         printf("\n ENTER A POSITION TO INSERT");
//         scanf("%d", &pos);
//     }while(pos>n);
//     elem = a[pos];
//     printf("\nDeleted element is: %d\n", elem);
//     for(i=pos;i<n-1;i++){
//         a[i]=a[i+1];
//     }
//     n = n-1;
//     display();
// }

// #include <stdio.h>
// #include <string.h>

// void pattern(char str[], const char pat[], const char rep[]);

// int main() {
//     char str[100], pat[100], rep[100];
    
//     printf("Enter the main string: ");
//     gets(str);

//     printf("Enter the pattern string: ");
//     gets(pat);

//     printf("Enter the replacement string: ");
//     gets(rep);

    
//     pattern(str, pat, rep);
    
//     printf("\nModified string: %s\n", str);

//     return 0;
// }

// void pattern(char str[], const char pat[], const char rep[]) {
//     int m = strlen(str);
//     int p = strlen(pat);
//     int r = strlen(rep);
    
//     char result[1000];
//     int i, j, k;
    
//     for (i = 0, j = 0; i < m;) {
//         if (strncmp(&str[i], pat, p) == 0) {
//             for (k = 0; k < r; k++) {
//                 result[j++] = rep[k];
//             }
//             i += p;
//         } else {
//             result[j++] = str[i++];
//         }
//     }
//     result[j] = '\0';
    
//     if (strcmp(str, result) == 0) {
//         printf("Pattern not found in the main string.\n");
//     } else {
//         strcpy(str, result);
//         printf("Pattern replaced successfully.\n");
//     }
// }

// #include <stdio.h>


// int main(){
//     struct EMPLOYEE{
//         int age;
//         int id;
//         char name[20];
//         struct DOB{
//             int day;
//             int month;
//             int year;
//         }d1;
//     }e1,e2;

//     scanf("%d %d %d %d %d", &e1.age,&e1.id,&e1.d1.day,&e1.d1.month, &e1.d1.year);
//     getchar();
//     gets(e1.name);

//     printf("%d %d %s %d %d %d", e1.age, e1.id, e1.name, e1.d1.day, e1.d1.month, e1.d1.year);

//     return 0;
    
// }



// #include <stdio.h>
// #include <stdlib.h>
// #define MAX 100 
// int stack[MAX]; 
// int top = -1;

// void push(int element){
//     if (top == MAX - 1){
//         printf("Stack Overflow\n");
//         return; 
//     }
//     stack[++top] = element; 
// }

// int pop() {
//     if (top == -1){
//         printf("Stack Underflow\n");
//         return -1; 
//     }

//     int element = stack[top--];
//     printf("Element %d popped from the stack\n", element);
//     return element;
// }



// void display() {
//     if (top == -1) {
//         printf("Stack is empty\n");
//         return; 
//     }

//     printf("Elements in the stack: "); 
//     for (int i = top; i >= 0; i--){
//         printf("%d \n ", stack[i]); 
//     }
// }

// int isPalindrome(){ 
//     int i = 0, j = top;
//     while (i < j) {
//         if (stack[i] != stack[j]){
//             return 0; 
//         }
//         i++;
//         j--; 
//     }

//     return 1; 
// }

// // saippuakivikauppias 
// void checkPalindrome(){ 
//     char str[MAX];
//     printf("Enter a string: "); scanf("%s", str);

//     for (int i = 0; str[i] != '\0'; i++){
//         push(str[i]); 
//     }

//     if (isPalindrome()){
//         printf("The string is a palindrome\n");
//     } 

//     else{
//     printf("The string is not a palindrome\n");
//     }

// }

// int main() {
//     int choice, element; 
//     while (1) {
//         printf("\n----- Stack Operations -----\n"); printf("1. Push\n");
//         printf("2. Pop\n");
//         printf("3. Check Palindrome\n"); printf("4. Display\n");
//         printf("5. Exit\n"); printf("Enter your choice: "); 
//         scanf("%d", &choice); 
//         switch (choice) {

//             case 1:
//                 printf("Enter the element to push: "); scanf("%d", &element); push(element);
//                 break;

//             case 2: 
//                 pop();
//                 break; 

//             case 3:
//                 checkPalindrome();
//                 break; 
                
//             case 4:
//                 display();
//                 break; 

//             case 5:
//                 exit(0); 

//             default:
//                 printf("Invalid choice\n"); 
//         }
//     }
//     return 0; 
// }

// #include <string.h>
// #include <stdio.h>
// #define SIZE 50

// char s[SIZE]; /* Create stack of characters and Implement push() and pop() */
// int top= -1;

// void push(char elem){
//     s[++top]=elem;
// } 


// char pop(){
//     return(s[top--]);
// }


// void display(int k, char p[]){
//     for (int i=0; i <= top; i++) printf("%c", s[i]); printf("\n");
//     for (int i=0; i < k; i++) printf("%c", p[i]);
// }


// int precedence(char elem){ 
//     switch(elem){
//         case '(': return 1; case '+':
//         case '-': return 2; case '*':
//         case '/':
//         case '%': return 3; case '^': return 4; default: return 0;
//     }
// }


// void convert(char infix[], char postfix[]){
//     char ch;
//     int k=0;
//     push('\0');
//     for(int i=0;infix[i];i++){
//         ch=infix[i];
//         switch(ch){
//             case '(':
//                 push(ch);
//                 break;
//             case ')':
//                 while((ch = pop()) != '('){
//                     postfix[k++] = ch; 
//                 }
//                 break;
//             case '+':
//             case '-':
//             case '/':
//             case '*':                case '%':
//             case '^':
//                 while(precedence(ch) <= precedence(s[top])){
//                     postfix[k++]=pop();
//                 } 
//                 push(ch);
//                 break; 
//             default:
//                 postfix[k++]=ch;
//         }
//     }
// }

// int main(){
//     char infix[100];
//     char postfix[100];
//     printf("Enter the infix Expression: ");
//     gets(infix);
//     convert(infix, postfix);
//     printf("Postfix Expn: %s\n", postfix);

// }

// #include <string.h>
// #include <stdio.h>
// #define SIZE 50

// char s[SIZE]; 
// int top = -1;

// void push(char elem) {
//     s[++top] = elem;
// }

// char pop() {
//     return (s[top--]);
// }

// int precedence(char elem) {
//     switch (elem) {
//         case '(': return 0; 
//         case '+':
//         case '-': return 1;
//         case '*':
//         case '/':
//         case '%': return 2;
//         case '^': return 3;
//         default: return -1;
//     }
// }

// void convert(char infix[], char postfix[]) {
//     char ch;
//     int k = 0;
//     push('\0');

//     for (int i = 0; infix[i]; i++) {
//         ch = infix[i];
//         switch (ch) {
//             case '(':
//                 push(ch);
//                 break;
//             case ')':
//                 while ((ch = pop()) != '(') {
//                     postfix[k++] = ch;
//                 }
//                 break;
//             case '+':
//             case '-':
//             case '*':
//             case '/':
//             case '%':
//             case '^':
//                 while (precedence(ch) <= precedence(s[top])) {
//                     postfix[k++] = pop();
//                 }
//                 push(ch);
//                 break;
//             default:
//                 postfix[k++] = ch;
//         }
//     }

 
//     while (s[top] != '\0') {
//         postfix[k++] = pop();
//     }
//     postfix[k] = '\0'; 
// }

// int main() {
//     char infix[100];
//     char postfix[100] = {0}; 

//     printf("Enter the infix Expression: ");
//     fgets(infix, sizeof(infix), stdin);

//     size_t len = strlen(infix);
//     if (len > 0 && infix[len - 1] == '\n') {
//         infix[len - 1] = '\0';
//     }

//     convert(infix, postfix);
//     printf("Postfix Expn: %s\n", postfix);

//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <ctype.h>
// #include <math.h>
// #include <string.h>

// #define SIZE 50 // Size of Stack

// typedef struct {
//     int items[SIZE];
//     int top;
// } Stack;

// void push(Stack *s, int elem) {
//     if (s->top < SIZE - 1) {
//         s->items[++s->top] = elem;
//     } else {
//         printf("Stack Overflow\n");
//     }
// }

// int pop(Stack *s) {
//     if (s->top >= 0) {
//         return s->items[s->top--];
//     } else {
//         printf("Stack Underflow\n");
//         return -1; // or some error code
//     }
// }

// void suffix() {
//     Stack s = { .top = -1 };
//     char exp[50];
//     int num1, num2;

//     printf("Enter suffix expression: ");
//     scanf("%s", exp);

//     for (int i = 0; exp[i]; i++) {
//         if (isdigit(exp[i])) {
//             push(&s, exp[i] - '0');
//         } else {
//             num2 = pop(&s);
//             num1 = pop(&s);
//             switch (exp[i]) {
//                 case '+': push(&s, num1 + num2); break;
//                 case '-': push(&s, num1 - num2); break;
//                 case '*': push(&s, num1 * num2); break;
//                 case '/': push(&s, num1 / num2); break;
//                 case '%': push(&s, num1 % num2); break;
//                 case '^': push(&s, pow(num1, num2)); break;
//             }
//         }
//     }
//     printf("Result: %d\n", pop(&s));
// }

// void toh(int n, char beg, char aux, char end) {
//     if (n == 1) {
//         printf("%c --> %c\n", beg, end);
//         return;
//     }
//     toh(n - 1, beg, end, aux); // Move n-1 disks from beg to aux
//     printf("%c --> %c\n", beg, end); // Move remaining disk from beg to end
//     toh(n - 1, aux, beg, end); // Move n-1 disks from aux to end
// }

// void tower() {
//     int n;
//     printf("Enter number of disks: ");
//     scanf("%d", &n);
//     toh(n, 'b', 'a', 'e');
// }

// int main() {
//     int choice;
//     struct MENU {
//         char *name;
//         void (*func)();
//     } menu[] = {
//         {"Done", NULL},
//         {"Suffix", suffix},
//         {"Tower", tower}
//     };

//     int size = sizeof(menu) / sizeof(menu[0]);
//     while (1) {
//         printf("\n-------Array Menu-------\n");
//         for (int i = 1; i < size; i++) {
//             printf("%d. %s\n", i, menu[i].name);
//         }
//         printf("---------------------------------\n");
//         printf("Enter your choice: ");
//         scanf("%d", &choice);

//         if (choice <= 0 || choice >= size) {
//             printf("Invalid choice\n");
//             continue;
//         }

//         if (menu[choice].func == NULL) break;
//         menu[choice].func();
//     }
//     return 0;
// }


// #include <stdio.h>
// #include <stdlib.h>

// #define SIZE 50 /* Size of Queue */
// int queue[SIZE];
// int front = -1, rear = -1;


// int isFull() {
//     return ((front == 0 && rear == SIZE - 1) || front == rear + 1);
// }


// int isEmpty() {
//     return (front == -1);
// }


// void enqueue(int elem) {
//     if (isFull()) {
//         printf("\nQueue is full\n");
//     } else {
//         if (front == -1) front = 0;
//         rear = (rear + 1) % SIZE;
//         queue[rear] = elem;
//         printf("\nInserted -> %d\n", elem);
//     }
// }


// int dequeue() {
//     int elem;
//     if (isEmpty()) {
//         printf("\nQueue is empty\n");
//         return (-1);
//     } else {
//         elem = queue[front];
//         if (front == rear) {
//             front = -1;
//             rear = -1;
//         } else {
//             front = (front + 1) % SIZE;
//         }
//         printf("\nDeleted element -> %d\n", elem);
//         return (elem);
//     }
// }


// void display() {
//     int i;
//     if (isEmpty()) {
//         printf("\nEmpty Queue\n");
//     } else {
//         printf("\nFront -> %d ", front);
//         printf("\nItems -> ");
//         for (i = front; i != rear; i = (i + 1) % SIZE)
//             printf("%d ", queue[i]);
//         printf("%d ", queue[i]);
//         printf("\nRear -> %d\n", rear);
//     }
// }


// void handleQueue() {
//     int choice, value;
//     do {
//         printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
//         printf("Enter your choice: ");
//         scanf("%d", &choice);
//         switch (choice) {
//             case 1:
//                 printf("Input the value to be added in the queue: ");
//                 scanf("%d", &value);
//                 enqueue(value);
//                 break;
//             case 2:
//                 dequeue();
//                 break;
//             case 3:
//                 display();
//                 break;
//             case 4:
//                 return;
//             default:
//                 printf("\nInvalid choice\n");
//         }
//     } while (choice != 4);
// }


// int main() {
//     int choice;

//     while (1) {
//         printf("\nQueue Operations Menu\n");
//         printf("1. Perform Queue Operations\n");
//         printf("2. Exit\n");
//         printf("Enter your choice: ");
//         scanf("%d", &choice);

//         switch (choice) {
//             case 1:
//                 handleQueue(); // Call the function to handle queue operations
//                 break;
//             case 2:
//                 printf("Exiting program.\n");
//                 exit(0); // Exit the program
//             default:
//                 printf("Invalid choice. Please try again.\n");
//         }
//     }
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

typedef struct NODE Node;
struct NODE {
    char usn[20];
    char name[20];
    char branch[20];
    char sem[20];
    char phone[20];
    Node *next;
};

Node *start = NULL;
int flag = 0; /* is 1 when list is created */

void get(char *prompt, char *s) {
    printf("Enter %s: ", prompt);
    scanf("%19s", s); // Limiting input to avoid buffer overflow
}

Node *info() {
    Node *s;
    s = malloc(sizeof(Node));
    if (s == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }
    get("USN", s->usn);
    get("Name", s->name);
    get("Branch", s->branch);
    get("Semester", s->sem);
    get("Phone", s->phone);
    s->next = NULL;
    return s;
}

void insert_front() {
    Node *student = info();
    student->next = start;
    start = student;
    flag = 1;
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
    }
    flag = 1;
}

void delete_front() {
    if (start == NULL) {
        printf("The list is empty. \n");
        return;
    }
    Node *p = start;
    start = start->next;
    printf("Deleted Student USN is %s \n\n", p->usn);
    free(p);
}

void delete_end() {
    if (start == NULL) {
        printf("The list is empty. \n");
        return;
    }
    if (start->next == NULL) {
        printf("Deleted Student USN is %s \n\n", start->usn);
        free(start);
        start = NULL;
        return;
    }
    Node *p = start, *q = NULL;
    while (p->next != NULL) {
        q = p;
        p = p->next;
    }
    q->next = NULL;
    printf("Deleted Student USN is %s \n\n", p->usn);
    free(p);
}

void display() {
    if (start == NULL) {
        printf("The list is empty.\n");
        return;
    }
    Node *p = start;
    int n = 1;
    while (p != NULL) {
        printf("%d. %s %s %s %s %s\n", n, p->usn, p->name, p->branch, p->sem, p->phone);
        p = p->next;
        n++;
    }
}

void create() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        printf("\nStudent %d details\n", i);
        insert_front();
    }
}

void exit_program() {
    exit(0);
}

int main() {
    int choice;
    struct MENU {
        char *name;
        void (*func)();
    } menu[] = {
        {"Done", exit_program},
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
        if (choice < 1 || choice >= size) {
            printf("Invalid choice. Please try again.\n");
            continue;
        }
        menu[choice].func();
    }
    return 0;
}

