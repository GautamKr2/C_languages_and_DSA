#include<stdio.h>
#include<stdlib.h>
#define max 20
int Arr[max];
int x;
void create(){
    printf("No of elements you want to enter : ");
    scanf("%d", &x);
    printf("Enter elements :\n");
    for(int i=0; i<x; i++){
        scanf("%d", &Arr[i]);
    }
}
void display(){
    for(int i=0; i<x; i++){
        printf("%d\t", Arr[i]);
    }
    printf("\n");
}
void insert_at_start(){
    int y;
    printf("Enter value which you want to insert at start : ");
    scanf("%d",&y);
    for(int i=x-1; i>=0; i--){
        Arr[i+1] = Arr[i];
    }
    Arr[0] = y;
    x++;
}
void insert_at_end(){
    int y;
    printf("Enter value which you want to insert at end : ");
    scanf("%d",&y);
    Arr[x++] = y;
}
void insert(){
    char c;
    printf("Press a for insert at start, b for insert at end : ");
    scanf(" %c", &c);
    switch(c){
        case 'a' : insert_at_start(); break;
        case 'b' : insert_at_end(); break;
    }
}

void delete_from_start(){
    for(int i=0; i<x; i++){
        Arr[i] = Arr[i+1];
    }
    x--;
}
void delete_from_end(){
    Arr[(x-- - 1)] = Arr[x];
}
void delete(){
    char c;
    printf("Press a for delete from start, b for delete from end : ");
    scanf(" %c", &c);
    switch(c){
        case 'a' : delete_from_start(); break;
        case 'b' : delete_from_end(); break;
    }
}
void modify(){
    int pos, y;
    printf("Enter position where you want to modify : ");
    scanf("%d", &pos);
    printf("Enter new element : ");
    scanf("%d", &y);
    Arr[pos-1] = y;
}

int main(){
    int ch;
    while(1){
        printf("Enter 1 for create, 2 for insert, 3 for delete, 4 for display, 5 for modify, 6 for exit\nChoose any option : ");
        scanf("%d", &ch);
        switch(ch){
            case 1 : create(); break;
            case 2 : insert(); break;
            case 3 : delete(); break;
            case 4 : display(); break;
            case 5 : modify(); break;
            case 6 : exit(0);
        }
    }
    return 0;
}