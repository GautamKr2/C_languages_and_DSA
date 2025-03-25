/*#include <stdio.h>
int main(){
    for (int i=1; i<=10; i++){
    if (i== 6){
        break;
        }
        printf("%d\n",i);
    }
    printf("End");
    return 0;
}*/

//For print odd number
/*#include<stdio.h>
int main(){
    for (int i=1; i<=10; i++){ 
        if (i%2 == 0){
            continue;
        }
        printf("%d\t",i);
    }
    return 0;
}*/

//For calculate factorial of number entered by user
/*#include<stdio.h>
int main(){
    int n;
    printf("Enter n : ");
    scanf("%d",&n);

    int fact=1;
    for (int i=1; i<=n; i++){
        fact = fact * i;
    }
    printf("%d",fact);
    return 0;
}*/

//For calculate sum of n natural number
/*#include<stdio.h>
int main(){
    int n;
    printf("Enter number : ");
    scanf("%d",&n);

    int sum = 0;
    for (int i=1; i<=n; i++){
        sum = sum + i;
    }

    //int i = 1;
    // while (i<=n){
    //     sum = sum + i;
    // }

    // do {
    //     sum = sum + i;
    // } while(i<=n);
    printf("%d",sum);
    return 0;
}*/

/*#include"stdio.h"
int main(){
    int i, sq, sum = 0;
    for(i=1; i<=10; i++){
        if(i%2 == 0){
            if(i%6 != 0){
                printf("%d\t",i);
                sq = i*i;
                sum = sum +sq;
            }
        }
    }
    printf("\n%d\n",sum);
    return 0;
}*/


/*#include<stdio.h>
#include<math.h>
int main(){
    int num, n=0;
    printf("Enter number : ");
    scanf("%d",&num);
    int digit = (int) log10(num);
    while(num != 0){
        int r = num % 10;
        n = n*10+r;
        num /= 10;
    }
    digit = digit - (int) log10(n);
    do{
        switch(n % 10){
            case 0 : printf("Zero  ");
            break;
            case 1 : printf("One  ");
            break;
            case 2 : printf("Two  ");
            break;
            case 3 : printf("Three  ");
            break;
            case 4 : printf("Four  ");
            break;
            case 5 : printf("Five  ");
            break;
            case 6 : printf("Six  ");
            break;
            case 7 : printf("Seven  ");
            break;
            case 8 : printf("Eight  ");
            break;
            case 9 : printf("Nine  ");
            break;
        }
        n /= 10;
    }while(n != 0);
    while(digit > 0){
        printf("Zero  ");
        digit--;
    }
    return 0;
}*/


//LCM
/*#include<stdio.h>
int main(){
    int m,n,lcm;
    printf("Enter both numbers: ");
    scanf("%d %d",&m,&n);
    int g = m>n ? m : n;
    int i = g;
    while(1){
        if(i%m==0 && i%n==0){
            lcm = i;
            break;
        }
        else{
            i = i + g;
        }
    }
    printf("LCM of both numbers is: %d",lcm);
    return 0;
}*/



//HCF
/*#include<stdio.h>
int main(){
    int m,n,hcf=1;
    printf("Enter both numbers: ");
    scanf("%d %d",&m,&n);
    int min = (m<n) ? m : n;
    for(int i=1; i<=min; i++){
        if(m%i==0 && n%i==0){
            hcf = i;
        }
    }
    printf("HCF of both numbers is: %d",hcf);
    return 0;
}*/

//Checking of Palindrome number
/*#include<stdio.h>
int main(){
    int num,n,rev;
    printf("Enter number: ");
    scanf("%d",&num);
    n = num;
    while(n!=0){
        int r = n % 10;
        rev = rev*10 + r;
        n /= 10;
    }
    if(rev == num){
        printf("%d is a palindrome number.",num);
    }
    else{
        printf("%d is not a palindrome number.",num);
    }
    return 0;
}*/


//Checking of Armstrong number
/*#include<stdio.h>
#include<math.h>
int main(){
    int num,n,sum=0;
    printf("Enter number: ");
    scanf("%d",&num);
    int digit = log10(num) + 1;
    n = num;
    while(n > 0){
        int r = n%10;
        sum += round(pow(r,digit));
        n /= 10;
    }
    if(sum == num){
        printf("%d is an Armstrong number.",num);
    }
    else{
        printf("%d is not an Armstrong number.",num);
    }
    return 0;
}*/


//Checking of Perfect number
/*#include<stdio.h>
int main(){
    int num,sum=0;
    printf("Enter number: ");
    scanf("%d",&num);
    for(int i=1; i<=num/2; i++){
        if(num%i == 0){
            sum += i;
        }
    }
    if(sum == num){
        printf("%d is a perfect number.",num);
    }
    else{
        printf("%d is not a perfect number.",num);
    }
    return 0;
}*/



// Strong number
/*#include<stdio.h>
int fact(int x){
    int f = 1;
    for(int i=1; i<=x; i++){
        f *= i;
    }
    return f;
}
int main(){
    int num,n,sum=0;
    printf("Enter number: ");
    scanf("%d",&num);
    n = num;
    while(n>0){
        int r = n%10;
        sum += fact(r);
        n /= 10;
    }
    if(sum == num)
        printf("%d is an strong number.",num);
    else
        printf("%d is not an strong number.",num);
    return 0;
}*/



//Pascals triangle
/*#include<stdio.h>
int func1(int a){
    int m = 1;
    for(int i=2; i<=a; i++){
        m *= i;
    }
    return m;
}
int func2(int x, int y){
    int c = func1(x)/(func1(y)*func1(x-y));
    return c;
}
int main(){
    int n;
    printf("Enter n: ");
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        for(int j=1; j<=n-i; j++){
            printf(" ");
        }
        for(int k=0; k<=i; k++){
            int z = func2(i,k);
            printf("%d ",z);
        }
        printf("\n");
    }
    return 0;
}*/