/*
Author : Anmol Biswas
1. You are given a string, str.
 
You need to find the score of str as per the following rules:
1) For each palindrome of length 4 in str, add 5 to the score
2) For each palindrome of length 5 in str, add 10 to the score
 
It is given that palindromes can overlap within str. However, the characters of the palindrome must be continuous and must NOT be circular (i.e. they must NOT wrap around the end of the string.
 
Output the final value of score.

DOC : 4th June 2024
*/


#include <stdio.h>
#include <string.h>

int main()
{
    char word[100];
    printf("Enter a word: ");
    scanf("%s",word);
    
    int n=strlen(word);
    int score=0;
    
    for(int i=0;i<=n-4;i++)
    {
        int j=i+3;
        int flag=1;
        while(i<=j)
        {
            if(word[i]!=word[j])
            {
                flag=0;
                break;
            }
            i++;j--;
        }
        
        if(flag==1)
        score+=5;
    }
    
    
     for(int i=0;i<=n-5;i++)
    {
        int j=i+4;
        int flag=1;
        while(i<=j)
        {
            if(word[i]!=word[j])
            {
                flag=0;
                break;
            }
            i++;j--;
        }
        
        if(flag==1)
        score+=10;
    }
    
    printf("Score: %d",score);
    
    return 0;
}

