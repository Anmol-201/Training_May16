/*
Author : Anmol Biswas
Minimum of two numbers
DOC : 23rd May 2024
*/

#include <stdio.h>

int main()
{
  int a,b;
  char ch;
  
  printf("Enter 2 numbers: ");
  scanf("%d %d",&a,&b);

 while ((getchar()) != '\n');
  printf("Enter choice of Operation:");

  scanf("%c",&ch);
  if(ch=='+')
   printf("%d",a+b);
  else if(ch=='-')
   printf("%d",a-b);
  else if(ch=='*')
          printf("%d",a*b);
  else if(ch=='/')
          printf("%d",a/b);
  else
          printf("Enter a Valid character");
  return 0;
}

