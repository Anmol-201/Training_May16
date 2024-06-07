#include <stdio.h>
#include <string.h>

int main()
{
    char s1[100],s2[100],s3[100];
    printf("Enter word1: ");
    scanf(" %s",s1);
    printf("Enter word2: ");
    scanf(" %s",s2);
    printf("Enter word3: ");
    scanf(" %s",s3);
    
    int freq[256]={0};
    int n=strlen(s1);
    int m=strlen(s2);
    int k=strlen(s3);
    
    if(k!=(n+m))
    printf("Not possible!");
    
    for(int i=0;i<n;i++)
        freq[s1[i]]+=1;
    for(int i=0;i<m;i++)
        freq[s2[i]]+=1;
    for(int i=0;i<k;i++)
        freq[s3[i]]-=1;
    
    int flag=1;    
    for(int i=0;i<256;i++)
    {
        if(freq[i]!=0)
        {
            printf("Not possible!");
            flag=0;
            break;
        }
    }
    if(flag)
    printf("Matching!");   
    
    
    return 0;
}
