/*
Author : Anmol Biswas
BMI calculator
DOC : 23rd May 2024
*/

#include<stdio.h>
#define MAXSIZE 100

int main()
{
 int n;
 int arr[MAXSIZE];
 printf("Enter array size: ");
 scanf("%d",&n);

 printf("Enter array elements: ");
 for(int i=0;i<n;i++)
   scanf("%d",&arr[i]);
 
 printf("Array elemenets are: \n");
 for(int i=0;i<n;i++)
   printf("%d\t",arr[i]);
 
}


