#include<stdio.h>
#include<string.h>

struct stack{
    char bracket[100];
    char operator[100];
    char alphabet[100];
}stack;

int operator(char operator){
    if(operator=='+' || operator=='*')return 1;
    else return 0;
}

int alphabet(char alphabet){
    if(alphabet=='1' || alphabet=='0')return 2;
    else return 0;
}

int bracket(char bracket){
    if(bracket=='(')return 4;
    else if(bracket==')')return 5;
    else return 0;
}
int main(){
    int i,j,k;
    char string[1000];

    scanf("%s", string);
    int brackets=0;
    if(bracket(string[0])==4)++brackets;

    if(operator(string[0])!=0 || strlen(string)<3  || strlen(string)%2==0 || bracket(string[0])==5){
        printf("String not accepted");
        return 0;
    }
    for(i=1;i<strlen(string);i++){
        if(alphabet(string[i])==alphabet(string[i-1]) && alphabet(string[i-1])!=0)break;
        if(operator(string[i])==operator(string[i-1]) && operator(string[i-1])!=0)break;
        if(bracket(string[i-1])==4 && operator(string[i])==1)break;
        if(bracket(string[i-1])==1 && operator(string[i])==5)break;
        if(bracket(string[i-1])==4 && bracket(string[i])==5)break;
        if(bracket(string[i-1])==5 && bracket(string[i])==4)break;
        if(bracket(string[i])==4)++brackets;
        if(bracket(string[i])==5)--brackets;
        if(brackets<0)break;
        
        if(i==strlen(string)-1){
            printf("String accepted");
            return 0;
        }
    }

    printf("String not accepted");
    return 0;
}