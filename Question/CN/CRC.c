#include <stdio.h>
#include <string.h>
#define max 20

int main() {
    char data[max], genPol[max/2];
    printf("Enter data bits: ");
    scanf("%s",data);
    printf("Enter Generato polynomial: ");
    scanf("%s",genPol);

    int m=strlen(genPol), n=strlen(data);
    for(int i=n; i<m+n-1; i++)
        data[i] = '0';
    data[m+n-1] = '\0';

    char temp[m+1];
    for(int i=0; i<m; i++)
        temp[i] = data[i];
    temp[m] = '\0';

    for(int i=0; i<n; i++) {
        if(temp[0] == '1') {
            for(int j=1; j<m; j++) {
                if(temp[j]==genPol[j]) {
                    temp[j-1] = '0';
                } else {
                    temp[j-1] = '1';
                }
            }
            temp[m-1] = data[i+m];
        }
        else {
            for(int j=1; j<m; j++) {
                temp[j-1] = temp[j];
            }
            temp[m-1] = data[i+m];
        }
    }
    temp[m-1] = '\0';

    printf("Checksum is - %s\n", temp);
    for(int i=n; i<n+m-1; i++) {
        data[i] = temp[i-m-1];
    }
    data[m+n-1] = '\0';
    printf("Transmitted data - %s\n", data);
    return 0;
}