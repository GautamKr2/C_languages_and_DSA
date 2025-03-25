/*#include<stdio.h>
#include<stdlib.h>
int main(){
    int *ptr;
    ptr = (int*) calloc(5, sizeof(int));
    for(int i=0, j=0; i<5*2, j<5; i++, j++){
        if(i%2 != 0){
            scanf("%d",&ptr[j]);
        }
    }
    for(int i=0; i<5; i++){
        printf("%d\n", ptr[i]);
    }
    printf("\n");

    //For even numbers
    ptr = realloc(ptr, 6);
    for(int i=1, j=0; i<=6*2, j<6; i++, j++){
        if(i%2 == 0){
            scanf("%d",&ptr[j]);
        }
    }
    for(int i=0; i<6; i++){
        printf("%d\n", ptr[i]);
    }
    free(ptr);
    return 0;
}*/



/*#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    printf("Enter n: ");
    scanf("%d",&n);
    int *p;
    p = (int*)calloc(n,sizeof(int));
    for(int i=0; i<n; i++){
        printf("%d\n",p[i]);
    }
    free(p);
    printf("\n");
    p = (int*)calloc(2,sizeof(int));
    for(int i=0; i<n; i++){
        printf("%d\n",p[i]);
    }
    return 0;
}*/



#include<stdio.h>
#include<stdlib.h>
int main(){
    int *p;
    p = (int*)calloc(3,sizeof(int));
    printf("Enter numbers(3): ");
    for(int i=0; i<3; i++){
        scanf("%d",&p[i]);
    }
    printf("\n");
    for(int i=0; i<3; i++){
        printf("%d\n",p[i]);
    }

    p = realloc(p,5);
    printf("Enter numbers(5): ");
    for(int i=0; i<5; i++){
        scanf("%d",&p[i]);
    }

    printf("\n");
    for(int i=0; i<5; i++){
        printf("%d\n",p[i]);
    }
    
    return 0;
}