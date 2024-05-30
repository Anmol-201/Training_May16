/*
Author : Anmol Biswas
Delete adjacent duplicate characters of a word  (Eg. In=aaacdabef  out= cdabef)
DOC : 30th May 2024
*/


#include <stdio.h>
#include<string.h>
#define MAX 100

int main()
{
    char word[MAX];
    printf("Enter a word: ");
    scanf("%s",word);
    int n=strlen(word);
    int arr[100]={0};
    
    //aaabcdef remove adjacent duplicates
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(word[i]==word[j])
            {
                arr[i]=-1;
                arr[j]=-1;
            }
            else
              break;
        }
    }
    
    printf("After removing duplicate adjacents:\n");
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=-1)
         printf("%c",word[i]);
    }
    
    return 0;
}
