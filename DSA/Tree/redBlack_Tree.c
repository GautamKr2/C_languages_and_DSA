#include <stdio.h>
#include <stdlib.h>

typedef struct node { // Definition of node of red-black tree
    int val;
    struct node *left, *right;
    char color;
    struct node *parent;
} Node;

Node* createNode(int data) { // For create newNode
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->val = data;
    newNode->left = newNode->right = newNode->parent = NULL;
    newNode->color = 'R';
    return newNode;
}

void preOrder(Node *r) { // To traverse tree in inOrder
    if(r != NULL) {
        printf("%d %c  ", r->val, r->color);
        preOrder(r->left);
        preOrder(r->right);
    }
}

void leftRotate(Node **root, Node *x) { // To left rotate tree 
    Node *y = x->right; // create root(y) node of new sub tree

    x->right = y->left; // Store left subtree of right child of x
    if(y->left != NULL)
        y->left->parent = x; // Now x-right->parent = x also

    y->parent = x->parent; // Parent of y replaces with parent of x

    if (x->parent == NULL) // x = root node
        *root = y; // Now root become y
    else if (x == x->parent->left) // if x is left child of his parent
        x->parent->left = y;
    else // if x is right child of his parent
        x->parent->right = y;

    y->left = x; // Set link of y->left as x
    x->parent = y; // Now parent of x becomes y
}

void rightRotate(Node **root, Node*y) { // For right rotation of tree
    Node *x = y->left; // Create root(x) of new sub tree

    y->left = x->right; // Store right subtree of left child of y
    if (x->right != NULL)
        x->right->parent = y; // Now y->left->parent = y also

    x->parent = y->parent; // Parent of x replaces with parent of y

    if (y->parent == NULL) // y = root node itself
        *root = x; // Now root becomes x
    else if (y == y->parent->left) // if y is left child of its parent
        y->parent->left = x;
    else // if y is right child of its parent
        y->parent->right = x;

    x->right = y; // Set link of x->right as y
    y->parent = x; // Now parent of y becomes x
}

void fixInsert(Node **root, Node *x) { // To fix insertion(rotation or recoloring)

    while (x != *root && x->parent->color == 'R') { // To check red-red conflict

        Node *p = x->parent; // First find parent and grandparent
        Node *g = p->parent;

        // Parent is left child
        if (p == g->left) { // Inserted in left subtree of grandparent

            Node *u = g->right; // Now first find uncle

            // Case 1: u is RED (Recolor)
            if (u != NULL && u->color == 'R') { // Uncle is red, only recoloring required
                p->color = 'B'; // Recolor parent, uncle, and grandparent
                u->color = 'B';
                g->color = 'R';
                x = g; // Now x goes up(as grandparent); now treating that g is inserted
            }
            // Case 2: u is BLACK
            else { // Uncle is black or NULL
                // LR case
                if (x == p->right) { //         /
                    x = p;           /*          \          */
                    leftRotate(root, x);
                }
                else {               //       /
                    // LL case       //      /
                    p->color = 'B'; // First recolor parent, and grandparent
                    g->color = 'R';
                    rightRotate(root, g); // Then rightRotate
                }
            }
        }
        // Parent is right child (mirror case)
        else { // Inserted in right subtree of grandparent

            Node *u = g->left;// Now first find uncle

            if (u != NULL && u->color == 'R') { // Uncle is red, only recoloring required
                p->color = 'B'; // Recolor uncle, parent, and grandparent
                u->color = 'B';
                g->color = 'R';
                x = g; // x goes up(as grandparent) now treating that g is inserted
            }
            else { // Uncle is black or NULL
                // RL case
                if (x == p->left) { //          \ 
                    x = p;          //          /
                    rightRotate(root, x);
                }
                else {              //          \ 
                    // RR case      //           \ 
                    p->color = 'B'; // First recolor parent, and grandparent
                    g->color = 'R';
                    leftRotate(root, g); // Then left rotate
                }
            }
        }
    }

    (*root)->color = 'B';   // root must be black
}

void insertNode(Node **root, int data) { // For inserting of newNode
    Node *newNode = createNode(data); // First create new node

    Node *parent = NULL; // Set parent as null
    Node *current = *root; //Set current node as root

    // Normal BST insert
    while (current != NULL) { // To traverse where to insert
        parent = current;
        if (data < current->val) // in left side
            current = current->left;
        else // in right side
            current = current->right;
    }

    newNode->parent = parent; // Set parent of newNode

    if (parent == NULL) // No any node in the tree
        *root = newNode;
    else if (data < parent->val) // inserting left side of parent
        parent->left = newNode;
    else // inserting right side of parent
        parent->right = newNode;

    // Fix Red-Black properties
    fixInsert(root, newNode); // Now sent to fix after inserting
}

void fixDelete(Node **root, Node *x) {

}
void deleteNode(Node **root, int data) {

}

int main() {
    int n, x;
    printf("Enter nodes initially insert: ");
    scanf("%d", &n);

    Node *root = NULL; // Initially root node should be NULL
    printf("Enter values of nodes: ");
    for(int i=0; i<n; i++) {
        scanf("%d", &x); // One by one scan the value
        insertNode(&root, x); // Then insert
    }
    printf("Inserted value - ");
    preOrder(root); // Print inserted value in inOrder
    printf("\n");

    int ch;
    while(1) { // Always true because we may insert, delete, or traverse
        printf("Enter 1 for insert, 2 for delete, 3 for traverse, 4 for exit: ");
        scanf("%d", &ch); 
        switch(ch) { //Switch case statement
            case 1: // Inserting case
                printf("Enter data: ");
                scanf("%d", &x);
                insertNode(&root, x);
                break;
            /*case 2: // Deleting case
                printf("Which node you want to delete: ");
                scanf("%d", &x);
                root = deleteNode(x);
                break;*/
            case 3: // Traversing case
                preOrder(root);
                printf("\n");
                break;
            case 4: exit(0); // To exit from program
            default: printf("Invalid input! Please insert a valid input: ");
        }
    }
    return 0;
}