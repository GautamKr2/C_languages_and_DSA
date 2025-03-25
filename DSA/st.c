// Stack using array
/*#include<stdio.h>
#include<stdlib.h>
#define max 5
int A[max];
int top = -1;
void push(){
    int x;
    if(top == max-1)
        printf("Overflow condition !");
    else{
        printf("Enter data : ");
        scanf("%d", &x);
        A[++top] = x;
    }
}
void pop(){
    if(top == -1)
        printf("Stack is empty !");
    else
        top--;
}
void top_p(){
    printf("The topmost element is %d\n",A[top]);
}
void display(){
    for(int i=top; i>=0; i--){
        printf("%d\t", A[i]);
    }
    printf("\n");
}

int main(){
    int ch;
    while(1){
        printf("Enter 1 for push, 2 for pop, 3 for top, 4 for display, 5 for exit\nChoose any option : ");
        scanf("%d", &ch);
        switch(ch){
            case 1 : push(); break;
            case 2 : pop(); break;
            case 3 : top_p(); break;
            case 4 : display(); break;
            case 5 : exit(0);
        }
    }
    return 0;
}*/


// Stack using linked list
/*#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *link;
}NODE;
NODE *top = NULL, *temp;

void push(){
    int x;
    printf("Enter data which you want to push : ");
    scanf("%d", &x);
    temp = (NODE*)malloc(sizeof(NODE));
    temp -> data = x;
    temp -> link = top;
    top = temp;
}
void pop(){
    if(top == NULL)
        printf("List is empty !");
    else{
        temp = top;
        top = top -> link;
        free(temp);
    }
}
void top_p(){
    if(top == NULL)
        printf("List is empty !");
    else
        printf("The topmost element of list is %d\n",top -> data);
}
void display(){
    temp = top;
    while(temp != NULL){
        printf("%d\t", temp -> data);
        temp = temp -> link;
    }
    printf("\n");
}

int main(){
    int ch;
    while(1){
        printf("Enter 1 for push, 2 for pop, 3 for top, 4 for display, 5 for exit\nChoose any option : ");
        scanf("%d", &ch);
        switch(ch){
            case 1 : push(); break;
            case 2 : pop(); break;
            case 3 : top_p(); break;
            case 4 : display(); break;
            case 5 : exit(0);
        }
    }
    return 0;
}*/



// Reverse of string using stack
/*#include<stdio.h>
#define max 10
char A[max];
int top = -1;
void push(char c){
    A[++top] = c;
}
void pop(){
    while(top != -1){
        printf("%c",A[top--]);
    }
}
int main(){
    char str[max];
    printf("Enter your string : ");
    scanf("%s", str);
    int i = 0;
    while(str[i] != '\0'){
        push(str[i]);
        i++;
    }
    // For print reverse of string
    pop();
    return 0;
}*/




// Infix to prefix
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define max 20
int top = -1, A[max];
void push(char x){
    A[++top] = x;
}
char pop(){
    if(top == -1)
        return -1;
    else
        return A[top--];
}

int prcd(char c){
    if(c == ')')
        return 0;
    else if(c == '+' || c == '-')
        return 1;
    else if(c == '*' || c == '/')
        return 2;
}
void infix_to_prefix(char infix[max], char prefix[max]){
    char temp, x;
    int i=0, j=0;
    strrev(infix);
    while(infix[i] != '\0'){
        temp = infix[i];
        if(isalnum(temp)){
            prefix[j++] = temp;
        }
        else if(temp == ')')
            push(temp);
        else if(temp == '('){
            while((x = pop()) != ')'){
                prefix[j++] = x;
            }
        }
        else{
            if(prcd(A[top]) == prcd(temp)){
                push(temp);
            }
            else{
                while(prcd(A[top]) >= prcd(temp)){
                    prefix[j++] = pop();
                }
                push(temp);
            }
        }
        i++;
    }
    while(top != -1){
        prefix[j++] = pop();
    }
    prefix[j] = '\0';
    strrev(prefix);
}
int main(){
    char infix[max], prefix[max];
    printf("Enter the infix expression\n");
    gets(infix);
    printf("The infix expression is %s\n", infix);
    infix_to_prefix(infix, prefix);
    printf("The prefix expression is %s\n", prefix);
    return 0;
}