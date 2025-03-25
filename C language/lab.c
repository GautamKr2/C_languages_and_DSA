/*#include<stdio.h>
#include<math.h>
int main(){
    long long int n,m,o,re=0;
    printf("Enter number : ");
    scanf("%lld",&n);
    m = n;
    o = m;
    int sum = 0, prod = 1;
    int l = n%10;
    printf("Last digit of given number is : %d\n",l);
    int r = log10(n);
    int f = n / pow(10,r);
    printf("First digit of given number is : %d\n\n",f);
    
    printf("Sum of 1st and last digit of given number is : %d\n\n",f+l);

    printf("Before swapping \nFirst number : %d & Last number : %d\n",f,l);
    f = f + l;
    l = f - l;
    f = f - l;
    printf("After swapping \nFirst number : %d & Last number : %d\n\n",f,l);

    for(int i=1; n!=0; i++){
        int r = n%10;
        sum = sum + r;
        prod = prod * r;
        n = n/10;
    }
    printf("Sum of all digits of given number is : %d\n\n",sum);
    printf("Product of all digits of given number is : %d\n\n",prod);

    for(int i=1; m!=0; i++){
        int r = m%10;
        re = (re * 10) + r;
        m = m/10;
    }
    printf("Reverse of given number is : %lld\n\n",re);

    if(re == o){
        printf("Entered number is a palindrome number.");
    }
    else {
        printf("Entered number is not a palindrome number.");
    }
    return 0;
}*/


//To print all prime factors of a given number
/*#include<stdio.h>
int main(){
    int n,isPrime;
    printf("Enter number : ");
    scanf("%d",&n);
    printf("All prime factor of given number are :\n");
    for(int i=2; i<=n; i++){
        if(n%i == 0){
            isPrime = 1;
            for(int j=2; j<=i/2; j++){
                if(i%j == 0){
                    isPrime = 0;
                }
            }
            if(isPrime)
                printf("%d   ",i);
        }
    }
    return 0;
}*/


//To print total strong number between 1 to n
//Def : A strong number is a positive integer whose sum of factorials of its digits equals the number itself.
/*#include<stdio.h>
int factorial(int x){
    int fact = 1;
    for(int i=1; i<=x; i++){
        fact = fact * i;
    }
    return fact;
}
int main(){
    int n,m,fact,sum=0;
    printf("Enter number : ");
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        m = i;
        while(m!=0){
            int r = m%10;
            fact = factorial(r);
            sum = sum + fact;
            m = m/10;
        }
        if(sum == i){
            printf("%d  ",i);
        }
        sum = 0;
    }
    return 0;
}*/

/*
#include<stdio.h>
int fact(int n){
    int f=1;
    for(int i=1; i<=n; i++){
        f *= i;
    }
    return f;
}
int main(){
    int n, m, sum=0;
    printf("Enter n: ");
    scanf("%d",&n);
    
    m = n;
    while(m != 0){
        int r = m%10;
        sum += fact(r);
        m /= 10;
    }
    if(sum == n){
        printf("Strong number");
    }
    else
        printf("Not a strong number");
    return 0;
}
*/
