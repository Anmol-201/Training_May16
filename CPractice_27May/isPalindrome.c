#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    printf("Enter a word: ");
    scanf("%s",&str);
    
    int n=strlen(str);
    int i=0,j=n-1;
    int flag=1;
    while(i<=j)
    {
        if(str[i]!=str[j])
        {
            printf("Not a palindrome!");
            flag=0;
            break;
            
        }
        i++;j--;
    }
    
    if(flag==1)
    printf("Palindrome!");
    
    return 0;
}



