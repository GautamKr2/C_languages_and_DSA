/*#include<stdio.h>
int main(){

    // int b[5] = {4,0,7,-2,9};
    // printf("%d\n",ab);
    // printf("%d\n",&b);

    int a[2][3] = {6,2,4,0,7,1};
    // printf("%d\n",&a[0]);
    // printf("%d\n",&a[1]);
    // printf("%d\n",a+1);

    int *p = a;
    // printf("%d\n",*p);
    // printf("%d\n",*(p+1));

    printf("%d\n",**p);
    // printf("%d\n",a+1);
    // printf("%d\n",(a+1)+2);
    // printf("%d\n",*(a+1)+2);
    // printf("%d\n",a[1]);
    // printf("%d\n",**(a));
    // printf("%d\n",**(a+1));
    // printf("%d\n",*(a+1)+2);
    // printf("%d\n",*(*(a+1)+2));


    return 0;
}*/



// Shorting of elements of an array
#include<stdio.h>
int main(){
    int a[5] = {5,2,8,-1,4};
    int min, i ,j;
    for(i=0; i<5; i++){
        min = i;
        for(j=i+1; j<5; j++){
            if(a[min] > a[j]){
                min = j;
            }
        }
        int t = a[min];
        a[min] = a[i];
        a[i] = t;
    }
    for(i=0; i<5; i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
    return 0;
}