#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *left, *right, *parent;
} Node;

void preOrder(Node *r) {
    if(r != NULL) {
        printf("%d ", r->val);
        preOrder(r->left);
        preOrder(r->right);
    }
}

Node* createNode(int x) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->val = x;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void leftRotate(Node **root, Node *x) {
    Node *y = x->right;
    // Set right child of y
    x->right = y->left;
    if(y->left != NULL)
        y->left->parent = x;
    // Set y, now head node
    y->parent = x->parent;
    if(x == *root)
        *root = y;
    else if(x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    // Set x
    y->left = x;
    x->parent = y;
}

void rightRotate(Node **root, Node *x) {
    Node *y = x->left;
    // Set right child of y
    x->left = y->right;
    if(y->right != NULL)
        y->right->parent = x;
    // Set y, now head node
    y->parent = x->parent;
    if(x == *root)
        *root = y;
    else if(x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    // Set x
    y->right = x;
    x->parent = y;
}

void Splay(Node **root, Node *x) {
    while(x != *root) {
        Node *p = x->parent;
        Node *g = p->parent;
        if(g == NULL) {
            if(x == p->left)
                rightRotate(root, p);
            else
                leftRotate(root, p);
        }
        else {
            if(x==p->left && p==g->left) {
                rightRotate(root, g);
                rightRotate(root, p);
            }
            else if(x==p->right && p==g->right) {
                leftRotate(root, g);
                leftRotate(root, p);
            }
            else if(x==p->left && p==g->right) {
                rightRotate(root, p);
                leftRotate(root, g);
            }
            else {
                leftRotate(root, p);
                rightRotate(root, g);
            }
        }
    }
}

void searchNode(Node **root, int data) {
    Node *temp = *root;
    while(temp != NULL) {
        if(data == temp->val) {
            Splay(root, temp);
            printf("%d is present in the tree.\n", data);
            return;
        }
        else if(data < temp->val)
            temp = temp->left;
        else
            temp = temp->right;
    }
    if(temp == NULL) {
        printf("%d is not present in the tree.\n", data);
    }
}

void insertNode(Node **root, int data) {
    Node *newNode = createNode(data);
    Node *temp = *root;
    Node *p = NULL;
    while(temp != NULL) {
        p = temp;
        if(data < temp->val)
            temp = temp->left;
        else if(data > temp->val)
            temp = temp->right;
        else {
            printf("You have entered a duplicate node.\n");
            return;
        }
    }

    newNode->parent = p;

    if(p == NULL)
        *root = newNode;
    else if(data < p->val)
        p->left = newNode;
    else
        p->right = newNode;

    Splay(root, newNode);
}

void deleteNode_Bottom_Up(Node **root, int x) {
    Node *temp = *root, *p;
    while(temp != NULL) {
        if(temp->val == x) {
            p = temp->parent;
            break;
        }
        else if(x < temp->val)
            temp = temp->left;
        else
            temp = temp->right;
    }
    if(temp == NULL) {
        printf("%d is not present in the tree.\n", x);
        return;
    }
    while(temp->left!=NULL || temp->right!=NULL) {
        if(temp->left == NULL) {
            temp->val = temp->right->val;
            temp = temp->right;
        }
        else if(temp->right == NULL) {
            temp->val = temp->left->val;
            temp = temp->left;
        }
        else {
            Node *t = temp->right;
            while(t->left != NULL) {
                t = t->left;
            }
            temp->val = t->val;
            temp = t;
        }
    }
    if(temp == temp->parent->left) {
        temp->parent->left = NULL;
    }
    else {
        temp->parent->right = NULL;
    }
    free(temp);
    Splay(root, p);
}

void deleteNode_Top_Down(Node **root, int x) {
    Node temp = *root;
    while(temp->val != x) {
        if(x < temp->val)
            temp = temp->left;
        else if(x > temp->val)
            temp = temp->right;
    }
    if(temp == NULL) {
        printf("%d is not in the tree.", x);
        return;
    }
    Splay(root, temp);
    if(temp != *root) {
        if(*root->left==NULL && *root->right==NULL);
        else if(*root->left==NULL)
            *root->right->parent = NULL;
        else if(*root->right==NULL)
            *root->left->parent = NULL;
        else {
            *root->left->parent = NULL;
            *root->right->parent = NULL;
        }
    }
    Node *leftSubTree = *root->left;
    Node *rightSubTree = *root->right;
    free(*root);
}

void deleteNode(Node **root, int x) {
    int ch;
    printf("Enter 1 for bottom-up approach, 2 for top-down approach, 0 for exit: ");
    scanf("%d", &ch);
    if(ch == 1)
        deleteNode_Bottom_Up(root, x);
    else if(ch == 2);
        // deleteNode_Top_Down(root, x);
    else if(ch == 0) exit(0);
    else
        printf("Invalid input! Please enter a valid input: ");
}

int main() {
    int n, x;
    printf("Enter no of nodes initially want to insert: ");
    scanf("%d", &n);

    Node *root = NULL;
    printf("Enter elements: ");
    for(int i=0; i<n; i++) {
        scanf("%d", &x);
        insertNode(&root, x);
    }
    printf("Inserted node - ");
    preOrder(root);
    printf("\n");

    int ch;
    while(1) {
        printf("Enter 1 for inserting, 2 for deleting, 3 for displaying, 4 for searching, 5 for exit: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &x);
                insertNode(&root, x);
                break;
            
            case 2:
                if(root == NULL) {
                    printf("Tree have no any node.\n");
                    break;
                }
                printf("Which node you want to delete: ");
                scanf("%d", &x);
                deleteNode(&root, x);
                break;

            case 3:
                if(root == NULL) {
                    printf("Tree have no any node.\n");
                    break;
                }
                preOrder(root);
                printf("\n");
                break;

            case 4:
                if(root == NULL) {
                    printf("Tree have no any node.\n");
                    break;
                }
                printf("Which node you want to search: ");
                scanf("%d", &x);
                searchNode(&root, x);
                break;

            case 5: exit(0);

            default: printf("Invalid input!");
        }
    }
    return 0;
}