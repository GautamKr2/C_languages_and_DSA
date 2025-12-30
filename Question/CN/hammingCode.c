#include <stdio.h>
#include <string.h>
#define max 20

int main() {
    char data[max], trnsmittedData[max];
    printf("Enter data bits: ");
    scanf("%s", data);
    int n=strlen(data), p=1;

    int i=1;
    while(i<n) {
        i *= 2;
        p++;
    }
    printf("%d\n", p);
    int k=1, j=0;
    for(int i=0; i<n+p; i++) {
        if(i+1==k) {
            trnsmittedData[i] = '0';
            k <<= 1;
        }
        else {
            trnsmittedData[i] = data[j++];
        }
    }
    trnsmittedData[n+p] = '\0';

    k = 1;
    for(int i=0; i<strlen(trnsmittedData); i++) {
        if(i+1==k) {
            int prtyBit = 0;
            for(int j=0; j<strlen(trnsmittedData); j++) {
                if((j+1) & k) {
                    if(j+1!=k)
                        prtyBit ^= (trnsmittedData[j] - '0');
                }
            }
            trnsmittedData[i] = prtyBit + '0';
            k <<= 1;
        }
    }
    trnsmittedData[n+p] = '\0';

    printf("Transmitted data: %s\n", trnsmittedData);
    return 0;
}