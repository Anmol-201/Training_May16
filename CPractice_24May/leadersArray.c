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
  int k=0;
  int ans[MAXSIZE];

  for(int i=n-1;i>-1;i--)
  {
    if(arr[i]>leader)
    {
      ans[k]=arr[i];
      k++;
      leader=arr[i];
    }
  }

  printf("Leaders are:\n");
  for(int i=k-1;i>-1;i--)
    printf("%d\t",ans[i]);
  

  return 0;
}

