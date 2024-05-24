/*
Author : Anmol Biswas
Leaders in Array
DOC : 24th May 2024
*/

#include<stdio.h>
#define MAXSIZE 100
int main()
{
  int arr[MAXSIZE];
  int n;
  printf("Enter array size:");
  scanf("%d",&n);

  printf("Enter array elements:");
  for(int i=0;i<n;i++)
	  scanf("%d",&arr[i]);

  int leader=-1;
  for(int i=n-2;i>-1;i--)
  {
    if(arr[i]<arr[i+1])
    {
      leader=arr[i+1];
      break;
    }
  }

  printf("Leader in array is: %d",leader);

  return 0;
}

