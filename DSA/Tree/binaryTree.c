#include <stdio.h>
#include <stdlib.h>
typedef struct n{
    int data;
    struct n *left, *right;
}Tree;
Tree* create();
void display(Tree* temp);
void main() {
    Tree* root = NULL;
    root = create();
    display(root);
}
Tree* create() {
    int x;
    Tree* newNode;
    newNode = (Tree*)malloc(sizeof(Tree));
    printf("Enter data(-1 for no data): ");
    scanf("%d", &x);
    if(x == -1) return NULL;
    newNode -> data = x;
    printf("\nEnter left child of %d.\n", x);
    newNode -> left = create();
    printf("\nEnter right chile of %d.\n", x);
    newNode -> right = create();
    return newNode;
}
void display(Tree* root) {
    Tree* temp = root;
    if(root != NULL) {
        display(temp -> left);
        printf("%d\t", temp -> data);
        display(temp -> right);
    }
}