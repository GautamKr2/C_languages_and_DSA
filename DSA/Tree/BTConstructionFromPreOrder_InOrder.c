#include <stdio.h>
#include <stdlib.h>
#define max 100

struct node {
    int data;
    struct node *left, *right;
};
struct node* createNode(int currVal) {
    struct node* newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    
    newNode -> data = currVal;
    newNode -> left = newNode -> right = NULL;
    return newNode;
}

int findIndex(char inOrder[], int start, int end, int currVal) {
    for(int i=start; i<=end; i++)
        if(inOrder[i]==currVal)
            return i;
    return -1;
}

struct node* createFullTree(char preOrder[], char inOrder[], int start, int end, int* index) {
    if(start > end) return NULL;
    int currVal = preOrder[*index];
    (*index)++;
    // struct node* root = createNode(currVal);
    struct node *root = (struct node*)malloc(sizeof(struct node));
    root -> data = currVal;
    root -> left = root -> right = NULL;

    if(start==end) return root;

    // int valIdx = findIndex(inOrder, start, end, currVal);
    int valIdx;
    for(int i=start; i<=end; i++)
        if(inOrder[i]==currVal) {
            valIdx = i;
            break;
        }

    root -> left = createFullTree(preOrder, inOrder, start, valIdx-1, index);
    root -> right = createFullTree(preOrder, inOrder, valIdx+1, end, index);
    return root;
}

struct node* createTree(char preOrder[], char inOrder[], int n) {
    int index = 0;
    return createFullTree(preOrder, inOrder, 0, n-1, &index);
}

void inOrderTraversal(struct node *root) {
    if(root != NULL) {
        inOrderTraversal(root -> left);
        printf("%d ", root -> data);
        inOrderTraversal(root -> right);
    }
}
void preOrderTraversal(struct node *root) {
    if(root != NULL) {
        printf("%d ", root -> data);
        preOrderTraversal(root -> left);
        preOrderTraversal(root -> right);
    }
}

int main() {
    int n;
    printf("Enter no of nodes: ");
    scanf("%d", &n);
    char preOrder[max], inOrder[max];
    printf("Enter preOrder: ");
    for(int i=0; i<n; i++)
        scanf("%d", &preOrder[i]);
    printf("Enter inOrder: ");
    for(int i=0; i<n; i++)
        scanf("%d", &inOrder[i]);

    // struct node* root = createTree(preOrder, inOrder, n);
    int index = 0;
    struct node *root = createFullTree(preOrder, inOrder, 0, n-1, &index);

    printf("InOrder traversal of constructed tree is -\n");
    inOrderTraversal(root);
    printf("\nPreOrder traversal of constructed is -\n");
    preOrderTraversal(root);

    return 0;
}