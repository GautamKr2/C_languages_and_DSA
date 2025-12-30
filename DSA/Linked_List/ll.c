/*#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
typedef struct node *ll;
ll first = NULL, last, run, temp;

void create();
void display();
void insert_at_first();
void insert_at_last();
void insert_at_middle();
void delete_from_first();
void delete_from_last();
void delete_from_middle();

int main(){
    int ch;
    while(1){
        printf("Enter 1 for create,\n2 for display,\n3 for insert at first,\n4 for insert at last,\n5 for insert at middle,\n6 for delete from first,\n7 for delete from last,\n8 for delete from middle,\n9 for exit,\nChoose any option : ");
        scanf("%d",&ch);
        switch(ch){
            case 1 : create(); break;
            case 2 : display(); break;
            case 3 : insert_at_first(); break;
            case 4 : insert_at_last(); break;
            case 5 : insert_at_middle(); break;
            case 6 : delete_from_first(); break;
            case 7 : delete_from_last(); break;
            case 8 : delete_from_middle(); break;
            case 9 : exit(0);
        }
    }
    return 0;
}

void create(){
    int x, y, max;
    printf("Enter the nodes to be created : ");
    scanf("%d", &max);
    printf("Enter the first data in the list : ");
    scanf("%d", &x);
    temp = (ll) malloc(sizeof(struct node));
    temp -> data = x;
    temp -> next = NULL;
    first = temp;
    last = temp;
    for(int i=1; i<max; i++){
        printf("Enter the next value : ");
        scanf("%d", &y);
        temp = (ll) malloc(sizeof(struct node));
        temp -> data = y;
        temp -> next = NULL;
        last -> next = temp;
        last = temp;;
    }
}
void display(){
    run = first;
    while(run != NULL){
        printf("%d  ",run -> data);
        run = run -> next;
    }
    printf("\n");
}
void insert_at_first(){
    int x;
    printf("Enter value which you want to insert at first : ");
    scanf("%d", &x);
    temp = (ll) malloc(sizeof(struct node));
    temp -> data = x;
    temp -> next = first;
    first = temp;
}
void insert_at_last(){
    int x;
    printf("Enter value which you want to insert at last : ");
    scanf("%d", &x);
    temp = (ll) malloc(sizeof(struct node));
    temp -> data = x;
    temp -> next = NULL;
    last -> next = temp;
    last = temp;
}
void insert_at_middle(){
    ll next_node;
    int x, pos, count = 1;
    printf("Enter value which you want to insert at middle : ");
    scanf("%d", &x);
    printf("After which node you want to insert : ");
    scanf("%d", &pos);
    temp = (ll) malloc(sizeof(struct node));
    temp -> data = x;
    run = first;
    while(pos > count){
        run = run -> next;
        count++;
    }
    next_node = run -> next;
    run -> next = temp;
    temp -> next = next_node;
}
void delete_from_first(){
    if(first == NULL){
        printf("List is empty !\n");
    }
    else{
        run = first;
        first = first -> next;
        free(run);
    }
}
void delete_from_last(){
    run = first;
    while(run -> next != last){
        run = run -> next;
    }
    last = run;
    run = run -> next;
    last -> next = NULL;
    free(run);
}
void delete_from_middle(){
    int pos, count = 1;
    printf("Which node you want to delete?");
    scanf("%d",&pos);
    run = first;
    while(pos-1 > count){
        run = run -> next;
        count++;
    }
    temp = run -> next;
    run -> next = temp -> next;
    free(temp);
}*/



// For reverse of a linked list
#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int data;
    struct node *next;
}ll;
ll *new_node, *temp, *head=NULL, *tail;
void create(){
    int x;
    printf("Enter data : ");
    scanf("%d",&x);
    new_node = (ll*)malloc(sizeof(ll));
    new_node -> data = x;
    new_node -> next = NULL;
    if(head == NULL){
        head = new_node;
        tail = new_node;
    }
    else{
        tail -> next = new_node;
        tail = new_node;
    }
}
void display(){
    printf("Elements of list are :\n");
    temp = head;
    while(temp != NULL){
        printf("%d\t",temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}
void reverse(){
    ll *curr, *prev=NULL, *next;
    curr = head;
    while(curr != NULL){
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}
int main(){
    int choice;
    while(1){
        printf("Enter 1 for create, 2 for display, 3 for reverse, 4 for exit\nChoose any option : ");
        scanf("%d",&choice);
        switch(choice){
            case 1 : create(); break;
            case 2 : display(); break;
            case 3 : reverse(); break;
            case 4 : exit(0);
            default : printf("Invalid input!\n");
        }
    }
    return 0;
}