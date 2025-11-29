#include <stdio.h>
#include <stdlib.h>
#define max 100

typedef struct node {
    int data;
    struct node *left, *right;
} node;

node* createFullTree(char postOrder[], char inOrder[], int start, int end, int *index) {
    if(end < start) return NULL;
    int currVal = postOrder[*index];
    (*index)--;
    node *root = (node*)malloc(sizeof(node));
    root -> data = currVal;
    root -> left = root -> right = NULL;

    if(start == end) return root;

    int valIdx;
    for(int i=end; i>=start; i--)
        if(inOrder[i] == currVal) {
            valIdx = i;
            break;
        }
        
    root -> right = createFullTree(postOrder, inOrder, valIdx+1, end, index);
    root -> left = createFullTree(postOrder, inOrder, start, valIdx-1, index);
    return root;
}

void postOrderTraversal(node *root) {
    if(root != NULL) {
        postOrderTraversal(root -> left);
        postOrderTraversal(root -> right);
        printf("%d ", root -> data);
    }
}
void inOrderTraversal(node *root) {
    if(root != NULL) {
        inOrderTraversal(root -> left);
        printf("%d ", root -> data);
        inOrderTraversal(root -> right);
    }
}

int main() {
    int n;
    printf("Enter no of nodes: ");
    scanf("%d", &n);
    char postOrder[max], inOrder[max];
    printf("Enter postOrder: ");
    for(int i=0; i<n; i++)
        scanf("%d", &postOrder[i]);
    printf("Enter inOrder: ");
    for(int i=0; i<n; i++)
        scanf("%d", &inOrder[i]);

    int index = n-1;
    node* root = createFullTree(postOrder, inOrder, 0, n-1, &index);

    printf("PostOrder traversal of constructed tree -\n");
    postOrderTraversal(root);
    printf("\nInOrder traversal of constructed tree -\n");
    inOrderTraversal(root);
    return 0;
}