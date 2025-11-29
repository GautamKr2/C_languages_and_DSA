#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define max 20
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
    if(c == ')')
        return 0;
    else if(c == '+' || c == '-')
        return 1;
    else if(c == '*' || c == '/')
        return 2;
    else if(c == '^')
        return 3;
}
void infix_to_prefix(char infix[], char prefix[]){
    strrev(infix);
    char temp, x;
    int i=0, j=0;
    while(infix[i] != '\0'){
        temp = infix[i];
        if(isalnum(temp)){
            prefix[j++] = temp;
        }
        else if(temp == ')'){
            push(temp);
        }
        else if(temp == '('){
            while((x=pop()) != ')'){
                prefix[j++] = x;
            }
        }
        else{
            if(prcd(A[top]) == prcd(temp)){
                if(temp == '^'){
                    while(prcd(A[top]) == prcd(temp)){
                        prefix[j++] = pop();
                    }
                }
                push(temp);
            }
            else{
                while(prcd(A[top]) > prcd(temp)){
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
    printf("Enter infix expression :\n");
    scanf("%s",infix);
    printf("The infix expression is %s\n",infix);
    infix_to_prefix(infix, prefix);
    printf("The prefix expression is %s\n",prefix);
    return 0;
}