/*
Author : Anmol Biswas
Sum of digits of number
DOC : 23rd May 2024
*/


#include<stdio.h>

int main()
{
  int num;
  printf("Enter a number:");
  scanf("%d",&num);

  int sum=0;
  while(num)
   {
     sum+=num%10;
     num/=10;
   }

  printf("Sum of digits: %d",sum);

  return 0;
}

