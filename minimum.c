/*
Author : Anmol Biswas
Minimum of two numbers
DOC : 23rd May 2024
*/

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
int a,b;
printf("Enter two numbers: ");
scanf("%d %d",&a,&b);

(a<b)?printf("Minimum Number is: %d",a) : printf("Minimum Number is: %d",b);

return 0;
}


