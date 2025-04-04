#include<stdio.h>
#include<stdlib.h>

typedef struct NODE {
    int data;
    struct NODE *prev;
    struct NODE *next;
}NODE;
void create_ll(NODE **head, NODE **tail, int arr[], int n) {
    *head = NULL;
    *tail = NULL;
    int i = 0;
    while(i < n) {
        NODE *new_node = (NODE*)malloc(sizeof(NODE));
        if(*head == NULL) {
            new_node -> prev = NULL;
            new_node -> next = NULL;
            new_node -> data = arr[i];
            *head = new_node;
            *tail = new_node;
        }
        else {
            new_node -> next = NULL;
            new_node -> prev = *tail;
            new_node -> data = arr[i];
            (*tail) -> next = new_node;
            *tail = new_node;
        }
        i++;
    }
}
void display(NODE *head, NODE *tail) {
    NODE *temp = head;
    while(temp -> next != NULL) {
        printf("%d\t",temp -> data);
        temp = temp -> next;
    }
    printf("%d\n",temp -> data);
}
// void sort(int arr[], int n) {
//     int min;
//     for(int i=0; i<n; i++) {

//     }
// }

int main() {
    int n;
    printf("Enter no of elements in 1st array : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements of 1st array : ");
    for(int i=0; i<n; i++) {
        scanf("%d",&arr[i]);
    }
    printf("First array is :\n");
    for(int i=0; i<n; i++)
        printf("%d\t",arr[i]);
    printf("\n");
    NODE *head1, *tail1, *head2, *tail2;
    create_ll(&head1, &tail1, arr, n);
    printf("From linked list 1st array is :\n");
    display(head1, tail1);

    printf("Enter no of elements in 2nd array : ");
    scanf("%d",&n);
    printf("Enter elements of 2nd array : ");
    for(int i=0; i<n; i++) {
        scanf("%d",&arr[i]);
    }
    printf("second array is :\n");
    for(int i=0; i<n; i++)
        printf("%d\t",arr[i]);
    printf("\n");
    create_ll(&head2, &tail2, arr, n);
    printf("From linked list 1st array is :\n");
    display(head2, tail2);
    return 0;
}