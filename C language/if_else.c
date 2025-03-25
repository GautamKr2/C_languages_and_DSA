/*#include<stdio.h>
int main(){
    //Average age of students of entered class
    int x;
    printf ("Enter class : ");
    scanf("%d ",&x);

    switch(x){
        case 1 : printf("Average age of class 1 is 7 years.");
        break;
        case 2 : printf("Average age of class 2 is 8 years.");
        break;
        case 3 : printf("Average age of class 3 is 9 years.");
        break;
        case 4 : printf("Average age of class 4 is 10 years.");
        break;
        case 5 : printf("Average age of class 5 is 11 years.");    
        break;
        case 6 : printf("Average age of class 6 is 12 years.");
        break;
        case 7 : printf("Average age of class 7 is 13 years.");
        break;
        case 8 : printf("Average age of class 8 is 14 years.");
        break;
        case 9 : printf("Average age of class 9 is 15 years.");
        break;
        case 10 : printf("Average age of class 10 is 16 years.");
        break;

        default : printf("Not valid ");
        }
    return 0;
}*/


#include<stdio.h>
int main(){
    int i;
    printf("Enter 1 if you are a member or enter 2 if you are a customer :");
    scanf("%d",&i);

    float price;
    if (i == 1){
        printf("Enter price : ");
        scanf("%f",&price);
        if (price > 100){
            printf("You will get 10 percent discount.\n");
            printf("Your final price is %f.",price - (price*0.1));
        }
        else {
            printf("final price is %f",price);
        }
    }
    else if(i == 2){
        printf("Enter price : ");
        scanf("%f",&price);
        if (price > 150 ){
            printf("You will get 10 percent discount.\n");
            printf("Your final price is %f.",price - (price*0.1));
        }
        else {
             printf("final price is %f",price);
        }
    }
    else {
        printf("You are not a customer.");
    }
    return 0;
}

/*#include<stdio.h>
int main(){
    int year;
    printf("Enter year :");
    scanf("%d",&year);
    if (year%4 == 0){
        printf("%d is a leap year. ",year);
    }
    else {
        printf ("%d is not a leap year.",year);
    }
    return 0;
}*/


/*#include<stdio.h>
int main(){
    int a,b,c,d,e;
    printf("Enter a :");
    scanf("%d",&a);
    printf("Enter b :");
    scanf("%d",&b);
    printf("Enter c :");
    scanf("%d",&c);
    printf("Enter d :");
    scanf("%d",&d);
    printf("Enter e :");
    scanf("%d",&e);

    if (a>b && a>c && a>d && a>e){
        printf("%d is the greatest number among them.",a);
    }
    else if (b>a && b>c && b>d && b>e){
        printf("%d is the greatest number among them.",b);
    }
    else if (c>a && c>b && c>d && c>e){
        printf("%d is the greatest number among them.",c);
    }
    else if (d>a && d>b && d>c && d>e){
        printf("%d is the greatest number among them.",d);
    }
    else if (e>b && e>c && e>d && e>a){
        printf("%d is the greatest number among them.",e);
    }
    else {
        printf("All entered numbers are equal.");
    }
    return 0;
}*/


/*#include<stdio.h>
int main(){
    float marks ;
    printf("Enter percentage marks :");
    scanf("%f",&marks);

    if (marks >= 40 && marks < 50){
        printf("Grade E\n");
    }
    else if (marks >= 50 && marks < 60){
        printf("Grade D\n");
    }
    else if (marks >= 60 && marks < 70){
        printf("Grade C\n");
    }
    else if (marks >= 70 && marks < 80){
        printf("Grade B\n");
    }
    else if (marks >= 80 && marks < 90){
        printf("Grade A\n");
    }
    else if (marks >= 90 && marks < = 100){
        printf("Grade O");
    }
    else {
        printf("Fail\n");
    }
    return 0 ;
}*/


/*#include<stdio.h>
int main(){
    char ch;
    printf("Enter character: ");
    scanf("%c",&ch);

    if (ch >= 'A' && ch <= 'Z'){
        printf("Entered character is an upper case.");
    }
    else if (ch >= 'a' && ch <= 'z'){
        printf("Entered character is a lower case.");
    }
    else {
        printf("Not an english letter.");
    }
    return 0;
}*/

/*#include<stdio.h>
#include<math.h>
void main(){
    int a = 2 , b = 4;
    int R = pow(a,b);
    printf("%d",R);
    
}*/