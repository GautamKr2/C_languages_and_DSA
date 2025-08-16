// Queue using array
#include"stdio.h"
#include<stdlib.h>
#define max 20
int Arr[max];
int front=-1, rear=-1;

void enqueue(){
    int x;
    printf("Enter data : ");
    scanf("%d",&x);
    if(rear == max-1)
        printf("Overflow codition !");
    else if(front == -1 && rear == -1){
        Arr[++front] = x;
        rear++;
    }
    else
        Arr[++rear] = x;
}
void dequeue(){
    if(front == -1 && rear == -1)
        printf("There is no any elements in the queue !\n");
    else if(front == rear) {
        rear = -1;
        printf("Dequed element is %d\n",Arr[front]);
        front = -1;
    }
    else
        printf("Dequed element is %d\n",Arr[front++]);
}
void display(){
    if(front == -1 && rear == -1)
        printf("There is no any elements in the queue !\n");
    else {
        printf("Elements of queue are :\n");
        for(int i=front; i<=rear; i++)
            printf("%d\t",Arr[i]);
    }
    printf("\n");
}
void Peek() {
    if(front == -1 && rear == -1)
        printf("There is no any elements in the queue !\n");
    else
        printf("First element is %d\n",Arr[front]);
}

int main(){
    int ch;
    while(1){
        printf("Press 1 for enqueue, 2 for dequeue, 3 for display, 4 for Peek, 5 for exit\nChoose any option : ");
        scanf("%d",&ch);
        switch(ch){
           case 1 : enqueue(); break;
           case 2 : dequeue(); break;
           case 3 : display(); break;
           case 4 : Peek(); break;
           case 5 : exit(0);
           default : printf("Invalid input !\n");
        }
    }
    return 0;
}



// Queue using linked list
/* #include"stdio.h"
#include"stdlib.h"
typedef struct node {
    int data;
    struct node *link;
}NODE;
NODE *front = NULL, *rear = NULL, *newNode, *temp;
void enqueue(){
    int x;
    printf("Enter data : ");
    scanf("%d",&x);
    newNode = (NODE*)malloc(sizeof(NODE));
    newNode -> data = x;
    newNode -> link = NULL;
    if(front == NULL && rear == NULL){
        front = newNode;
        rear = newNode;
    }
    else{
        rear -> link = newNode;
        rear = newNode;
    }
}
void dequeue(){
    if(front == NULL && rear == NULL){
        printf("Underflow condition !\nThere is no data in the queue.\n");
    }
    else{
        printf("Dequeued value is %d\n",front -> data);
        temp = front;
        front = front -> link;
        free(temp);
    }
}
void display(){
    temp = front;
    while(temp != NULL){
        printf("%d\t",temp -> data);
        temp = temp -> link;
    }
    printf("\n");
}
int main(){
    int ch;
    while(1){
        printf("Press 1 for enqueue, 2 for dequeue, 3 for display, 4 for exit\nChoose any option : ");
        scanf("%d",&ch);
        switch(ch){
            case 1 : enqueue(); break;
            case 2: dequeue(); break;
            case 3 : display(); break;
            case 4 : exit(0);
            default : printf("Invalid input !");
        }
    }
    return 0;
} */