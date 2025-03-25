// Insertion of elements in the linked list
/*#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *head, *new_node, *temp;
void Display(){
    temp = head;
    while(temp != 0){
        printf("%d\n",temp -> data);
        temp = temp -> next;
    }
}
void Insert_at_beginning(){
    new_node = (struct node*)malloc(sizeof(struct node));
    printf("Enter data which you want to insert(at begin): ");
    scanf("%d",&new_node -> data);
    new_node -> next = head;
    head = new_node;
}

void Insert_at_end(){
    new_node = (struct node*)malloc(sizeof(struct node));
    printf("Enter data which you want to insert at end: ");
    scanf("%d",&new_node -> data);
    temp = head;
    while(temp -> next != 0){
        temp = temp -> next;
    }
    temp -> next = new_node;
    new_node -> next = 0;
}
int main(){
    int choice=1, count = 0;
    //struct node *head, *new_node, *temp;
    head = 0;

    while(choice){
        new_node = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d",&new_node -> data);
        new_node -> next = 0;
        if(head == 0){
            head = new_node;
            temp = head;
        }
        else{
            temp -> next = new_node;
            temp = new_node;
        }
        printf("Are you want to continue (0 or 1): ");
        scanf("%d",&choice);
    }

    Display();

    // Insertion of node at beginning
    Insert_at_beginning();
    Display();

    // Insertion of node at the end
    Insert_at_end();
    temp = head;
    while(temp != 0){
        printf("%d\n",temp -> data);
        temp = temp -> next;
        count++;
    }

    // Insertion at a given location
    int pos, i;
    new_node = (struct node*)malloc(sizeof(struct node));
    printf("Enter position where you want to insert: ");
    scanf("%d",&pos);
    if(pos > count){
        printf("Invalid Position");
    }
    else{
        temp = head;
        for(i=1; i<pos-1; i++){
            temp = temp -> next;
        }
        printf("Enter data which you want to insert(at any position): ");
        scanf("%d",&new_node -> data);
        new_node -> next = temp -> next;
        temp -> next = new_node;
    }
    Display();

    return 0;
}*/


// Deletion of element from linked list
/*#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
void Display(struct node *head){
    struct node *temp = head;
    while(temp != 0){
        printf("%d\n",temp -> data);
        temp = temp -> next;
    }
}
// struct node *head, *new_node, *temp;

int main(){
    int choice, count = 0;
    struct node *head, *new_node, *temp;
    head = 0;
    while(choice){
        new_node = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d",&new_node -> data);
        new_node -> next = 0;
        if(head == 0){
            head = new_node;
            temp = head;
        }
        else{
            temp -> next = new_node;
            temp = new_node;
        }
        printf("Are u want to continue(0 or 1): ");
        scanf("%d",&choice);
    }                                               
    Display(head);

    // Deletion of 1st element
    printf("\n");
    temp = head;
    head = head -> next;
    free(temp);
    Display(head);

    // Deletion of last element
    printf("\n");
    temp = head;
    while((temp -> next) -> next != 0){
        temp = temp -> next;
    }
    count = 0;
    free(temp -> next);
    temp -> next = 0;
    Display(head);

    // Deletion from given position
    printf("\n");
    int pos;
    printf("Enter position from where u want to delete: ");
    scanf("%d",&pos);
    temp = head;
    for(int i=1; i<pos-1; i++){
        temp = temp -> next;
    }
    struct node *next_node = temp -> next;
    temp -> next = next_node -> next;
    free(next_node);
    Display(head);

    return 0;
}*/



// Code for reverse a linked list
/*#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head, *new_node, *temp;
void Display(){
    temp = head;
    while(temp != 0){
        printf("%d\n",temp -> data);
        temp = temp -> next;
    }
}
void Reverse(){
    struct node *prev_node, *current_node, *next_node;
    prev_node = 0;
    current_node = head;
    next_node = head;
    while(next_node != 0){
        next_node = next_node -> next;
        current_node -> next = prev_node;
        prev_node = current_node;
        current_node = next_node;
    }
    head = prev_node;
}
int main(){
    int choice;
    //struct node *head, *new_node, *temp;
    head = 0;
    while(choice){
        new_node = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d",&new_node -> data);
        new_node -> next = 0;
        if(head == 0){
            head = new_node;
            temp = head;
        }
        else{
            temp -> next = new_node;
            temp = new_node;
        }
        printf("Are you want to continue(0 or 1): ");
        scanf("%d",&choice);
    }
    Display();

    printf("\n");
    Reverse();
    Display();
    return 0;
}*/



// For doubly linked list
/*#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *head, *new_node, *tail;
void Display(){
    struct node *temp;
    temp = head;
    while(temp != 0){
        printf("%d\n",temp -> data);
        temp = temp -> next;
    }
}
void Create_doubly_l_l(){
    head = 0;
    int choice = 1;
    while(choice){
        new_node = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d",&new_node -> data);
        new_node -> prev = 0;
        new_node -> next = 0;
        if(head == 0){
            head = new_node;
            tail = new_node;
        }
        else{
            tail -> next = new_node;
            new_node -> prev = tail;
            tail = new_node;
        }
        printf("Are you want to continue(0 or 1): ");
        scanf("%d",&choice);
    }
}
void Insert_at_beginning(){
    new_node = (struct node*)malloc(sizeof(struct  node));
    printf("Enter data which you want to insert at begin: ");
    scanf("%d",&new_node -> data);
    new_node -> prev = 0;
    new_node -> next = head;
    head -> prev = new_node;
    head = new_node;
}
void Insert_at_end(){
    new_node = (struct node*)malloc(sizeof(struct node));
    printf("Enter data which you want to insert at end: ");
    scanf("%d",&new_node -> data);
    new_node -> next = 0;
    new_node -> prev = tail;
    tail -> next = new_node;
    tail = new_node;
}
void Insert_at_specific_position(){
    int pos, i = 1;
    struct node *temp;
    printf("Enter position where you want to insert: ");
    scanf("%d",&pos);
    temp = head;
    while(i < pos-1){
        temp = temp -> next;
        i++;
    }
    if(pos == 1){
        Insert_at_beginning();
    }
    else{
        new_node = (struct node*)malloc(sizeof(struct node));
        printf("Enter data which you want to insert at position: ");
        scanf("%d",&new_node -> data);
        new_node -> prev = temp;
        new_node -> next = temp -> next;
        (temp -> next) -> prev = new_node;
        temp -> next = new_node;
    }
}
void Delete_from_beginning(){
    struct node *temp;
    if(head == 0){
        printf("List is empty");
    }
    else{
        temp = head;
        head = head -> next;
        head -> prev = 0;
        free(temp);
    }
}
void Delete_from_end(){
    struct node *temp;
    temp = tail;
    tail = tail -> prev;
    tail -> next = 0;
    free(temp);
}
void Delete_from_specific_position(){
    struct node *temp;
    int pos, i=1;
    printf("Enter position from where you want to delete: ");
    scanf("%d",&pos);
    temp = head;
    while(i < pos){
        temp = temp -> next;
        i++;
    }
    (temp -> next) -> prev = temp -> prev;
    (temp -> prev) -> next = temp -> next;
    free(temp);
}
void Reverse_doubly_l_l(){
    struct node *currentNode, *nextNode;
    currentNode = head;
    while(nextNode != 0){
        nextNode = currentNode -> next;
        currentNode -> next = currentNode -> prev;
        currentNode -> prev = nextNode;
        currentNode = nextNode;
    }
    currentNode = head;
    head = tail;
    tail = currentNode;
}
int main(){
    // Implementation section
    // Create_doubly_l_l();
    // Display();


    // Insertion section
    // Create_doubly_l_l();
    // Display();
    // printf("\n");
    // Insert_at_beginning();
    // Display();

    // printf("\n");
    // Insert_at_end();
    // Display();

    // printf("\n");
    // Insert_at_specific_position();
    // Display();


    // Deletion section
    // Create_doubly_l_l();
    // Display();
    // printf("\n");
    // Delete_from_beginning();
    // Display();

    // printf("\n");
    // Delete_from_end();
    // Display();

    // printf("\n");
    // Delete_from_specific_position();
    // Display();


    // Reverse section
    Create_doubly_l_l();
    Display();
    printf("\n");
    Reverse_doubly_l_l();
    Display();
    return 0;
}*/




// Circular link list
/*#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head, *new_node, *temp, *tail;

// By maintaining head pointer only
void Create_Circular_l_l();
void Display();
void Insert_at_beginning();
void Insert_at_end();
void Insert_at_specific_position();
void Delete_from_beginning();
void Delete_from_end();
void Delete_from_specific_position();
void Reverse_circular_l_l();



// By maintaining head pointer only
void Create_Circular_l_l_2();
void Display_2();
void Insert_at_beginning_2();
void Insert_at_end_2();
void Insert_at_specific_position_2();
void Delete_from_beginning_2();
void Delete_from_end_2();
void Delete_from_specific_position_2();
void Reverse_circular_l_l_2();

int main(){
    // By maintaining only head pointer
    // Insertion section
    Create_Circular_l_l();
    Display();
    printf("\n");

    Insert_at_beginning();
    Display();
    printf("\n");

    Insert_at_end();
    Display();
    printf("\n");

    Insert_at_specific_position();
    Display();
    printf("\n");


    // Deletion section
    Delete_from_beginning();
    printf("After deletion from beginning, list are :\n");
    Display();
    printf("\n");

    Delete_from_end();
    printf("After deletion from end, list are :\n");
    Display();
    printf("\n");

    Delete_from_specific_position();
    printf("After deletion from specific position, list are :\n");
    Display();
    printf("\n");


    // Reverse section
    Reverse_circular_l_l();
    printf("After reversing, list are :\n");
    Display();



    // By maintaining only tail pointer
    // Insertion section
    // Create_Circular_l_l_2();
    // Display_2();
    // printf("\n");

    // Insert_at_beginning_2();
    // Display_2();
    // printf("\n");

    // Insert_at_end_2();
    // Display_2();
    // printf("\n");

    // Insert_at_specific_position_2();
    // Display_2();
    // printf("\n");


    // Deletion section
    // Delete_from_beginning_2();
    // printf("After deletion from beginning, list are : \n");
    // Display_2();
    // printf("\n");

    // Delete_from_end_2();
    // printf("After deletion from end, list are : \n");
    // Display_2();
    // printf("\n");

    // Delete_from_specific_position_2();
    // printf("After deletion from specific position, list are : \n");
    // Display_2();
    // printf("\n");


    // Reverse section
    // Reverse_circular_l_l_2();
    // printf("After reversing, list are : \n");
    // Display_2();
    return 0;
}
void Create_Circular_l_l(){
    int choice = 1;
    head = 0;
    while(choice){
        new_node = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d",&new_node -> data);
        new_node -> next = 0;
        if(head == 0){
            head = new_node;
            temp = new_node;
        }
        else{
            temp -> next = new_node;
            temp = new_node;
        }
        printf("Are you want to continue(0 or 1): ");
        scanf("%d",&choice);
    }
    temp -> next = head;
}
void Display(){
    temp = head;
    while(temp -> next != head){
        printf("%d\t",temp -> data);
        temp = temp -> next;
    }
    printf("%d\t",temp -> data);
}
void Insert_at_beginning(){
    new_node = (struct node*)malloc(sizeof(struct node));
    printf("Enter data which you want to insert at begin: ");
    scanf("%d",&new_node -> data);
    new_node -> next = head;
    head = new_node;
    temp -> next = head;
}
void Insert_at_end(){
    temp = head;
    while(temp -> next != head){
        temp = temp -> next;
    }
    new_node = (struct node*)malloc(sizeof(struct node));
    printf("Enter data which you want to insert at end: ");
    scanf("%d",&new_node -> data);
    new_node -> next = temp -> next;
    temp -> next = new_node;
}
void Insert_at_specific_position(){
    int pos, i=1;
    printf("Enter position where you want to insert: ");
    scanf("%d",&pos);
    temp = head;
    while(i < pos-1){
        temp = temp -> next;
        i++;
    }
    new_node = (struct node*)malloc(sizeof(struct node));
    printf("Enter data which you want to insert at given position: ");
    scanf("%d",&new_node -> data);
    new_node -> next = temp -> next;
    temp -> next = new_node;
}
void Delete_from_beginning(){
    struct node *first_node;
    first_node = head;
    temp = head;
    while(temp -> next != head){
        temp = temp -> next;
    }
    temp -> next = head -> next;
    head = first_node -> next;
    free(first_node);
}
void Delete_from_end(){
    struct node *last_node;
    temp = head;
    while((temp -> next) -> next != head){
        temp = temp -> next;
    }
    last_node = temp -> next;
    temp -> next = last_node -> next;
    free(last_node);
}
void Delete_from_specific_position(){
    struct node *next_node;
    int pos, i=1;
    printf("Enter position where you want to deletes: ");
    scanf("%d",&pos);
    if(pos == 1){
        Delete_from_beginning();
    }
    else{
        temp = head;
        while(i < pos-1){
            temp = temp -> next;
            i++;
        }
        next_node = temp -> next;
        temp -> next = next_node -> next;
        free(next_node);
    }
}
void Reverse_circular_l_l(){
    struct node *current_node, *prev_node, *next_node, *last;
    last = head;
    while(last -> next != head){
        last = last -> next;
    }
    prev_node = 0;
    current_node = head;
    next_node = current_node -> next;
    while(current_node != last){
        prev_node = current_node;
        current_node = next_node;
        next_node = current_node -> next;
        current_node -> next = prev_node;
    }
    next_node -> next = current_node;
    head = current_node;
}




void Create_Circular_l_l_2(){
    int choice = 1;
    tail = 0;
    while(choice){
        new_node = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d",&new_node -> data);
        new_node -> next = 0;
        if(tail == 0){
            tail = new_node;
            tail -> next = new_node;
        }
        else{
            new_node -> next = tail -> next;
            tail -> next = new_node;
            tail = new_node;
        }
        printf("Are you want to continue(0 or 1): ");
        scanf("%d",&choice);
    }
}
void Display_2(){
    temp = tail -> next;
    while(temp -> next != tail -> next){
        printf("%d\t",temp -> data);
        temp = temp -> next;
    }
    printf("%d\t",temp -> data);
}
void Insert_at_beginning_2(){
    new_node = (struct node*)malloc(sizeof(struct node));
    printf("Enter data which you want to insert at begin: ");
    scanf("%d",&new_node -> data);
    new_node -> next = tail -> next;
    tail -> next = new_node;
}
void Insert_at_end_2(){
    new_node = (struct node*)malloc(sizeof(struct node));
    printf("Enter data which you want to insert at end: ");
    scanf("%d",&new_node -> data);
    new_node -> next = tail -> next;
    tail -> next = new_node;
    tail = new_node;
}
void Insert_at_specific_position_2(){
    int pos, i = 1;
    printf("Enter position where you want to insert: ");
    scanf("%d",&pos);
    temp = tail -> next;
    while(i < pos - 1){
        temp = temp -> next;
        i++;
    }
    new_node = (struct node*)malloc(sizeof(struct node));
    printf("Enter data which you want to insert at specific position: ");
    scanf("%d",&new_node -> data);
    new_node -> next = temp -> next;
    temp -> next = new_node;
}
void Delete_from_beginning_2(){
    temp = tail -> next;
    tail -> next = temp -> next;
    free(temp);
}
void Delete_from_end_2(){
    temp = tail -> next;
    while(temp -> next != tail){
        temp = temp -> next;
    }
    temp -> next = tail -> next;
    free(tail);
    tail = temp;
}
void Delete_from_specific_position_2(){
    struct node *next_node;
    int pos, i=1;
    printf("Enter position from where you want to delete: ");
    scanf("%d",&pos);
    temp = tail -> next;
    while(i < pos-1){
        temp = temp -> next;
        i++;
    }
    next_node = temp -> next;
    temp -> next = next_node -> next;
    free(next_node);
}
void Reverse_circular_l_l_2(){
    struct node *current_node, *next_node, *prev_node;
    prev_node = 0;
    current_node = tail -> next;
    next_node = current_node -> next;
    while(current_node != tail){
        prev_node = current_node;
        current_node = next_node;
        next_node = current_node -> next;
        current_node -> next = prev_node;
    }
    next_node -> next = current_node;
    tail = next_node;
}*/





// Doubly circular linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *new_node, *head, *temp, *tail;
void Create_doubly_circular_l_l();
void Display();
int Count_no_of_elements_in_list();
void Insert_at_beginning();
void Insert_at_end();
void Insert_at_specific_position();
void Delete_from_beginning();
void Delete_from_end();
void Delete_from_specific_position();

int main(){
    // Insertion section
    Create_doubly_circular_l_l();
    Display();
    printf("\n");

    Insert_at_beginning();
    Display();
    printf("\n");

    Insert_at_end();
    Display();
    printf("\n");

    Insert_at_specific_position();
    Display();
    printf("\n");


    // Deletion section
    Delete_from_beginning();
    printf("After deletion from beginning, list are :\n");
    Display();
    printf("\n");

    Delete_from_end();
    printf("After deletion from end, list are :\n");
    Display();
    printf("\n");

    Delete_from_specific_position();
    printf("After deletion from specific position, list are :\n");
    Display();
    printf("\n");

    return 0;
}
void Create_doubly_circular_l_l(){
    int choice = 1;
    head = 0;
    while(choice){
        new_node = (struct node*)malloc(sizeof(struct node));
        printf("Enter data : ");
        scanf("%d",&new_node -> data);
        if(head == 0){
            head = new_node;
            tail = new_node;
            new_node -> next = new_node;
            new_node -> prev = new_node;
        }
        else{
            tail -> next = new_node;
            new_node -> next = head;
            new_node -> prev = tail;
            head -> prev = new_node;
            tail = new_node;
        }
        printf("Are you want to continue (0 or 1) : ");
        scanf("%d",&choice);
    }
}
void Display(){
    temp = head;
    while(temp != tail){
        printf("%d\t",temp -> data);
        temp = temp -> next;
    }
    printf("%d\t",temp -> data);
}
int Count_no_of_elements_in_list(){
    int count = 0;
    temp = head;
    while(temp != tail){
        count++;
        temp = temp -> next;
    }
    return count + 1;
}
void Insert_at_beginning(){
    new_node = (struct node*)malloc(sizeof(struct node));
    printf("Enter data which you want to insert at beginning: ");
    scanf("%d",&new_node -> data);
    head -> prev = new_node;
    new_node -> next = head;
    new_node -> prev = tail;
    tail -> next = new_node;
    head = new_node;
}
void Insert_at_end(){
    new_node = (struct node*)malloc(sizeof(struct node));
    printf("Enter data which you want to insert at end : ");
    scanf("%d",&new_node -> data);
    tail -> next = new_node;
    new_node -> prev = tail;
    new_node -> next = head;
    head -> prev = new_node;
    tail = new_node;
}
void Insert_at_specific_position(){
    struct node *next_node;
    int pos, i=1;
    printf("Enter position where you want insert : ");
    scanf("%d",&pos);
    temp = head;
    if(pos == 1){
        Insert_at_beginning();
    }
    else{
        while(i < pos-1){
            temp = temp -> next;
            i++;
        }
        next_node = temp -> next;
        new_node = (struct node*)malloc(sizeof(struct node));
        printf("Enter data which you want to insert at specific position : ");
        scanf("%d",&new_node -> data);
        new_node -> next = next_node;
        next_node -> prev = new_node;
        temp -> next = new_node;
        new_node -> prev = temp;
    }
}


void Delete_from_beginning(){
    temp = head;
    (temp -> next) -> prev = tail;
    tail -> next = head -> next;
    head = temp -> next;
    free(temp);
}
void Delete_from_end(){
    temp = head;
    while(temp -> next != tail){
        temp = temp -> next;
    }
    temp -> next = tail -> next;
    head -> prev = temp;
    temp = tail;
    tail = head -> prev;
    free(temp);
}
void Delete_from_specific_position(){
    struct node *nextNode;
    int pos, i = 1;
    printf("Enter position from where you want to delete : ");
    scanf("%d",&pos);
    temp = head;
    while(i < pos-1){
        temp = temp -> next;
        i++;
    }
    if(pos == 1)
        Delete_from_beginning();
    else{
        nextNode = temp -> next;
        temp -> next = nextNode -> next;
        (nextNode -> next) -> prev = temp;
        free(nextNode);
    }
}