/*#include<stdio.h>
int sum(int x);
int main(){
    int n,s=0;
    printf("Enter n : ");
    scanf("%d",&n);

    s = sum(n);
    printf("Sum of %d natural numbers is %d.",n,s);
    return 0;
}
int sum(int x){
    int s = 0;
    if(x == 1){
        return 1;
    }
    else{
        s = x + sum(x-1);
        return s;
    }
    return s;
}*/


/*#include<stdio.h>
int main(){
    int n;
    printf("Enter n : ");
    scanf("%d",&n);
    for(int i=1; i<=n*2-1; i++){
        if(i<=n){
            for(int j=1; j<=n; j++){
                if(i+j >= n+1)
                    printf("*   ");
                else
                    printf("  ");
            }
            printf("\n");
        }
        else{
            for(int j=1; j<=n; j++){
                if(j+n>=i+1)
                    printf("*   ");
                else
                    printf("  ");
            }
            printf("\n");
        }
    }
    return 0;
}*/




/*#include<stdio.h>
void main()
{
    int A[2][2],B[2][2],S[2][2],i,j;
    for(i=0; i<2; i++)
    {
        for(j=0; j<2; j++)
        {
            printf("Enter the elements of your matrix: ");
            scanf("%d",A[i][j]);
        }
    }
    for(i=0; i<2; i++)
    {
        for(j=0; j<2; j++)
        {
            printf("Enter the elements of your matrix: ");
            scanf("%d",B[i][j]);
        }
    }
    for(i=0; i<2; i++)
    {
        printf("\n");
        for(j=0; j<2; j++)
        {
            printf("your matrix is: %d\t",A[i][j]);
        }
    }
    for(i=0; i<2; i++)
    {
        printf("\n");
        for(j=0; j<2; j++)
        {
            printf("your matrix is: %d\t",B[i][j]);
        }
    }
    for(i=0; i<2; i++)
    {
        for(j=0; j<2; j++)
        {
            S[i][j]=A[i]+B[j];
        }
    }
    for(i=0; i<2; i++)
    {
        printf("\n");
        for(j=0; j<2; j++)
        {
            printf("%d\t",S[i][j]);
        }
    }

}*/


#include<stdio.h>
int a=0, b=1, c;
int fib(int n){
    
    if(n>0){
        printf("%d  ",a);
        c = a+b;
        a = b;
        b = c;
        //printf("%d  ",a);
        fib(n-1);
    }
}
int main(){
    int n = 8;
    printf("Fibonacci series of %d terms are : \n",n);
    fib(n);
    return 0;
}