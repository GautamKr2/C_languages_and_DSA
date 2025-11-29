#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Search for value in postorder[l..r]
int searchPost(int post[], int l, int r, int val) {
    for (int i = l; i <= r; i++) {
        if (post[i] == val)
            return i;
    }
    return -1;
}

// Recursive utility to construct tree
struct Node* constructTreeUtil(int pre[], int post[], int *preIndex,
                               int l, int h, int size) {
    if (*preIndex >= size || l > h)
        return NULL;

    // Create root from current preorder element
    struct Node *root = createNode(pre[*preIndex]);
    (*preIndex)++;

    // If this is a leaf node or no range left
    if (l == h || *preIndex >= size)
        return root;

    // Next preorder element is root of left subtree
    int i = searchPost(post, l, h, pre[*preIndex]);

    // If found, build left and right subtrees
    if (i != -1 && i <= h) {
        root->left  = constructTreeUtil(pre, post, preIndex, l, i, size);
        root->right = constructTreeUtil(pre, post, preIndex, i + 1, h - 1, size);
    }

    return root;
}

struct Node* constructTree(int pre[], int post[], int size) {
    int preIndex = 0;
    return constructTreeUtil(pre, post, &preIndex, 0, size - 1, size);
}

// Inorder traversal for verification
void printInorder(struct Node *root) {
    if (root == NULL) return;
    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int pre[100], post[100];

    printf("Enter preorder traversal (%d elements): ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &pre[i]);

    printf("Enter postorder traversal (%d elements): ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &post[i]);

    struct Node *root = constructTree(pre, post, n);

    printf("Inorder of constructed tree: ");
    printInorder(root);
    printf("\n");

    return 0;
}
