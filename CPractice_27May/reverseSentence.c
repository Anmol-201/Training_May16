#include <stdio.h>
#include<string.h>
#define SIZE 1000

int main()
{
    char line[SIZE];
    char *token=(char *)malloc(SIZE);
    
    printf("Enter a sentence: ");
    scanf("%[^\n]s",&line);
    
    char str[SIZE][100];
    
    token=strtok(line," ");
    int i=0;
    while(token)
    {
        char temp[100];
        strcpy(temp,token);
        strcpy(str[i],temp);
        i++;
    
        token=strtok(NULL," ");
    }
    
    printf("\nReversed sentence is:\n");
    for(int j=i-1;j>-1;j--)
    printf("%s\t",str[j]);
    
    return 0;
}

