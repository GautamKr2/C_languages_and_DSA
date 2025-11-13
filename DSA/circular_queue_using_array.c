// Circular Queue using array
#include"stdio.h"
#include"stdlib.h"
#define max 20
int Arr[max];
int front = -1, rear = -1;
int isFull() {
    if(front == (rear+1)%max)
        return 1;
    return 0;
}
int isEmpty() {
    if(front == -1 && rear == -1)
        return 1;
    return 0;
}
void enqueue() {
    int x;
    printf("Enter data : ");
    scanf("%d",&x);
    if(isFull())
        printf("Overflow condition !\n");
    else{
        if(front == -1)
            front = 0;
        rear = (rear + 1) % max;
        Arr[rear] = x;
    }
}
void dequeue() {
    int el;
    if(isEmpty())
        printf("Underflow condition !\n");
    else{
        el = Arr[front];
        if(front == rear)
            front = rear = -1;
        else
            front = (front + 1) % max;
        printf("Dequeued element is %d.\n",el);
    }
}
void Peek() {
    if(isEmpty())
        printf("No any element in the queue.\n");
    else
        printf("Front element is %d.\n",Arr[front]);
}
void display() {
    int i;
    if(isEmpty())
        printf("Underflow condition !\n");
    else {
        for(i=front; i!=rear; i=(i+1)%max)
            printf("%d\t",Arr[i]);
        printf("%d\n",Arr[i]);
    }
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
            default : printf("Invalid input !");
        }
    }
    return 0;
}