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
void selection_sort(){
    int i, j, min;
    for(i=0; i<=n-2; i++){
        min = i;
        for(j=i+1; j<=n-1; j++){
            if(Arr[j] < Arr[min])
                min = j;
        }
        if(min != i){
            swap(&Arr[min], &Arr[i]);
        // Arr[min] = Arr[min] + Arr[i];
        // Arr[i] = Arr[min] - Arr[i];
        // Arr[min] = Arr[min] - Arr[i];
        }
    }
    printf("After selection sort, your array is\n");
    display();
}
void bubble_sort(){
    int i, j;
    for(i=0; i<=n-1; i++){
        for(j=0; j<=n-2; j++){
            if(Arr[j] > Arr[j+1])
                swap(&Arr[j], &Arr[j+1]);
        }
    }
    printf("After bubble sort, your array is\n");
    display();
}
void insertion_sort(){
    int i, j, temp;
    for(i=1; i<n; i++){
        temp = Arr[i];
        for(j=i; j>0; j--){
            if(Arr[j-1] > temp){
                Arr[j] = Arr[j-1];
            }
            else{
                break;
            }
        }
        Arr[j] = temp;
    }
    printf("After insertion sort, your array is\n");
    display();
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
        if(start < end){
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
void merge(int lb, int mid, int ub){
    int i=lb, j=mid+1, k=lb, B[max];
    while(i<=mid && j<=ub){
        if(Arr[i] <= Arr[j]){
            B[k] = Arr[i];
            i++;
        }
        else{
            B[k] = Arr[j];
            j++;
        }
        k++;
    }
    if(i > mid){
        while(j <= ub){
            B[k] = Arr[j];
            j++;
            k++;
        }
    }
    else{
        while(i <= mid){
            B[k] = Arr[i];
            i++;
            k++;
        }
    }
    for(k=lb; k<=ub; k++){
        Arr[k] = B[k];
    }
}
void merge_sort(int lb, int ub){
    int mid;
    if(lb < ub){
        mid = (lb + ub)/2;
        merge_sort(lb, mid);
        merge_sort(mid+1, ub);
        merge(lb, mid, ub);
    }
}

int main(){
    int ch;
    printf("How many elements you want to enter : ");
    scanf("%d",&n);
    printf("Enter elements of array :\n");
    for(int i=0; i<n; i++)
        scanf("%d",&Arr[i]);
    printf("Your array is\n");
    display();
    while(1){
        printf("For sortint by selection press 1, by bubble press 2, by insertion press 3, by quick press 4, by merge press 5, for print array press 6, press 7 for exit\nChoose any option : ");
        scanf("%d",&ch);
        switch(ch){
            case 1 : selection_sort(); break;
            case 2 : bubble_sort(); break;
            case 3 : insertion_sort(); break;
            case 4 : quick_sort(0, n-1); break;
            case 5 : merge_sort(0, n-1); break;
            case 6 : display(); break;
            case 7 : exit(0);
            default : printf("Invalid input!\n");
        }
    }
    return 0;
}