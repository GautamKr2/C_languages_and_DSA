/*#include<stdio.h>
int i = 1;
float res;
float semi(float l, float r, float n){
    
    // for(int i=1; i<n; i++){
    //     if(i%2){
    //         res = (l+r)/2;
    //         l = res;
    //     }
    //     else{
    //         res = (l+r)/2;
    //         r = res;
    //     }
    // }
    // return res;
    if(n == 1){
        return 0;
    }
    else{
        if(i%2 == 0){
            res = (l+r)/2;
            r = res;
        }
        else{
            res = (l+r)/2;
            l = res;
        }
    }
    i++;
    semi(l, r, n-1);
    return res;
}
int main(){
    float result = semi(0, 1, 5);
    printf("%f", result);
    return 0;
}*/



#include<stdio.h>
int main(){

    return 0;
}