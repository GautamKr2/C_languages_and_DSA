#include<stdio.h>
#include<string.h>
#include<ctype.h> // This is for isdigit and isalnum function.
#include<math.h> // This is for power function.
#define max 50
int Stack[max];
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
int prcd(char c){
    if(c == ')')
        return 0;
    else if(c == '+' || c == '-')
        return 1;
    else if(c == '*' || c == '/')
        return 2;
}
void infix_to_prefix(char Infix[], char Prefix[]){
    char x, temp;
    int i=0, j=0;
    strrev(Infix);
    while(Infix[i] != '\0'){
        temp = Infix[i];
        if(isalnum(temp)){
            Prefix[j++] = temp;
        }
        else if(temp == ')'){
            push(temp);
        }
        else if(temp == '('){
            while((x=pop()) != ')'){
                Prefix[j++] = x;
            }
        }
        else{
            if(prcd(Stack[top]) == prcd(temp)){
                push(temp);
            }
            else{
                while(prcd(Stack[top]) > prcd(temp)){
                    Prefix[j++] = pop();
                }
                push(temp);
            }
        }
        i++;
    }
    while(top != -1){
        Prefix[j++] = pop();
    }
    Prefix[j] = '\0';
    strrev(Prefix);
}
int evl_of_prefix(char Prefix[]){
    strrev(Prefix);
    int evl_val=0, i=0, op1, op2;
    char temp;
    while(Prefix[i] != '\0'){
        temp = Prefix[i];
        // if(isdigit(temp)){
        //     push(temp - '0');
        // }
        if(isdigit(temp)){
            int x = 0;
            while((temp=Prefix[i]) != ' '){
                x = (x*10) + (temp-'0');
                i++;
            }
            push(x);
        }
        else if(temp == ' '){
            i++;
            continue;
        }
        else{
            op1 = pop();
            op2 = pop();
            switch(temp){
                case '+' : evl_val = op1 + op2; break;
                case '-' : evl_val = op1 - op2; break;
                case '*' : evl_val = op1 * op2; break;
                case '/' : if(op2 == 0){
                    printf("Error : Division by zero !");
                    return -1;
                }
                else{
                    evl_val = op1 / op2;
                } break;
                case '^' : evl_val = pow(op1, op2);
            }
            push(evl_val);
        }
        i++;
    }
    return pop();
}

int main(){
    char Infix[max], Prefix[max];
    printf("Enter infix expression :\n");
    gets(Prefix);
    // printf("The infix expression is %s\n",Infix);
    // infix_to_prefix(Infix, Prefix);
    // printf("The prefix expressin is %s\n",Prefix);
    int result = evl_of_prefix(Prefix);
    printf("Evaluated value of given expression is %d\n",result);
    return 0;
}
