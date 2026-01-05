#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *left, *right;
    char color;
    struct node *parent;
} Node;

Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->val = data;
    newNode->left = newNode->right = newNode->parent = NULL;
    newNode->color = 'R';
    return newNode;
}

void preOrder(Node *r) {
    if(r != NULL) {
        printf("%d %c  ", r->val, r->color);
        preOrder(r->left);
        preOrder(r->right);
    }
}

void leftRotate(Node **root, Node *x) {
    Node *y = x->right;

    x->right = y->left;
    if(y->left != NULL)
        y->left->parent = x;

    y->parent = x->parent;

    if (x->parent == NULL)
        *root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->left = x;
    x->parent = y;
}

void rightRotate(Node **root, Node*y) {
    Node *x = y->left;

    y->left = x->right;
    if (x->right != NULL)
        x->right->parent = y;

    x->parent = y->parent;

    if (y->parent == NULL)
        *root = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;

    x->right = y;
    y->parent = x;
}

void fixInsert(Node **root, Node *x) {

    while (x != *root && x->parent->color == 'R') {

        Node *p = x->parent;
        Node *g = p->parent;

        // Parent is left child
        if (p == g->left) {

            Node *u = g->right;

            // Case 1: u is RED (Recolor)
            if (u != NULL && u->color == 'R') {
                p->color = 'B';
                u->color = 'B';
                g->color = 'R';
                x = g;
            }
            // Case 2: u is BLACK
            else {
                // LR case
                if (x == p->right) {
                    x = p;
                    leftRotate(root, x);
                }
                else {
                    // LL case
                    p->color = 'B';
                    g->color = 'R';
                    rightRotate(root, g);
                }
            }
        }
        // Parent is right child (mirror case)
        else {

            Node *u = g->left;

            if (u != NULL && u->color == 'R') {
                p->color = 'B';
                u->color = 'B';
                g->color = 'R';
                x = g;
            }
            else {
                // RL case
                if (x == p->left) {
                    x = p;
                    rightRotate(root, x);
                }
                else {
                    // RR case
                    p->color = 'B';
                    g->color = 'R';
                    leftRotate(root, g);
                }
            }
        }
    }

    (*root)->color = 'B';   // root must be black
}

void insertNode(Node **root, int data) {
    Node *newNode = createNode(data);

    Node *parent = NULL;
    Node *current = *root;

    // Normal BST insert
    while (current != NULL) {
        parent = current;
        if (data < current->val)
            current = current->left;
        else
            current = current->right;
    }

    newNode->parent = parent;

    if (parent == NULL)
        *root = newNode;
    else if (data < parent->val)
        parent->left = newNode;
    else
        parent->right = newNode;

    // Fix Red-Black properties
    fixInsert(root, newNode);
}

int main() {
    int n, x;
    printf("Enter nodes initially insert: ");
    scanf("%d", &n);

    Node *root = NULL;
    printf("Enter values of nodes: ");
    for(int i=0; i<n; i++) {
        scanf("%d", &x);
        insertNode(&root, x);
    }
    printf("Inserted value - ");
    preOrder(root);
    printf("\n");

    int ch;
    while(1) {
        printf("Enter 1 for insert, 2 for delete, 3 for traverse, 4 for exit: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &x);
                insertNode(&root, x);
                break;
            /*case 2:
                printf("Which node you want to delete: ");
                scanf("%d", &x);
                root = deleteNode(x);
                break;*/
            case 3:
                preOrder(root);
                printf("\n");
                break;
            case 4: exit(0);
            default: printf("Invalid input! Please insert a valid input: ");
        }
    }
    return 0;
}