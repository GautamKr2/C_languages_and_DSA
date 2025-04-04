#include<stdio.h>
#include<stdlib.h>

typedef struct NODE { // User defined data type
    int data;
    struct NODE *prev;
    struct NODE *next;
}NODE;
void create_ll(NODE **head, NODE **tail, int arr[], int n) { // To create a linked list
    *head = NULL;
    *tail = NULL;
    int i = 0;
    while(i < n) {
        NODE *new_node = (NODE*)malloc(sizeof(NODE)); // Dynamically allocate memory
        if(*head == NULL) { // For first node
            new_node -> prev = NULL;
            new_node -> next = NULL;
            new_node -> data = arr[i];
            *head = new_node;
            *tail = new_node;
        }
        else { // For other than first node
            new_node -> next = NULL;
            new_node -> prev = *tail;
            new_node -> data = arr[i];
            (*tail) -> next = new_node;
            *tail = new_node;
        }
        i++;
    }
}
void display(NODE *head, NODE *tail) { // Function for displaying the linked list
    NODE *temp = head;
    while(temp -> next != NULL) {
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
    sort(arr, n); // Calling of sort function
    printf("First sorted array is :\n");
    for(int i=0; i<n; i++)
        printf("%d\t",arr[i]);
    printf("\n");
    NODE *head1, *tail1, *head2, *tail2;
    create_ll(&head1, &tail1, arr, n); // Creating 1st linked list
    printf("From linked list 1st array is :\n");
    display(head1, tail1); // Display 1st linked list

    printf("\nEnter no of elements in 2nd array : ");
    scanf("%d",&n);
    printf("Enter elements of 2nd array : ");
    for(int i=0; i<n; i++) {
        scanf("%d",&arr[i]);
    }
    printf("Second array is :\n");
    for(int i=0; i<n; i++)
        printf("%d\t",arr[i]);
    printf("\n");
    sort(arr, n);
    printf("Second sorted array is :\n");
    for(int i=0; i<n; i++)
        printf("%d\t",arr[i]);
    printf("\n");
    create_ll(&head2, &tail2, arr, n); // Creating 2nd linked list
    printf("From linked list 1st array is :\n");
    display(head2, tail2); // Display 2nd linked list
    return 0;
}