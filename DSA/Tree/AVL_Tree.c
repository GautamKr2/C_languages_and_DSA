#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct node {
    int val;
    struct node* left;
    struct node* right;
    int height;
} Node;

int max(int x, int y) { // To find maximum of two numbers
    return (x>y) ? x : y; // Ternary operator
}

Node* createNode(int data) { // To create a new node
    Node* node = (Node*) malloc(sizeof(Node));
    node->val = data;
    node->left = node->right = NULL;
    node->height = 0;
    return node;
}

int getHeight(Node* n) { // To find height of the node
    if(n==NULL)
        return -1;
    return n->height;
}

int getBalanceFactor(Node *n) { // To find balance factor
    if(n==NULL)
        return 0;
    return (getHeight(n->left) - getHeight(n->right));
}

void preOrder(Node *n) { // To traverse tree in prerder
    if(n != NULL) {
        printf("%d %d  ", n->val, n->height);
        preOrder(n->left);
        preOrder(n->right);
    }
}

Node* rightRotate(Node* B) { // Right rotation w.r.t. node
    Node* A = B->left;
    Node* T2 = A->right;

    A->right = B;
    B->left = T2;

    if(B->left==NULL && B->right==NULL) // For no any child
        B->height = 0;
    else // For child of node
        B->height = max(getHeight(B->left), getHeight(B->right)) + 1;
    A->height = max(getHeight(A->left), getHeight(A->right)) + 1;

    return A;
}

Node* leftRotate(Node* B) { // Left rotation w.r.t. node
    Node* C = B->right;
    Node* T3 = C->left;

    C->left = B;
    B->right = T3;

    if(B->left==NULL && B->right==NULL)
        B->height = 0;
    else
        B->height = max(getHeight(B->left), getHeight(B->right)) + 1;
    C->height = max(getHeight(C->left), getHeight(C->right)) + 1;

    return C;
}

Node* insertNode(Node* r, int data) { // To insert node in tree
    if(r==NULL) {
        return createNode(data);
    }
    else if(data < r->val) {
        r->left = insertNode(r->left, data);
    }
    else if(data > r->val) {
        r->right = insertNode(r->right, data);
    }
    else if(data == r->val) { // Duplicate data can not be inserted
        printf("You have inserted a duplicate data.");
    }

    r->height = max(getHeight(r->left), getHeight(r->right)) + 1;


    // To balance the tree after insertion of node
    int bf = getBalanceFactor(r);

    if(bf>1) { // Left tree have more node
        if(data < r->left->val) {
            r = rightRotate(r); // Left Left rotation(Right rotate)
        } else {
            r->left = leftRotate(r->left);// Left Right rotation
            r = rightRotate(r); // (Left rotate child then Right rotate parent)
        }
    }
    else if(bf<-1) { // Right tree have more node
        if(data > r->right->val) {
            r = leftRotate(r); // Right Right rotation (Left rotate)
        } else {
            r->right = rightRotate(r->right); // Right Left rotation
            r = leftRotate(r); // (Right rotate child then Left rotate parent)
        }
    }
    return r;
}

int main() {
    int n, x;
    printf("Enter no of elements you want to insert initialy: ");
    scanf("%d", &n);
    Node* root = NULL;
    printf("Enter elements of tree: ");
    for(int i=0; i<n; i++) {
        scanf("%d", &x);
        root = insertNode(root, x);
    }
    preOrder(root);
    printf("\n");

    int ch;
    while(1) { // Infinite loop
        printf("Enter 1 for insert, 2 for delete, 3 for traverse, 4 for exit: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: // For insertion of the node
                printf("Enter data: ");
                scanf("%d", &x);
                root = insertNode(root, x);
                break;
            // case 2: // To delete the node
                // root = deleteNode(root);
                // break;
            case 3: // To traverse the tree
                preOrder(root); 
                printf("\n");
                break;
            case 4: exit(0); // Exit from loop and also from program
            default: printf("Invalid choice ! Please choose again -\n");
        }
    }
    return 0;
}