#include"stdio.h"
#include"stdlib.h"
typedef struct node {
    int data;
    struct node *link;
}NODE;
NODE* front = NULL, *rear = NULL, *newNode,* temp;
void enqueue() {
    int x;
    printf("Enter data : ");
    scanf("%d",&x);
    newNode = (NODE*)malloc(sizeof(NODE));
    newNode -> data = x;
    newNode -> link = NULL;
    if(front == NULL && rear == NULL)
        front = rear = newNode;
    else{
        rear -> link = newNode;
        rear = newNode;
    }
}
void dequeue() {
    if(front == NULL && rear == NULL)
        printf("There is no data in the queue.\n");
    else if(front == rear) {
        printf("Dequed value is %d.\n",front->data);
        front = rear = NULL;
    }
    else{
        printf("Dequeued value is %d\n",front -> data);
        temp = front;
        front = front -> link;
        free(temp);
    }
}
void display() {
    if(front == NULL)
        printf("No any element in the queue.");
    else {
        temp = front;
        while(temp != NULL){
            printf("%d\t",temp -> data);
            temp = temp -> link;
        }
    }
    printf("\n");
}
void Peek() {
    if(front == NULL)
        printf("No any element in queue !\n");
    else
        printf("Front element of the queue is %d.\n",front->data);
}
int main() {
    int ch;
    while(1){
        printf("Press 1 for enqueue, 2 for dequeue, 3 for display, 4 for Peek 5 for exit\nChoose any option : ");
        scanf("%d",&ch);
        switch(ch){
            case 1 : enqueue(); break;
            case 2: dequeue(); break;
            case 3 : display(); break;
            case 4 : Peek(); break;
            case 5 : exit(0);
            default : printf("Invalid input !\nPress a valid option -\n");
        }
    }
    return 0;
}