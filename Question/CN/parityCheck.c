#include <stdio.h>
#define max 100

int main() {
    char data[max];
    int n=0, count=0;
    printf("Enter data: ");
    fgets(data, max, stdin);
    printf("Entered data is - ");
    puts(data);
    
    while(data[n] != '\n') {
        if(data[n]=='1') count++;
        n++;
    }
    if(count%2)
        printf("Given data is in odd parity.");
    else
        printf("Given data is in even parity.");
    return 0;
}