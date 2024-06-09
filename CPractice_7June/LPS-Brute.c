#include <stdio.h>
#include <string.h>

int isPalind(char *s)
{
    int n=strlen(s);
    int i=0, j=n-1;
    while(i<=j)
    {
        if(s[i]!=s[j])
            return 0;
            
        i++;j--;    
    }
    return 1;
}



int main()
{
    char word[100];
    printf("Enter a string: ");
    scanf("%s",word);
    
    int n=strlen(word);
    int len=0;
    
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
           char temp[100]="";
           int size=j-i+1;
           strncpy(temp,word+i,size);
           if(isPalind(temp))
             len= (size>len) ? size : len;
        }
    }
    
    printf("LPS: %d",len);

    return 0;
}

