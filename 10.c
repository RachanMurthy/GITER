#include <stdio.h>
#include <stdlib.h>

typedef struct NODE Node;
struct NODE {
    int value;
    Node *left;
    Node *right;
};

Node *root = NULL;

/* Insert Function */
Node *insert(Node *root, int value) {
    if (root == NULL) {
        Node *node = malloc(sizeof(Node));
        node->value = value;
        node->left = node->right = NULL;
        return node;
    }
    if (value == root->value) {
        printf(" Duplicate Element Not Allowed !!!");
    } else if (value < root->value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

/* Search Function */
Node *search(Node *root, int value) {
    if (root == NULL) {
        return NULL; // Element not found
    }
    if (value == root->value) {
        return root; // Element found
    } else if (value < root->value) {
        return search(root->left, value); // Search in left subtree
    } else {
        return search(root->right, value); // Search in right subtree
    }
}

/* Inorder Traversal */
void inorder(Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf(" %d ", root->value);
        inorder(root->right);
    }
}

/* Preorder Traversal */
void preorder(Node *root) {
    if (root != NULL) {
        printf(" %d ", root->value);
        preorder(root->left);
        preorder(root->right);
    }
}

/* Postorder Traversal */
void postorder(Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf(" %d ", root->value);
    }
}

/* Traverse and Print */
void traverse() {
    printf("Preorder: ");
    preorder(root);
    printf("\nInorder: ");
    inorder(root);
    printf("\nPostorder: ");
    postorder(root);
    printf("\n");
}

/* Find Value */
void find() {
    Node *node;
    int value;
    printf("Enter item: ");
    scanf("%d", &value);
    node = search(root, value);
    if (node == NULL) {
        printf("Not found.\n");
    } else {
        printf("Found %d.\n", node->value);
    }
}

/* Create BST */
void create() {
    int n, value;
    printf("BST for How Many Nodes? : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter the value of node %d: ", i + 1);
        scanf("%d", &value);
        root = insert(root, value);
    }
    printf("BST created!!\n");
}

/* Main Function */
int main() {
    int choice;
    struct STRUCT {
        char *name;
        void (*func)();
    } menu[] = {
        {"Exit", exit},
        {"Create", create},
        {"Traverse", traverse},
        {"Search", find}
    };
    int size = sizeof(menu) / sizeof(menu[0]);
    while (1) {
        printf("\n-------BST Menu-------\n");
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
}
