/*
Author : Anmol Biswas
Input a string , choose 2 lexicographicaly consecutive characters and delete both . (Eg: acdbfz out- abfz then fz)
DOC : 30th May 2024
*/

#include <stdio.h>
#include <string.h>
#define MAX 100

int main()
{
    char word[MAX];
    printf("Enter a word: ");
    scanf("%s",word);
    int n=strlen(word);
    
    int cnt=0;
    int i=0;
    int freq[100]={0};
    
    while(1)
    {
        if(i==n-1)
        break;
        
        if(word[i]+1==word[i+1] && freq[i]!=-1)
            {
                freq[i]=-1;
                freq[i+1]=-1;
                i=0;
            
                char temp[100];
                int p=0;
                for(int j=0;j<n;j++)
                {
                    if(freq[j]!=-1)
                        {
                            temp[p]=word[j];
                            p++;
                        }
                }
                
                for(int k=0;k<p;k++)
                freq[k]=0;
                
                strcpy(word,temp);
                n=p;    
            }
            else
            i++;    
    }

    for(int i=0;i<n;i++)
    {
        if(freq[i]!=-1)
          printf("%c",word[i]);    
    }
    
    return 0;
}
