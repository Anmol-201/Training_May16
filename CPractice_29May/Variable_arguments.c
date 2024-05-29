#include <stdio.h>
#include <stdarg.h>
#include <limits.h>

int sum(int n, ...)
{
    int res=0;
    
    va_list ap;
    va_start(ap,n);
    
    for(int i=0;i<n;i++)
    {
        res+=va_arg(ap,int);
    }
    
    va_end(ap);
    return res;
}


int max(int n,...)
{
    int maxi=INT_MIN;
    
    va_list ap;
    va_start(ap,n);
    
    for(int i=0;i<n;i++)
    {
        int temp=va_arg(ap,int);
        maxi = (temp > maxi) ? temp : maxi; 
    }
    
    va_end(ap);
    return maxi;
}


int main()
{
    printf("Sum = %d\n",sum(3, 25,75,40));
    printf("Max = %d",max(4, 25,75,550,45));
    return 0;
}

