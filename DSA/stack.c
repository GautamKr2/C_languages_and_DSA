/* // Implementation using array
#include<stdio.h>
#include<stdlib.h>
#define N 10
int stack[N];
int top = -1;
void Push();
void Pop();
void Peek();
void Disply();

int main(){
    int choice;
    do{
        printf("Enter choice :\nPush(1), Pop(2), Peek(3), Disply(4), Exit(5) : ");
        scanf("%d",&choice);
        switch(choice){
            case 1 : Push();
                break;
            case 2 : Pop();
                break;
            case 3 : Peek();
                break;
            case 4 : Disply();
                break;
            case 5 : exit(0);
                break;
            default : printf("Invalid  input !!\n");
        }
    }while(choice != 0);
    return 0;
}

void Push(){
    int x;
    printf("Enter data : ");
    scanf("%d",&x);
    if(top == N-1)
        printf("Overflow condition !!\n");
    else{
        top++;
        stack[top] = x;
    }
}
void Pop(){
    int item;
    if(top == -1)
        printf("Underflow condition !!\n");
    else{
        item = stack[top];
        top--;
        printf("Popped item is %d.\n",item);
    }
}
void Peek(){
    if(top == -1)
        printf("Underflow condition !");
    else
        printf("Topmost element of stack is %d.\n",stack[top]);
}
void Disply(){
    int i;
    printf("Elements of stack are :\n");
    for(i=top; i>=0; i--)
        printf("%d\t",stack[i]);
    printf("\n");
} */



/* // Implementation of stack using linked list
#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int data;
    struct node *link;
}NODE;
NODE *new_node, *top = 0, *temp;
void Push();
void Pop();
void Peek();
void Disply();

int main(){
    int choice;
    do{
        printf("Enter choice :\nPush(1), Pop(2), Peek(3), Disply(4), Exit(5) : ");
        scanf("%d",&choice);
        switch(choice){
            case 1 : Push();
                break;
            case 2 : Pop();
                break;
            case 3 : Peek();
                break;
            case 4 : Disply();
                break;
            case 5 : exit(0);
                break;
            default : printf("Invalid  input !!\n");
        }
    }while(choice != 0);
    return 0;
}

void Push(){
    new_node = (NODE*)malloc(sizeof(NODE));
    printf("Enter data : ");
    scanf("%d",&new_node -> data);
    new_node -> link = top;
    top = new_node;
}
void Disply(){
    if(top == 0)
        printf("Stack is empty !!");
    else{
        temp = top;
        while(temp != 0){
            printf("%d\t",temp -> data);
            temp = temp -> link;
        }
    }
    printf("\n");
}
void Pop(){
    temp = top;
    top = top -> link;
    if(top == 0)
        printf("Stack is empty !!\n");
    else{
        printf("Popped element is %d.\n",temp -> data);
        free(temp);
    }
}
void Peek(){
    if(top == 0)
        printf("Stack is empty !!\n");
    else
        printf("Toopmost element of stack is %d.\n",top -> data);
} */



/*#include<stdio.h>
#define max 100
int top=-1, a[max];
void push(char x)
{
    a[++top]=x;
}
char pop()
{ if(top==-1)
return -1;
else
return a[top--];
}

int prcd(char c)
{   if(c=='(')
    return 0;
    else if(c=='+'||c=='-')
    return 1;
    else if(c=='*'||c=='/')
    return 2;
}
int infixtopostfix(char infix[max],char postfix[max])
{
    char temp,x;
    int i=0,j=0;
    while(infix[i]!='\0')
    {
        temp=infix[i];
        if(isalnum(temp))
        {
            postfix[j++]=temp;
        }
        else if(temp=='(')
         push(temp);
        else if(temp==')')
            {
         while((x=pop())!='(')
         {
          postfix[j++]=x;
           }
          }
        else
        {  while(prcd(a[top])>=prcd(temp))
            {postfix[j++]=pop();}
                push(temp);
        }
        i++;
    }
    while(top!= -1)
    postfix[j++]=pop();
    postfix[j]='\0';
}
main()
{
    char infix[max],postfix[max];
    printf("Enter the infix expression\n");
    gets(infix);
    printf("The infix expression is %s\n",infix);
    infixtopostfix(infix, postfix);
    printf("The postfix expression is %s\n",postfix);

}*/


#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define max 50
typedef struct node{
    char ch;
    struct node *link;
}NODE;
NODE *stack, *top = NULL;
void push(char c){
    stack = (NODE*)malloc(sizeof(NODE));
    stack -> ch = c;
    stack -> link = top;
    top = stack;
}
char pop(){
    if(top == NULL)
        return -1;
    else
        return top -> ch;
    NODE *temp = top;
    top = top -> link;
    free(temp);
}
int prcd(char c){
    if(c == '(')
        return 0;
    else if(c == '+' || c == '-')
        return 1;
    else if(c == '*' || c =='/')
        return 2;
    else if(c == '^')
        return 3;
}
void infixtopostfix(char infix[max], char postfix[max]){
    char ch, x;
    int i = 0, j = 0;
    while(infix[i] != '\0'){
        ch = infix[i];
        if(isalnum(ch)){
            postfix[j++] = ch;
        }
        else if(ch == '(')
            push(ch);
        else if(ch == ')'){
            while((x = pop()) != '('){
                postfix[j++] = x;
            }
        }
        else{
            while(prcd(top -> ch) >= prcd(ch)){
                postfix[j++] = pop();
            }
            push(ch);
        }
        i++;
    }
    while(top != NULL){
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    printf("Postfix expression is %s\n",postfix);
}
int main(){
    char infix[max], postfix[max];
    printf("Enter infix exp : ");
    scanf("%s",infix);
    // fgets(infix, max, stdin);
    printf("Your infix expression is %s\n",infix);
    char y = infix[1];
    printf("%c",y);
    infixtopostfix(infix, postfix);
    // printf("Postfix expression is %s\n",postfix);
    // char y = infix[0];
    // printf("%c",y);
    return 0;
}