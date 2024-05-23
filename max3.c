/*
Author : Anmol Biswas
BMI calculator
DOC : 23rd May 2024
*/

#include <stdio.h>

int main()
{
    int a,b,c;
    printf("Enter 3 numbers: ");
    scanf("%d %d %d",&a,&b,&c);
    (a>b) ? ((a>c) ? printf("Largest is %d",a) : printf("Largest is %d",c)) : ((b>c) ? printf("Largest is %d",b) : printf("Largest is %d",c));

    return 0;
}

