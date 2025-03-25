/*#include<stdio.h>
int sum(int a, int b);
int main(){
    int a,b;
    printf("Enter a :");
    scanf("%d",&a);
    printf("Enter b :");
    scanf("%d",&b);

    int s=sum(a,b);
    printf("Sum is : %d",s);
    return 0;
}
int sum(int a, int b){
    return a+b;
}*/

/*#include <stdio.h>

int fib(int n);
int main() {
    int n ;

    printf("Enter n : ");
    scanf("%d",&n);
    printf ("%dth term of fibonacci sequence is %d \n",n , fib(n));
    return 0 ;
}
int fib(int n){
    if (n==0){
        return 0;
    }
    if (n==1){
        return 1;
    }
    int fibNm1 = fib(n - 1);
    int fibNm2 = fib(n - 2);
    int fibN = fibNm1 + fibNm2 ;
    return fibN ;
}*/


/*#include<stdio.h>
void printNum(int a);
int main(){
    int n;
    printf("Enter n: ");
    scanf("%d",&n);
    printNum(n);
    return 0;
}
void printNum(int a){
    if(a==0)
        return;
    else{
        printf("%d\n",a);
        printNum(a-1);
        printf("%d\n",a);
    }
}*/


/*#include<stdio.h>
int fact(int a);
int main(){
    int n;
    printf("Enter n: ");
    scanf("%d",&n);
    int x = fact(n);
    printf("Factorial of n is: %d",x);
    return 0;
}
int fact(int a){
    int fac;
    if(a == 1)
        return 1;
    else{
        fac = a * fact(a-1);
    }
    return fac;
}*/


/*#include<stdio.h>
int fib(int n){
    if(n == 0)
        return 0;
    if(n==1 || n==2)
        return 1;
    else
        return (fib(n-1) + fib(n-2));
}
int main(){
    int n;
    printf("Enter n: ");
    scanf("%d",&n);
    for(int i=0; i<=n; i++){
        printf("%d\t",fib(n));
    }
    return 0;
}*/



#include<stdio.h>
void value(int *p){
    int b;
    printf("Enter b: ");
    scanf("%d",&b);
    *p = b;
    printf("%d\n",*p);
}
int main(){
    int a = 5;
    int *p = &a;

    printf("%d\n",a);
    value(p);
    return 0;
}