#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *left, *right;
    char color;
} Node;
int start = 1;

Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->val = data;
    newNode->left = newNode->right = NULL;
    if(start==1)
        newNode->color = 'B';
    else
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

Node* leftRotate(Node *B) {
    Node *C = B->right;
    Node *T3 = C->left;

    C->left = B;
    B->right = T3;

    return C;
}

Node* rightRotate(Node *B) {
    Node *A = B->left;
    Node *T2 = A->right;

    A->right = B;
    B->left = T2;

    return A;
}

Node* reColor(Node *r) {
    if(r==NULL)
        return r;
    r->color = (r->color=='R') ? 'B' : 'R';
    return r;
}

Node* insertNode(Node *r, int data) {
    if(r==NULL)
        return createNode(data);
    else if(data < r->val) {
        start++;
        r->left = insertNode(r->left, data);
    }
    else if(data > r->val) {
        start++;
        r->right = insertNode(r->right, data);
    }
    else {
        printf("Youn have entered a duplicate data!\n");
    }



    return r;
}

int main() {
    int n, x;
    printf("Enter nodes initially insert: ");
    scanf("%d", &n);

    Node *root = NULL;
    printf("Enter values of nodes: ");
    for(int i=0; i<n; i++) {
        scanf("%d", &x);
        start = 1;
        root = insertNode(root, x);
    }
    printf("Inserted value - ");
    preOrder(root);
    printf("\n");

    /*int ch;
    while(true) {
        printf("Enter 1 for insert, 2 for delete, 3 for traverse, 4 for exit: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &x);
                root = insertNode(root, x);
                break;
            case 2:
                printf("Which node you want to delete: ");
                scanf("%d", &x);
                root = deleteNode(x);
                break;
            case 3:
                preOrder(root);
                printf("\n");
                break;
            case 4: exit(0);
            default: printf("Invalid input! Please insert a valid input: ");
        }
    }*/
    return 0;
}