/*
Author : Anmol Biswas
1. Input a sentence and find the unique words 
2. Find all anagrams also
DOC : 5th June 2024
*/



#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

int isAnagram(char *str1,char *str2)
{
    int n=strlen(str1);
    int m=strlen(str2);
    
    if(n!=m)
        return 0;
    
    char freq[256]={0};
    for(int i=0;i<n;i++)
    freq[str1[i]]+=1;

    for(int i=0;i<n;i++)
    freq[str2[i]]-=1;

    int flag=1;
    for(int i=0;i<256;i++)
    {
    	if(freq[i]!=0)
	    {
	    	flag=0;
	    	break;
	    }
    }

	return flag;
}



int main()
{
    char line[100];
    char words[100][100];
    printf("Enter a sentence: ");
    scanf(" %[^\n]",line);
    
    char *token=(char *)malloc(sizeof(char *));
    token=strtok(line," ");
    
    int p=0;
    while(token)
    {
        strcpy(words[p],token);
        token=strtok(NULL," ");
        p++;
    }
    
    int freq[100]={0};
    
    for(int i=0;i<p-1;i++)
    {
        for(int j=i+1;j<p;j++)
        {
            if(isAnagram(words[i],words[j]))
             {
                 freq[i]=-1;
                 freq[j]=-1;
             }    
        }
    }
    
    
    for(int i=0;i<p;i++)
    {
        if(freq[i]==-1)
        printf("%s- Anagram\n",words[i]);
        else
        printf("%s- Unique\n",words[i]);
    }
    
    return 0;
}

