#include <stdio.h>
#include <string.h>

int main()
{
    char word[100], out[100][100];
    int k;
    printf("Enter a string: ");
    scanf("%s",word);
    printf("Enter length k: ");
    scanf("%d",&k);
    
    int n=strlen(word);
    int p=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
           char temp[100]="";
           int size=j-i+1;
           if(size==k)
           {
                strncpy(temp,word+i,size);    
                strcpy(out[p],temp);
                p++;
           }
        }
    }
    
    n=p;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(strcmp(out[i],out[j])>0)
            {
                char temp[100];
                strcpy(temp,out[i]);
                strcpy(out[i],out[j]);
                strcpy(out[j],temp);
            }
        }
    }
    
    for(int i=0;i<p;i++)
    printf("%s\n",out[i]);

    return 0;
}

