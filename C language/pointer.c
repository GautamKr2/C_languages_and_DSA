/*#include<stdio.h>
int main(){
    int age = 19;
    int *ptr = &age;
    int _age = *ptr;

    //Printing of value
    printf("%d\t%d\t%d\t%d",age,_age,*ptr,*(&age));
    return 0;
}*/

/*#include<stdio.h>
int main(){
    int age = 19;
    int *ptr = &age;

    //Printing of address
    printf("%p\n",&age);
    printf("%u\n",&age);
    printf("%u\n",ptr);
    printf("%u\n",&ptr);
    return 0;
}*/

/*#include<stdio.h>
int main(){
    float price;
    printf("Enter price : ");
    scanf("%f",&price);
    float *ptr = &price;
    float **pptr = &ptr;

    //Value
    printf("%f\t%f\t%f\n",price,*ptr,**pptr);

    //Address
    printf("%u\n%u\n%u\n%u\n%u\n%u",&price,ptr,*pptr,&ptr,pptr,&pptr);
    return 0;
}*/

/*#include<stdio.h>
int main(){
    void square(int n);

    void _square(int *n);

    int n;
    printf("Enter number : ");
    scanf("%d",&n);

    //Call by value
    square(n);
    printf("number = %d\n",n);

    //Call by reference
    _square(&n);
    printf("number = %d\n",n);
    return 0;
}
void square(int n){
    n = n*n;
    printf("square = %d\n",n);
}

void _square(int *n){
    *n = (*n) * (*n);
    printf("square = %d\n",n);
    printf("square = %d\n",*n);
}*/

/*#include<stdio.h>
int main(){
    void swap(int a, int b);

    void _swap(int *a, int *b);

    int a = 4, b = 7;
    //Call by value
    swap(a,b);
    printf("%d\t%d\n\n",a,b);

    //Call by reference
    _swap(&a,&b);
    printf("%d\t%d\n",a,b);
    return 0;
}
void swap(int a, int b){
    int x = a;
    a = b;
    b = x;
    printf("%d\t%d\n",a,b);
}

void _swap(int *a, int *b){
    int y = *a;
    *a = *b;
    *b = y;
    printf("%d\t%d\n",*a,*b);
}*/

/*#include<stdio.h>
void printAddress(int n);
void _printAddress(int *n);

int main(){
    int n = 6;
    //Call by value
    printAddress(n);
    printf("%p\n",&n);

    //Call by reference
    _printAddress(&n);
    printf("%p\n",&n);
    return 0;
}
void printAddress(int n){
    printf("%p\n",&n);
}
void _printAddress(int *n){
  printf("%p\n",n);
}*/

/*#include<stdio.h>
void doWork(int a, int b, int *x, int *y, int *z);
int main(){
    int a = 13,b = 7, sum, prod, avg;
    doWork(a,b,&sum, &prod, &avg);
    printf("Sum is : %d\n product is : %d\n Average is : %d\n",sum, prod, avg);
    return 0;
}
void doWork(int a, int b, int *x, int *y, int *z){
    *x = a + b;
    *y = a * b;
    *z = (a+b)/2;
}*/


