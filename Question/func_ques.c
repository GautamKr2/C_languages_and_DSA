#include <stdio.h>
int cube(int n) {
    return n*n*n;
}
int mxm(int n, int arr[]) {
    int max = arr[0];
    for(int i=1; i<n; i++) {
        if(max < arr[i])
            max = arr[i];
    }
    return max;
}
int mnm(int n, int arr[]) {
    int min = arr[0];
    for(int i=1; i<n; i++) {
        if(min > arr[i])
            min = arr[i];
    }
    return min;
}
int main() {
    /*int n;
    printf("Enter n: ");
    scanf("%d",&n);
    int res = cube(n);
    printf("Cube of %d is : %d",n,res);*/

    int n;
    printf("How many numbers you want to enter: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter numbers: ");
    for(int i=0; i<n; i++)
        scanf("%d",&arr[i]);
    int max = mxm(n, arr);
    printf("Maximum of these numbers are: %d\n",max);
    int min = mnm(n, arr);
    printf("Minimum of these numbers are: %d\n",min);
    return 0;
}