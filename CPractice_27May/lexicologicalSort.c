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
    int n=0;
    while(token)
    {
        char temp1[100];
        strcpy(temp1,token);
        strcpy(str[n],temp1);
        n++;
        token=strtok(NULL," ");
    }
    
    char temp[50];
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
           if ( strcmp(str[i],str[j])>0) 
           {
             strcpy(temp,str[i]);
             strcpy(str[i],str[j]);
             strcpy(str[j],temp);
           }
        }
    }
    
    printf("Array in Lexicographical order is:\n");
    for(int i=0;i<n;i++)
    printf("%s\t",str[i]);
    
    return 0;
}

