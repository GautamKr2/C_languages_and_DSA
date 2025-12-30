#include <stdio.h>
#include <stdlib.h>

int mutex=1, full=0, empty=3, x=0;

int wait(int s) {
    return --s;
}
int signal(int s) {
    return ++s;
}

void producer() {
    mutex = wait(mutex);
    full = signal(full);
    empty = wait(empty);
    printf("Producer produces %d process\n", ++x);
    mutex = signal(mutex);
}
void consumer() {
    mutex = wait(mutex);
    empty = signal(empty);
    full = wait(full);
    printf("Consumer consumes process %d\n", x--);
    mutex = signal(mutex);
}

int main() {
    int ch;
    while(1) {
        printf("Enter 1 for prodece, 2 for consume, 3 for exit: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                if(mutex==1 && empty!=0)
                    producer();
                else {
                    if(mutex!=1)
                        printf("Consumer is in critical section !");
                    else
                        printf("Buffer is full !");
                }
                break;
            case 2:
                if(mutex==1 && full!=0)
                    consumer();
                else {
                    if(mutex!=1)
                        printf("Producer is in critical section !");
                    else
                        printf("Buffer is empty !");
                }
                break;
            case 3: exit(0);
            default: printf("Invalid input !");
        }
    }
    return 0;
}