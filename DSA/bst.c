#include<stdio.h>
#include<stdlib.h>
struct tree {
    struct tree *left;
    int data;
    struct tree *right;
};
typedef struct tree *bst;
bst root = NULL, temp;
bst create(bst r, int x){
    if(r == NULL){
        temp = (bst)malloc(sizeof(struct tree));
        temp -> data = x;
        temp -> left = NULL;
        temp -> right = NULL;
        return temp;
    }
    else if(x < r -> data){
        r -> left = create(r -> left, x);
        return r;
    }
    else if(x > r -> data){
        r -> right = create(r -> right, x);
        return r;
    }
}
void PO(bst r){
    if(r != NULL){
        printf("%d\t",r -> data);
        PO(r -> left);
        PO(r -> right);
    }
}
void IO(bst r){
    if(r == NULL)
        return;
    else{
        IO(r -> left);
        printf("%d\t",r -> data);
        IO(r -> right);
    }
}
void PoO(bst r){
    if(r == NULL)
        return;
    else{
        PoO(r -> left);
        PoO(r -> right);
        printf("%d\t",r -> data);
    }
}
int main(){
    int max, x, i;
    printf("Enter initial no of element required : ");
    scanf("%d",&max);
    for(i=0; i<max; i++){
        printf("Enter value : ");
        scanf("%d",&x);
        root = create(root, x);
    }
    printf("Pre order of this tree is -\n");
    PO(root);
    printf("\nIn order of this tree is -\n");
    IO(root);
    printf("\nPost order of this tree is -\n");
    PoO(root);
    return 0;
}