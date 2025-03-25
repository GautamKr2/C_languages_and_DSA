#include<stdio.h>
int main(){
    FILE *fptr;
    fptr = fopen("Test.txt", "r");
    char s[20];
    fscanf(fptr, "%s", s);
    int count = 0;
    for(int i=0; s[i]!='\0'; i++){
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
            count++;
        }
    }
    printf("No of vowels in string of file is : %d",count);
    fclose(fptr);
    return 0;
}