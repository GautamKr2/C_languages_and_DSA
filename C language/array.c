/*#include<stdio.h>
int main(){
    float price[3];
    printf("Enter price : ");
    scanf("%f %f %f",&price[0],&price[1],&price[2]);

    printf("Final price 1 = %f\n",price[0] + (price[0]*0.18));
    printf("Final price 2 = %f\n",price[1] + (price[1]*0.18));
    printf("Final price 3 = %f\n",price[2] + (price[2]*0.18));
    return 0;
}*/

/*#include<stdio.h>
int main(){
    int age = 19;
    int *ptr = &age;
    printf("ptr = %u\n",ptr);
    ptr++;
    printf("ptr = %u\n",ptr);
    return 0;
}*/

/*#include<stdio.h>
int main(){
    int age = 19;
    int *ptr = &age;

    int _age = 20;
    int *_ptr = &_age;

    printf("%u\n%u\nDifference = %u\n",ptr, _ptr, ptr - _ptr);

    return 0;
}*/

/*#include<stdio.h>
int main(){
    int aadhar[4];
    // Input
    for (int i=0; i<4; i++){
        printf("%dth index : ",i);
        scanf("%d",&aadhar[i]);//&aadhar[i] = (ptr + i)
    }

    //Output
    for (int i=0; i<4; i++){
        printf("%dth index is %d.\n",i,aadhar[i]);//aadhar = *(ptr + i)
    }
    return 0;
}*/

/*#include<stdio.h>
void printNumber(int *x, int n);
int main(){
    int arr[] = {1,2,3,4,5,6,7};
    printNumber(arr,7);
    return 0;
}

void printNumber(int *x, int n){
    for (int i=0; i<n; i++){
        printf("%d\t",x[i]);
    }
}*/

/*#include<stdio.h>
int main(){
    int marks[3][2]; // Marks of 3 students of 2 subjects
    marks[0][0]=85;
    marks[0][1]=76;
    
    marks[1][0]=84;
    marks[1][1]=83;

    marks[2][0]=92;
    marks[2][1]=95;

    printf("%d",marks[1][0]);
    return 0;
}*/

//Count odd number in given number
/*#include<stdio.h>
int countOdd(int arr[], int n);

int main(){
    int arr[] = {2,3,4,5,6,7,9};
    printf("%d",countOdd(arr,7));
    return 0;
}
int countOdd(int arr[], int n){
    int count = 0;
    for (int i=0; i<n; i++){
        if (arr[i] % 2 == 0){  //Odd number
            count++;
        }
    }
    return count;
}*/

/*#include<stdio.h>
void reverse(int arr[], int n);
void printArr(int arr[], int n);
int main(){
    int arr[] = {1,2,3,4,5,6,7};
    reverse(arr,7);
    printArr(arr,7);
    return 0;
}
void reverse(int arr[], int n){
    for (int i=0; i<n/2; i++){
        int firstVal = arr[i];
        int secondVal = arr[n-i-1];
        arr[n-i-1] = firstVal;
        arr[i] = secondVal;
    }
}
void printArr(int arr[], int n){
    for (int i=0; i<n; i++){
        printf("%d\t",arr[i]);
    }
}*/

//Program to print first n fibonacci number
/*#include<stdio.h>
int main(){
    int n;
    printf("Enter n (n>2): "); //n is the number of fibonacci number
    scanf("%d",&n);

    int fib[n];
    fib[0] = 0;
    fib[1] = 1;
    
    printf("0\t");
    printf("1\t");
    for (int i=2; i<n; i++){
        fib[i] = fib[i-1] + fib[i-2];
        printf("%d\t",fib[i]);
    }
    return 0;
}*/

//2-D array to printing the table of 2 and 3
/*#include<stdio.h>
void storeTable(int arr[][10], int n, int m, int number);
int main(){
    int table[2][10];
    storeTable(table,0,10,2);
    storeTable(table,1,10,3);

    for (int i=0; i<10; i++){
        printf("%d\t",table[0][i]);
    }
    printf("\n");
    for (int i=0; i<10; i++){
        printf("%d\t",table[1][i]);
    }
    return 0;
}
void storeTable(int arr[][10], int n, int m, int number){
    for (int i=0; i<m; i++){
        arr[n][i] = number * (i+1);
    }
}*/



// Transpose of matrix
/*#include<stdio.h>
int main(){
    int m,n;
    printf("Enter rows and columns: ");
    scanf("%d %d",&m,&n);
    int matrix[m][n];
    

    printf("Enter elements of matrix: ");
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            scanf("%d",&matrix[i][j]);
        }
    }

    printf("Your matrix is:\n");
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            printf("%d\t",matrix[i][j]);
        }
        printf("\n");
    }

   int transpose[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            transpose[i][j] = matrix[j][i];
        }
    }

    printf("Transpose matrix is:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            printf("%d\t",transpose[i][j]);
        }
        printf("\n");
    }
    return 0;
}*/



//  Addition of two matrices 
/*#include<stdio.h>
//int printArray(int *p);
int main(){
    int a1[2][2], a2[2][2], result[2][2];
    int *p = a1, *q = a2;
    printf("Enter elements of 1st matrix : ");
    for(int i=0; i<4; i++){
        scanf("%d",p);
        p++;
    }
    printf("Your 1st matrix is :\n");
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            printf("%d  ",a1[i][j]);
        }
        printf("\n");
    }

    printf("Enter elements of 2nd matrix : ");
    for(int i=0; i<4; i++){
        scanf("%d",q);
        q++;
    }
    printf("Your 2nd matrix is :\n");
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            printf("%d  ",a2[i][j]);
        }
        printf("\n");
    }

    printf("Addition of matrix a1 & a2 are :\n");
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            result[i][j] = a1[i][j] + a2[i][j];
            printf("%d  ",result[i][j]);
        }
        printf("\n");
    }
    // int a[2][3] = {4,3,5,7,1,2};
    // for(int i=0; i<2; i++){
    //     for(int j=0; j<3; j++){
    //         printf("%d  ",a[i][j]);
    //     }
    //     printf("\n");
    // }
    return 0;
}
/*int printArray(int *p){
    for(int i=0; i<4; i++){
        printf("%d\t",*p);
        p++;
    }
}*/


//  Multiplicatio of two matrices 
/*#include<stdio.h>
int main(){
    int a1[2][2], a2[2][2], result[2][2];
    int *p = a1, *q = a2, sum = 0;
    printf("Enter elements of 1st matrix : ");
    for(int i=0; i<4; i++){
        scanf("%d",p);
        p++;
    }
    printf("Your 1st matrix is :\n");
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            printf("%d  ",a1[i][j]);
        }
        printf("\n");
    }

    printf("Enter elements of 2nd matrix : ");
    for(int i=0; i<4; i++){
        scanf("%d",q);
        q++;
    }
    printf("Your 2nd matrix is :\n");
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            printf("%d  ",a2[i][j]);
        }
        printf("\n");
    }

    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            for(int k=0; k<2; k++){
                sum = sum + a1[i][k] * a2[k][j];
                result[i][j] = sum;
            }
            sum = 0;
        }
    }
    printf("Multiplication of matrices a1 & a2 is :\n");
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            printf("%d   ",result[i][j]);
        }
        printf("\n");
    }
    return 0;
}*/



// Addition ,Subtraction and Multiplication of two matrices
#include<stdio.h>
int main(){
    int m,n,p,q;
    printf("Enter m,n,p,q respectively: ");
    scanf("%d %d %d %d",&m,&n,&p,&q);
    int arr1[m][n];
    int arr2[p][q];
    printf("Enter 1st matrix:\n");
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            scanf("%d",&arr1[i][j]);
        }
    }
    printf("Enter 2nd matrix:\n");
    for(int i=0; i<p; i++){
        for(int j=0; j<q; j++){
            scanf("%d",&arr2[i][j]);
        }
    }
    printf("First matrix is :\n");
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            printf("%d  ",arr1[i][j]);
        }
        printf("\n");
    }
    printf("Second matrix is :\n");
    for(int i=0; i<p; i++){
        for(int j=0; j<q; j++){
            printf("%d  ",arr2[i][j]);
        }
        printf("\n");
    }
    int sum[m][q],diff[p][n];
    if(m==p && n==q){
        printf("Sum of both matrices are :\n");
        for(int i=0; i<m; i++){
            for(int j=0; j<q; j++){
                sum[i][j] = arr1[i][j] + arr2[i][j];
                printf("%d  ",sum[i][j]);
            }
            printf("\n");
        }
        printf("Difference of both matrices are :\n");
        for(int i=0; i<m; i++){
            for(int j=0; j<q; j++){
                diff[i][j] = arr1[i][j] - arr2[i][j];
                printf("%d  ",diff[i][j]);
            }
            printf("\n");
        }
    }
    int mul[m][q], summ = 0;
    if(n==p){
        printf("Multiplication of both matrices are :\n");
        for(int i=0; i<m; i++){
            for(int j=0; j<q; j++){
                summ = 0;
                for(int k=0; k<n; k++){
                    int r = arr1[i][k] * arr2[k][j];
                    summ = summ + r;
                }
                mul[i][j] = summ;
                printf("%d  ",mul[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}

//Minimum and Maximun among five numbers
/*#include<stdio.h>
int main(){
    int a[5];
    printf("Enter five numbers:");
    for(int i=0; i<5; i++){
        scanf("%d",&a[i]);
    }
    int idx_min = 0;
    for(int j=0+1; j<5; j++){
        if(a[j]<a[idx_min]){
            idx_min = j;
        }
    }
    printf("Minimum number among entered number is: %d\n",a[idx_min]);
    int idx_max = 0;
    for(int i=1; i<5; i++){
        if(a[i]>a[idx_max]){
            idx_max = i;
        }
    }
    printf("Maximun number among entered number is: %d\n",a[idx_max]);
    return 0;
}*/



//Accending and Descending order of five numbers
/*#include<stdio.h>
void swap(int *a, int *b){
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}
int main(){
    int a[5];
    printf("Enter five numbers:\n");
    for(int i=0; i<5; i++){
        scanf("%d",&a[i]);
    }
    for(int i=0; i<5; i++){
        int min = i;
        for(int j=i+1; j<5; j++){
            if(a[j] < a[min]){
                min = j;
            }
        }
        if(min != i){
            swap(&a[i], &a[min]);
        }
    }
    printf("Accending order of numbers are:\n");
    for(int i=0; i<5; i++){
        printf("%d\t",a[i]);
    }
    printf("\nDescending order of numbers are:\n");
    for(int i=4; i>=0; i--){
        printf("%d\t",a[i]);
    }
    return 0;
}*/