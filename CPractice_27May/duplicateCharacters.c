#include <stdio.h>
#include <string.h>

int main()
{
    char word[100];
    int n;
    printf("Enter word: ");
    scanf("%s",&word);
    n=strlen(word);
    int arr[100]={0};
    
    for(int i=0;i<n;i++)
    {
        char ch=word[i];
        for(int j=i+1;j<n;j++)
        {
            if(ch==word[j] && arr[j]!=-1)
               arr[j]=-1;
        }
    }
    
    printf("Word after removing duplicates: \n");
    for(int i=0;i<n;i++)
    {
        if(arr[i]==-1)
         continue;
        printf("%c",word[i]); 
    }
    
    return 0;
}

