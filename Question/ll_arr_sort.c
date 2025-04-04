#include<stdio.h>
#include<stdlib.h>

typedef struct NODE { // User defined data type
    int data;
    struct NODE *prev;
    struct NODE *next;
}NODE;
void create_ll(NODE **head, NODE **tail, int arr[], int n) { // To create a linked list from array
    *head = NULL;
    *tail = NULL;
    int i = 0;
    while(i < n) {
        NODE *new_node = (NODE*)malloc(sizeof(NODE)); // Dynamically allocate memory
        if(*head == NULL) { // For first node
            new_node -> prev = new_node;
            new_node -> next = new_node;
            new_node -> data = arr[i];
            *head = new_node;
            *tail = new_node;
        }
        else { // For other than first node
            new_node -> next = *head;
            (*head) -> prev = new_node;
            new_node -> prev = *tail;
            new_node -> data = arr[i];
            (*tail) -> next = new_node;
            *tail = new_node;
        }
        i++;
    }
}
void display(NODE *head) { // Function for displaying the linked list
    NODE *temp = head;
    while(temp -> next != head) {
        printf("%d\t",temp -> data);
        temp = temp -> next;
    }
    printf("%d\n",temp -> data);
}
void swap(int *a, int *b) { // Function for swapping two numbers
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}
void sort(int arr[], int n) { // Function for sorting array elements
    int min;
    for(int i=0; i<n; i++) {
        min = i;
        for(int j=i+1; j<n; j++) {
            if(arr[min] > arr[j])
                min = j;
        }
        if(min != i)
            swap(&arr[min], &arr[i]);
    }
}
void mrgd_ll(NODE **temp1, NODE **temp2, NODE **head, NODE **tail, int x) {
    NODE *new_node = (NODE*)malloc(sizeof(NODE));
    NODE *temp;
    if(*head == NULL) {
        new_node -> data = x;
        new_node -> prev = new_node;
        new_node -> next = new_node;
        *head = new_node;
        *tail = new_node;

        temp = *temp1;
        *temp1 = temp -> next;
        (*temp1) -> prev = *temp2;
        (*temp2) -> next = *temp1;
        free(temp);
    }
    else {
        new_node -> data = x;
        new_node -> next = *head;
        (*head) -> prev = new_node;
        new_node -> prev = *tail;
        (*tail) -> next = new_node;
        *tail = new_node;

        temp = *temp1;
        *temp1 = temp -> next;
        (*temp1) -> prev = *temp2;
        (*temp2) -> next = *temp1;
        free(temp);
    }
}

int main() {
    int n1;
    printf("Enter no of elements in 1st array : ");
    scanf("%d",&n1);
    int arr1[n1];
    printf("Enter elements of 1st array : ");
    for(int i=0; i<n1; i++) {
        scanf("%d",&arr1[i]);
    }
    printf("First array is :\n");
    for(int i=0; i<n1; i++)
        printf("%d\t",arr1[i]);
    printf("\n");
    sort(arr1, n1); // Calling of sort function
    printf("First sorted array is :\n");
    for(int i=0; i<n1; i++)
        printf("%d\t",arr1[i]);
    printf("\n");
    NODE *head1, *tail1;
    create_ll(&head1, &tail1, arr1, n1); // Creating 1st linked list
    printf("From linked list 1st array is :\n");
    display(head1); // Display 1st linked list

    int n2;
    printf("\nEnter no of elements in 2nd array : ");
    scanf("%d",&n2);
    int arr2[n2];
    printf("Enter elements of 2nd array : ");
    for(int i=0; i<n2; i++) {
        scanf("%d",&arr2[i]);
    }
    printf("Second array is :\n");
    for(int i=0; i<n2; i++)
        printf("%d\t",arr2[i]);
    printf("\n");
    sort(arr2, n2);
    printf("Second sorted array is :\n");
    for(int i=0; i<n2; i++)
        printf("%d\t",arr2[i]);
    printf("\n");
    NODE *head2, *tail2;
    create_ll(&head2, &tail2, arr2, n2); // Creating 2nd linked list
    printf("From linked list 1st array is :\n");
    display(head2); // Display 2nd linked list

    // For merging two sorted linked lists' elements
    int j = 0, k = 0;
    NODE *head = NULL, *tail = NULL;
    for(int i=0; i<n1+n2; i++) {
        if(arr1[j] < arr2[k]) {
            mrgd_ll(&head1, &tail1, &head, &tail, arr1[j]);
            j++;
        }
        else {
            mrgd_ll(&head2, &tail2, &head, &tail, arr2[k]);
            k++;
        }
    }
    printf("\nMerged linked list as sorted elements are :\n");
    display(head);
    return 0;
}