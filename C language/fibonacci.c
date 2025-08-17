#include <stdio.h>

int fibo(int n) {
    if(n==0 || n==1)
        return n;
    else
        return fibo(n-1) + fibo(n-2);
}

int main() {
    int f1=0, f2=1, n;
    printf("Enter n: ");
    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        /*if(i==0 || i==1)
            printf("%d ",i);
        else
            i%2 ? printf("%d ",f2=f1+f2) : printf("%d ",f1=f1+f2);*/
        printf("%d ",fibo(i));
    }
    return 0;
}