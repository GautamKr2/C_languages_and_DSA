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