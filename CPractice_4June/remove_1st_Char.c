/*
Author : Anmol Biswas
Write a C program to replace first occurrence of a character with another character in a string.
Example
 
Input
 
Input string: I love programming.
Input character to replace: .
Input character to replace with: !
 
Output
 
String after replacing '.' with '!': I love programming!

DOC : 4th June 2024
*/
 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char line[1000], ch1,ch2;
    printf("Enter a sentence: ");
    scanf("%[^\n]",line);
    printf("\nEnter character to replace: ");
    scanf(" %c",&ch1);
    printf("\nEnter character to replace with: ");
    scanf(" %c",&ch2);
    
    int n=strlen(line);
    for(int i=0;i<n;i++)
    {
        if(line[i]==ch1)
        {
            line[i]=ch2;
            break;
        }
    }
    
    printf("After replacing:\n");
    for(int i=0;i<n;i++)
    printf("%c",line[i]);

    return 0;
}

