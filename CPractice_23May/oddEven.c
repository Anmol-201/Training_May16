/*
Author : Anmol Biswas
Odd Even Number
DOC : 23rd May 2024
*/


#include <stdio.h>

int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d",&num);
    if(num&1)
      printf("Odd Number");
    else
      printf("Even Number");
    
    return 0;
}

