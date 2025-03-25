#include<stdio.h>
#include<ctype.h>
#define max 15
int top = -1;
char A[max];
void push(char c){
    A[++top] = c;
}
char pop(){
    if(top == -1)
        return -1;
    else
        return A[top--];
}
int prcd(char c){
    if(c == '(')
        return 0;
    else if(c == '+' || c == '-')
        return 1;
    else if(c == '*' || c == '/')
        return 2;
    else if(c == '^')
        return 3;
}
void infix_to_postfix(char infix[], char postfix[]){
    int i=0, j=0;
    char temp, x;
    while(infix[i] != '\0'){
        temp = infix[i];
        if(isalnum(temp)){
            postfix[j++] = temp;
        }
        else if(temp == '('){
            push(temp);
        }
        else if(temp == ')'){
            while((x=pop()) != '('){
                postfix[j++] = x;
            }
        }
        else{
            if(prcd(A[top]) == prcd(temp)){
                if(temp == '^'){
                    push(temp);
                }
                else{
                    while(prcd(A[top]) == prcd(temp)){
                        postfix[j++] = pop();
                    }
                    push(temp);
                }
            }
            else{
                while(prcd(A[top]) >= prcd(temp)){
                    postfix[j++] = pop();
                }
                push(temp);
            }
        }
        i++;
    }
    while(top != -1){
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}
int main(){
    char infix[max], postfix[max];
    printf("Enter infix expression :\n");
    scanf("%s",infix);
    printf("The infix expression is %s\n",infix);
    infix_to_postfix(infix, postfix);
    printf("The postfix expressoion is %s\n",postfix);
    return 0;
}