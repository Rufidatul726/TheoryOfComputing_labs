#include<stdio.h>
#include<string.h>

int main(void){
    char input[10000];
    char alphabets[1000];
    char state[1000];
    char table[1000][1000];
    char string[1000];
    char temp;
    char strconsume[10000];
    char accepting_state[1000]={'\0'};
    int alphabet, states;
    int i,j,count=0;

    printf("Enter number of Alphabets of string:\n");
    scanf("%d", &alphabet);
    printf("Enter the Alphabets of string:\n");
    scanf("%s", &alphabets);

    printf("Enter how many States to make transition table:\n");
    scanf("%d", &states);
    printf("Enter the States :\n");
    scanf("%s", &state);

    printf("  ");
    for(i=0;i<alphabet;i++){
        printf("%c  ",alphabets[i]);
    }

    for(i=0;i<states;i++){
        printf("\n%c ",state[i]);
        getchar();
        //gets(table[i]);
        for(j=0;j<alphabet;j++){
            scanf("%c", &table[i][j]);
            if(table[i][j]==' ')j--;
        }
    }

    printf("Enter accepting state:");
    scanf("%s",&accepting_state);


    printf("Enter the String:");
    scanf("%s", &string);



    for(i=0;i<strlen(string);i++){
        for(j=0;j<alphabet;j++){
            if(string[i]==alphabets[j]){
                strconsume[i]=table[i][j];
                break;
            }
            else if(j==alphabet){
                printf("Invalid String");
                return 0;
            }
        }
    }

    for(i=0;i<strlen(accepting_state);i++){
        if(strconsume[states-1]==accepting_state[i]){
        printf("%c", strconsume[states-1]);
            printf("String is Accepted.");
            return 0;
        }
    }

    printf("String can not be Accepted.");
    return 0;

}
