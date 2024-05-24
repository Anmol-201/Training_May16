/*
Author : Anmol Biswas
Binary to Decimal
DOC : 23rd May 2024
*/


#include <stdio.h>

int main()
{
   char str[33];
   printf("Enter a binary number: ");
   scanf("%s",&str); 
   
   char ch=str[0];
   int i=0;
   int num=0;

   while(ch!='\0')
   {
     num=num*2 + (str[i]-'0');
     i++;
     ch=str[i];
   }

   printf("Decimal number is: %d",num);
   
    return 0;
}
