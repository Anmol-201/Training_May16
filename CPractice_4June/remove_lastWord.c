/*
Author : Anmol Biswas
Write a C program to remove from last occurrence of a word in given string
	Example
 
Input
 
Input string: I am a programmer. I learn at Codeforwin.
Input word to remove: I
Output
 
String after removing last occurrence of 'I': 
I am a programmer.  learn at Codeforwin

DOC : 4th June 2024
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char line[1000], word[100];
    printf("Enter a sentence: ");
    scanf("%[^\n]",line);
    printf("\nEnter word to remove: ");
    scanf("%s",word);
    
    char *token=(char *)malloc(sizeof(char *));
    token=strtok(line," ");
    char out[100][100];
    int p=0;
    
    while(token)
    {
        char temp[100];
        strcpy(temp,token);
        strcpy(out[p],temp);
        p++;
        token=strtok(NULL," ");
    }
    
    for(int i=p-1;i>-1;i--)
    {
        if(strcmp(word,out[i])==0)
        {
            strcpy(out[i],"1");
            break;
        }
    }
    
    // char ans[100][100];
    // for(int i=0;i<p;i++)
    // {
    //     if(strcmp(ans[i],"1")==0)
    //     continue;
        
    //     strcpy(ans[i],out[i]);
    // }
    
    
    for(int i=0;i<p;i++)
    {
        if(strcmp(out[i],"1")==0)
        continue;
        printf("%s ",out[i]);
    }
    
    return 0;
}

