/*#include"stdio.h"
int main(){
    char name[] = {'G','A','U','T','A','M',' ','K','U','M','A','R','\0'};
    printf("%s\n\n",name);

    char _name[] = "GAUTAM KASHYAP";
    printf("%s\n",_name);
    return 0;
}*/

/*#include<stdio.h>
void printString(char arr[]);
int  main(){
    char firstName[] = "GAUTAM ";
    char lastName[] = "KUMAR";

    printString(firstName);
    printString(lastName);
    return 0;
}
void printString(char arr[]){
    for(int i=0; arr[i] != '\0'; i++){
        printf("%c",arr[i]);
    }
}*/

/*#include<stdio.h>
int main(){
    char name[40];
    printf("Enter your name : ");
    scanf("%s",name);
    printf("Your name is %s.",name);
    return 0;
}*/

/*#include"stdio.h"
int main(){
    char fullName[75];
    printf("Enter your name : ");
    gets(fullName);
    puts(fullName);
    return 0;
}*/

/*#include<stdio.h>
int countLength(char x[]);
int main(){
    char name[64];
    printf("Enter name : ");
    fgets(name,64,stdin);
    puts(name);
    
    printf("Length of your name is %d.\n",countLength(name));
    return 0;
}
int countLength(char x[]){
    int count = 0;
    for(int i=1; x[i]!='\0'; i++){
        if(x[i] == ' ')
            continue;
        count++;

    }
    return count;
}*/


/*#include<stdio.h>
#include<string.h>
int main(){
    char name[40];
    printf("Enter your name : ");
    gets(name);
    puts(name);

    printf("Length of your name is %d.\n",strlen(name)); //It gives in the form of unsigned int .

    int length = strlen(name);
    printf("Length of your name is %d.\n",length);

    return 0;
}*/

/*#include<stdio.h>
#include<string.h>
void salting(char x[]);
int main(){
    char password[20];
    printf("Enter your password : ");
    scanf("%s",password);

    salting(password);
    return 0;
}
void salting(char x[]){
    char newPass[30];
    char salt[] = "123";
    strcpy(newPass,x);
    strcat(newPass,salt);
    printf("Salted password is : %s",newPass);
}*/

/*#include<stdio.h>
void checkChar(char x[], char c);
int main(){
    char str[20];
    printf("Enter string : ");
    scanf("%s",str);
    char ch;
    printf("Enter your character : ");
    scanf(" %c",&ch);

    checkChar(str,ch);
    return 0;
}
void checkChar(char x[], char c){
    for(int i=0; x[i] != '\0'; i++){
        if(x[i] == c){
            printf("Yes, your character is present.\n");
            return;
        }
    }
    printf("Your character is not present.\n");
    printf("%d",count);
}*/

#include<stdio.h>
void remblnk(char x[]);
int main(){
    char dtr[] = "program.";
    
    remblnk(dtr);
    return 0;
}
void remblnk(char x[]){
    for(int i=0; x[i] != '\0'; i++){
        if(x[i] == 'a')
            x[i] = 'A';
        else if(x[i] == 'e')
            x[i] = 'E';
        else if(x[i] == 'i')
            x[i] = 'I';
        else if(x[i] == 'o')
            x[i] = 'O';
        else if(x[i] == 'u')
            x[i] = 'U';
    }
    puts(x);
}