/*
Author : Anmol Biswas
WAP that takes string(sentence) ,substring(1 word) and a character(1 char) , search the character in string and find the position and return . only 1st occurrence. IF not found set that char to -1. Same for sentence find the word or substring. Display sum of both such positions. -2 if both not found
DOC : 5th June  2024
*/



#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char line[100], word[100], ch;
    char out[100][100];
    printf("Enter a sentence: ");
    scanf(" %[^\n]",line);
    printf("\nEnter a word: ");
    scanf(" %s",word);
    printf("\nEnter a charcter: ");
    scanf(" %c",&ch);
    
    int ind1=-1, ind2=-1;
    
    char *token=(char *)malloc(sizeof(char *));
    token=strtok(line," ");
    
    int p=0;
    while(token)
    {
        strcpy(out[p],token);
        token=strtok(NULL," ");
        p++;
    }

    for(int i=0;i<p;i++)
    {
        if(strcmp(word,out[i])==0)
        {
            ind1=i+1;
            break;
        }
    }
    
    int len=strlen(word);
    
    for(int i=0;i<len;i++)
    {
        if(word[i]==ch)
        {
            ind2=i+1;
            break;
        }
    }
    
    printf("\nSum of positions: %d",ind1+ind2);
    
    return 0;
}





