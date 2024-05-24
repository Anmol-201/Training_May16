/*
Author : Anmol Biswas
Automorphic Number
DOC : 24th May 2024
*/

#include<stdio.h>
#include<math.h>

int main()
{
  int num;
  printf("Enter a number: ");
  scanf("%d",&num);

  int num1=num;
  int sq=num*num;
  int len=0;
  while(num)
  {
    len++;
    num/=10;
  }
  
  int powr=1;
  while(len)
  {
   powr*=10;
   len--;
  }


  int last=sq % powr;
  if(last==num1)
          printf("It's an Automorphic Number!");

  else
          printf("It's not an  Automorphic Number!");


return 0;
}



