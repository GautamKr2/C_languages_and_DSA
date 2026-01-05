#include<stdio.h>
#include<stdlib.h>
#define max 10
int n, Arr[max];
void swap(int *a, int *b){
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}
void display(){
    for(int i=0; i<n; i++){
        printf("%d\t",Arr[i]);
    }
    printf("\n");
}
int partition(int lb, int ub){
    int pivot = Arr[lb];
    int start = lb, end = ub;
    while(start < end){
        while(start <= ub && Arr[start] <= pivot){
            start++;
        }
        while(end >= lb && Arr[end] > pivot){
            end--;
        }
        if (start < end) {
            swap(&Arr[start], &Arr[end]);
        }
    }
    swap(&Arr[lb], &Arr[end]);
    return end;
}
void quick_sort(int lb, int ub){
    if(lb < ub){
        int loc = partition(lb, ub);
        quick_sort(lb, loc-1);
        quick_sort(loc+1, ub);
    }
}
int main(){
    printf("How many elements you want to enter : ");
    scanf("%d",&n);
    printf("Enter elements of array :\n");
    for(int i=0; i<n; i++)
        scanf("%d",&Arr[i]);
    printf("Your array is\n");
    display();
    quick_sort(0, n-1);
    printf("After quick sort, your array is :\n");
    display();
    return 0;
}