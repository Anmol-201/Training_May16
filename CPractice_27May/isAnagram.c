#include <stdio.h>
#include <string.h>
#define MAX 100

int main()
{
    char str1[MAX], str2[MAX];
    int n,m;
    printf("Enter word 1: ");
    scanf("%s",&str1);
    printf("Enter word 2: ");
    scanf("%s",&str2);
    
    n=strlen(str1);
    m=strlen(str2);
    
    if(n!=m)
    {
        printf("Not anagram!");
        exit(0);
    }
    
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


    if(flag==1)
	    printf("Valid Anagram!");
    else
	    printf("Not a Anagram!");
    
    
    return 0;
}

