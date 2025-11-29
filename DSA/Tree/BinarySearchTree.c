#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left, *right;
}node;

node* insert(node *root, int data) {
    if(root == NULL) {
        node *newNode = (node*)malloc(sizeof(node));
        newNode -> data = data;
        newNode -> left = newNode -> right = NULL;
        return newNode;
    }
    else if(data < root -> data) {
        root -> left = insert(root -> left, data);
    }
    else if(data > root -> data) {
        root -> right = insert(root -> right, data);
    }
    else if(data == root -> data) {
        printf("You inserted a duplicate data.\n");
    }
    return root;
}
void inOrder(node *root) {
    if(root != NULL) {
        inOrder(root -> left);
        printf("%d ", root -> data);
        inOrder(root -> right);
    }
}

node* delete(node *root, int x) {
    if(root == NULL) return root;

    if(x < root -> data)
        root -> left = delete(root -> left, x);
    else if(x > root -> data)
        root -> right = delete(root -> right, x);
    else {
        if(root -> left == NULL) {
            node *temp = root -> right;
            free(root);
            return temp;
        }
        else if(root -> right == NULL) {
            node *temp = root -> left;
            free(root);
            return temp;
        }
        node *temp = root -> right;
        while(temp -> left != NULL)
            temp = temp -> left;
        root -> data = temp -> data;
        root -> right = delete(root -> right, temp -> data);
    }
    return root;
}

int main() {
    int n, x;
    printf("Enter no of node to initilise the tree: ");
    scanf("%d", &n);
    node *root = NULL;
    printf("Enter data of tree one by one -\n");
    for(int i=0; i<n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }
    printf("\nInOrder of inserted data is -\n");
    inOrder(root);

    printf("\nWhich no you want to delete: ");
    scanf("%d", &x);
    root = delete(root, x);
    printf("InOrder after deletion -\n");
    inOrder(root);

    printf("\nEnter data: ");
    scanf("%d", &x);
    root = insert(root, x);
    printf("InOrder after addition -\n");
    inOrder(root);
    return 0;
}