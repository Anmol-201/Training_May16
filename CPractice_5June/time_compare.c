/*
Author : Anmol Biswas
WAP to take input an interger N, N lines of input : in each line a pair of time HH/MM/SS , compare each line
if 1st > 2nd - later
if 1st < 2nd - earlier
else - Equal
DOC : 5th June  2024
*/


#include <stdio.h>
#include<string.h>

int compare(char *t1,char *t2)
{
    if(strncmp(t1,t2,2)!=0)
    return strncmp(t1,t2,2);
    
    else if(strncmp(t1+3,t2+3,2)!=0)
    return strncmp(t1+3,t2+3,2);
    
    else 
    return strncmp(t1+6,t2+6,2);
}


int main()
{
    int n;
    int ans[100];
    printf("Enter number of lines: ");
    scanf("%d",&n);
    
    printf("Enter time pairs: \n");
    for(int i=0;i<n;i++)
    {
        char temp[100];
        scanf(" %[^\n]",temp);
        char t1[100], t2[100];
        strncpy(t1,temp,8);
        strncpy(t2,temp+9,8);
        ans[i]=compare(t1,t2);
    }
    
    for(int i=0;i<n;i++)
    {
        if(ans[i]==0)
        printf("Equal\n");    
        else if(ans[i]>0)
        printf("Later\n");
        else
        printf("Earlier\n");    
    }
    

    return 0;
}

