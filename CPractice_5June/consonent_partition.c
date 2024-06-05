/*
Author : Anmol Biswas
Input a string and find no. of ways in which a string can be partitioned into 2 non empty substring such that no. of consonents in 1st part is greater than no. of consonents in 2nd part
DOC : 5th June 2024
*/


#include <stdio.h>
#include <string.h>

int isVowel(char ch)
{
    char vowel[11]={'a','e','i','o','u','A','E','I','O','U'};
    for(int i=0;i<11;i++)
    {
        if(ch==vowel[i])
            return 1;
    }
    return 0;
}


int main()
{
    char word[100];
    printf("Enter the string: ");
    scanf("%s",word);
    int n=strlen(word);
    
    int count=0;
    int ways=0;
    for(int i=0;i<n;i++)
    {
        if(!isVowel(word[i]))
        count++;
    }
    
    
    int curr=0;
    for(int i=0;i<n;i++)
    {
        if(!isVowel(word[i]))
        curr++;
        
        if(curr>count/2)
        ways++;
    }
    
    
    printf("Number of ways: %d",ways);
    
    return 0;
}

