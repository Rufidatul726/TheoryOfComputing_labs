#include<stdio.h>
#include<string.h>

char stack[100];
int top=-1;
int max=0;

void push(char item)
{
    stack[++top] = item;
}

void pop()
{
    stack[top--] = '\0';
}

int main(void){
    int i,j,k;
    stack[++top] = 'Z';

    char string[100];
    printf("Enter a string: ");

    scanf("%s",string);
    int len = strlen(string);
    
    for(i=0;i<len;i++){
        if(max!=0 && string[i]!=stack[top]){
            for(j=i;j<max;j++){
                push(string[j]);
            }
        }

        if(stack[top]==string[i]){
            pop();
            max=i;
        }
        else{
            push(string[i]);
        }

        if(top==0 && i==strlen(string)-1){
            printf("\nString is accepted bt the language");
            return 0;
        }
    }

    printf("\nString is not accepted by the language");
    return 0;
}
