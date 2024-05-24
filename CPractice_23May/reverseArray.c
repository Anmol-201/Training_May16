/*
Author : Anmol Biswas
Reversing array
DOC : 24th May 2024
*/

#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

int main()
{
  int n;
  int arr[MAXSIZE];
  printf("Enter array size: ");
  scanf("%d",&n);
  
  printf("Enter Array elements: ");
  for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);

  //Reversing in arr itself
  for(int i=n-1;i>n/2;i--)
  {
	  int temp=arr[i];
          arr[i]=arr[n-i+1];
	  arr[n-i+1]=temp;
  }

  printf("Reversed array elements are:\n ");
  for(int i=0;i<n;i++)
	  printf("%d\t",arr[i]);

  return EXIT_SUCCESS;

}


