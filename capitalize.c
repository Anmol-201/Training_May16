#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 1000

int main()
{
    char line[MAX];
    printf("Enter a sentence: ");
    scanf("%[^\n]s",line);
    printf("\nCapitalized sentence is:\n");
    
    char *token=(char *)malloc(MAX);
    char output[MAX][100];
    
    token=strtok(line," ");
    
    int i=0;
    while(token)
    {
     char temp[100];
     token[0]=toupper(token[0]);
     strcpy(temp,token);
     strcpy(output[i],temp);
     
     token=strtok(NULL," ");
     i++;
    }
    
    
    for(int p=0;p<i;p++)
    printf("%s ",output[p]);
    
    return 0;
}


