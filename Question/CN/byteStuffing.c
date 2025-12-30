#include <stdio.h>
#define max 20
int main() {
    char flag='f', esc='e';
    char data[max], trData[2*max];
    printf("Enter flow of data(like 'abcegj'): ");
    fgets(data, max, stdin);

    int n=0, j=0;
    trData[j++] = 'f';
    while(data[n] != '\n') {
        if(data[n]=='f' || data[n]=='e') {
            trData[j++] = 'e';
        }
        trData[j++] = data[n++];
    }
    trData[j++] = 'f';
    trData[j] = '\0';
    printf("Transmitted data- ");
    puts(trData);
    return 0;
}