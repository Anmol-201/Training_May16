#include <stdio.h>
#include <stdlib.h>

int max(int a,int b)
{
    return (a>b) ? a : b;
}

int min(int a,int b)
{
    return (a<b) ? a : b;
}


int compare(int a,int b, int (*fp2) (int,int))
{
    int result=fp2(a,b);
    return result;
}


int sum(int a,int b)
{
    return a+b;
}



int main()
{
    int (*fp1) (int,int);
    fp1=sum;   //fp1=&sum;
    // int sum=fp1(20,30);   // =(*fp1) (10,20);
    
    // printf("Sum: %d",fp1(15,30));
    // printf("\nSum: %d",sum);
    
    //Funtion pointer as an argument
    int result=compare(20,35,max);
    printf("Compare: %d",result);
    
    return EXIT_SUCCESS;
}

