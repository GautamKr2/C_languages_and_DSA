#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct node {
    int val;
    struct node* left;
    struct node* right;
    int height;
} Node;

int max(int x, int y) {
    return (x>y) ? x : y;;
}

Node* createNode(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->val = data;
    node->left = node->right = NULL;
    node->height = 0;
    return node;
}

int getHeight(Node* n) {
    if(n==NULL)
        return 0;
    return n->height;
}

int getBalanceFactor(Node *n) {
    if(n==NULL)
        return 0;
    return (getHeight(n->left) - getHeight(n->right));
}

void preOrder(Node *n) {
    if(n != NULL) {
        printf("%d %d  ", n->val, n->height);
        preOrder(n->left);
        preOrder(n->right);
    }
}

Node* rightRotate(Node* B) {
    Node* A = B->left;
    Node* T2 = A->right;

    A->right = B;
    B->left = T2;

    if(B->left==NULL && B->right==NULL)
        B->height = 0;
    else
        B->height = max(getHeight(B->left), getHeight(B->right)) + 1;
    A->height = max(getHeight(A->left), getHeight(A->right)) + 1;

    return A;
}

Node* leftRotate(Node* B) {
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

Node* insertNode(Node* r, int data) {
    if(r==NULL) {
        return createNode(data);
    }
    else if(data < r->val) {
        r->left = insertNode(r->left, data);
    }
    else if(data > r->val) {
        r->right = insertNode(r->right, data);
    }
    else if(data == r->val) {
        printf("You have inserted a duplicate data.");
    }

    r->height = max(getHeight(r->left), getHeight(r->right)) + 1;


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

    root = leftRotate(root);
    printf("\n");
    preOrder(root);
    return 0;
}