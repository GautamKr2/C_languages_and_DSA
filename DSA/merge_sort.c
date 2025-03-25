#include<stdio.h>
#define max 10
void merge(int A[], int lb, int mid, int ub){
    int i=lb, j=mid+1, k=lb, B[max];
    while(i<=mid && j<=ub){
        if(A[i] <= A[j]){
            B[k] = A[i];
            i++;
        }
        else{
            B[k] = A[j];
            j++;
        }
        k++;
    }
    if(i > mid){
        while(j <= ub){
            B[k] = A[j];
            j++;
            k++;
        }
    }
    else{
        while(i <= mid){
            B[k] = A[i];
            i++;
            k++;
        }
    }
    for(k=lb; k<=ub; k++){
        A[k] = B[k];
    }
}
void merge_sort(int A[], int lb, int ub){
    int mid;
    if(lb < ub){
        mid = (lb + ub)/2;
        merge_sort(A, lb, mid);
        merge_sort(A, mid+1, ub);
        merge(A, lb, mid, ub);
    }
}
int main(){
    int n, i, Arr[max];
    printf("How many elements you want to enter : ");
    scanf("%d",&n);
    printf("Enter elements of array :\n");
    for(i=0; i<n; i++){
        scanf("%d",&Arr[i]);
    }
    printf("Your array is :\n");
    for(i=0; i<n; i++){
        printf("%d  ",Arr[i]);
    }
    printf("\n");
    merge_sort(Arr, 0, n-1);
    printf("Sorted array is\n");
    for(i=0; i<n; i++){
        printf("%d  ",Arr[i]);
    }
    printf("\n");
    return 0;
}