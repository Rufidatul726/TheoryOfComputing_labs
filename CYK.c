#include<stdio.h>
#include<string.h>

#define Max 100

char terminal[Max];
char nonterminal[Max];
char string[Max];

struct pair{
    char node;
    char product[Max][Max];
}initial[Max];

/*struct matrix{
    int pos[Max][Max];
    char node[Max];
}matrix[Max];*/

struct matrix{
    char node[Max][Max][15];
}matrix;

int checkDuplicate(char x, char array[]){
    int i;
    
    for(i=0;i<strlen(array);i++){
        if(array[i]==x){
            return 1;
        }
    }
    return 0;
}

void findchar(char x[], int index1, int index2){
    int i,j;
    int k=strlen(matrix.node[index1][index2]);
    //char temp[10];

    for(i=0;i<strlen(nonterminal);i++){
        for(j=0;j<2;j++){
            if(strcmp(initial[i].product[j],x)==0){
                if(checkDuplicate(nonterminal[i],matrix.node[index1][index2])==0){
                    matrix.node[index1][index2][k++]=nonterminal[i];
                     //printf("%s  print hoi?\n", matrix.node[i][j]);
                }
            }
        }
    }
}

void matrixmultiply(int index1, int index2, int index3, int index4, int index5, int index6){
    int i,j,k=0;
    char temp[10];
    int length1=strlen(matrix.node[index1][index2]);
    int length2=strlen(matrix.node[index3][index4]);
    
    for(i=0;i<length1;i++){
        for(j=0;j<length2;j++){
            k=0;
            temp[k++]=matrix.node[index1][index2][i];
            temp[k++]=matrix.node[index3][index4][j];
            temp[k]='\0';
           // printf("%s %d %d hoisena?", temp, index1, index2);
            findchar(temp,index5,index6);
        }
    }

    
}

int main(void){
    int i,j,k;
    char temp[10];

    terminal[0]='a';
    terminal[1]='b';

    strcpy(nonterminal, "SABC");

    for(i=0;i<strlen(nonterminal);i++){
        initial[i].node=nonterminal[i];
    }

    /*for(i=0;i<nonterminal;i++){
        for(j=0;;j++){
            scanf("%s",initial[i].product[j]);
            if(strcmp(initial[i].product[j],"Exit")==0)break;
        }
    }*/

        strcpy(initial[0].product[0],"AB");
        strcpy(initial[0].product[1],"BC");
        strcpy(initial[1].product[0],"BA");
        strcpy(initial[1].product[1],"a");
        strcpy(initial[2].product[0],"CC");
        strcpy(initial[2].product[1],"b");
        strcpy(initial[3].product[0],"AB");
        strcpy(initial[3].product[1],"a");

    printf("Production of CNF grammar G:");
    for(i=0;i<strlen(nonterminal);i++){
        printf("\n%c -> ", initial[i].node);
        for(j=0;j<2;j++){
            printf("%s  ", initial[i].product[j]);
        }
    }
    
    printf("\nEnter string to check membership: \n");
    //scanf("%s", string);
    strcpy(string, "baaab");

    int length=strlen(string);
    k=0;
    int k1=0, k2=0;

    for(i=1;i<=length;i++){
        for(j=i;j<=length;j++){
            if(i==j){
                temp[0]=string[i-1];
                temp[1]='\0';
                findchar(temp, i,j);
            }
        }
    }

    for(i=1;i<=length;i++){
        for(j=1;j<=length;j++){
            for(k1=j;k1<=i+j;k1++){
                matrixmultiply(j,k1,k1+1,i+j,j,i+j); 
                //if(j==3 && i==2)printf("%d %d %s\t", i,j ,matrix.node[j][i+j]);         
            }
            // printf("%d %d %s\t", i,j ,matrix.node[i][j]);
        }
      //  printf("\n");
    }

    for(i=0;i<=length;i++){
        for(j=1;j<=length;j++){
             printf("%s\t",matrix.node[j][j+i]);
        }
        printf("\n");
    }

    for(i=0;i<strlen(matrix.node[1][length]);i++){
        if(matrix.node[1][length][i]=='S'){
            printf("\nString is a member of language");
            return 0;
        }
    }

    printf("\nString is not a member of language");
    return 0;


}