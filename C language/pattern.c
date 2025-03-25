/*#include<stdio.h>
int main(){
    int i,j,n;
    printf("Enter size of square : ");
    scanf("%d",&n);
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            if(i==1 || i==n || j==1 || j==n){
                printf(" * ");
            }
            else
                printf("   ");
        }
        printf("\n");
    }
    return 0;
}*/


/*#include<stdio.h>
int main(){
    int n;
    printf("Enter n : ");
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i+j >= n+1){
                printf("   *");
            }
            else
                printf("  ");
        }
        printf("\n");
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(j >= i+1){
                printf("   *");
            }
            else
                printf("  ");
        }
        printf("\n");
    }
    return 0;
}*/

