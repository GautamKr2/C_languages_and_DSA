#include <stdio.h>
#include <string.h>
#define max 100

void modify(char s[], int k) {
    int i, len=strlen(s);
    for(i=len-1; i>k; i--)
        s[i+1] = s[i];
    s[i+1] = '0';
    s[len+1] = '\0';
}

int main() {
    char str[max];
    printf("Enter string of bits: ");
    scanf("%s", &str);
    printf("Given bits = %s\n", str);
    int i=0, count=0;
    while(str[i] != '\0') {
        if(str[i]=='1') count++;
        else if(str[i]=='0') count=0;
        if(count==5)
            modify(str, i);
        i++;
    }
    printf("%s\n", str);
    return 0;
}