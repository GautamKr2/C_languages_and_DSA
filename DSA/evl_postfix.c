#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define max 20
char Stack[max];
int top = -1;
void push(char c){
    Stack[++top] = c;
}
char pop(){
    if(top == -1)
        return -1;
    else
        return Stack[top--];
}
int prcd(char x){
    if(x == '(')
        return 0;
    else if(x == '+' || x == '-')
        return 1;
    else if(x == '*' || x == '/')
        return 2;
}
void infix_to_postfix(char Infix[], char Postfix[]){
    char temp, x;
    int i = 0, j = 0;
    while(Infix[i] != '\0'){
        temp = Infix[i];
        if(isalnum(temp)){
            Postfix[j++] = temp;
        }
        else if(temp == '('){
            push(temp);
        }
        else if(temp == ')'){
            while((x = pop()) != '('){
                Postfix[j++] = x;
            }
        }
        else{
            while(prcd(Stack[top]) >= prcd(temp)){
                    Postfix[j++] = pop();
            }
            push(temp);
        }
        i++;
    }
    while(top != -1){
        Postfix[j++] = pop();
    }
    Postfix[j] = '\0';
}
int Evl_of_postfix(char Postfix[]){
    int evl_val=0, i=0, op1, op2;
    char temp;
    while(Postfix[i] != '\0'){
        temp = Postfix[i];
        if(isdigit(temp)){
            push(temp - '0');
        }
        else{
            op2 = pop();
            op1 = pop();
            switch(temp){
                case '+' : evl_val = op1 + op2; break;
                case '-' : evl_val = op1 - op2; break;
                case '*' : evl_val = op1 * op2; break;
                case '/' : if(op2 == 0){
                    printf("Error : Division by zero !\n");
                    return -1;
                }
                else{
                    evl_val = op1 / op2;
                } break;
                default : printf("Invalid operator !\n");
            }
            push(evl_val);
        }
        i++;
    }
    return pop();
}
int main(){
    char Infix[max], Postfix[max];
    printf("Enter infix expression :\n");
    gets(Infix);
    printf("Your infix expression is : %s\n",Infix);
    infix_to_postfix(Infix, Postfix);
    printf("Your postfix expression is : %s\n",Postfix);
    int result = Evl_of_postfix(Postfix);
    printf("Evaluated value of given postfix expression is %d\n",result);
    return 0;
}