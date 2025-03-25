/*#include <stdio.h>

typedef struct student_data {
    char name[20];
    int rollNo;
    float cgpa;
} stda ;

void printInfo(stda inf);

int main () {
    stda s1 = {"gautam", 331, 7.4};
    stda s2 = {"anish", 334, 7.2};
    stda s3 = {"ankita", 329, 7.1};

    printInfo(s1);
    printInfo(s2);
    printInfo(s3);

    return 0;
}

void printInfo(stda inf){
    printf("Student's information is : %s, %d, %.2f\n",inf.name, inf.rollNo, inf.cgpa);
}*/

#include<stdio.h>
typedef struct complexNumber {
    int real;
    int img;
} cmp ;
int main (){
    cmp n;
    struct complexNumber *ptr = &n;
    printf("Enter real part : ");
    scanf("%d",&n.real);
    printf("Enter img part : ");
    scanf("%d",&n.img);

    printf("Real part of complex number is %d\n",(*ptr).real);
    printf("Imaginary part of complex number is %d\n",ptr->img);

    return 0;
}