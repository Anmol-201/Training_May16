/*
Author : Anmol Biswas
Binary search
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

 printf("Enter Sorted array elements: ");
 for(int i=0;i<n;i++)
   scanf("%d",&arr[i]);

 int target;
 printf("Enter target element: ");
 scanf("%d",&target);

 int low=0, high=n-1;
 int flag=0;
 while(low<=high)
 {
   int mid=(low+high)/2;
   if(arr[mid]==target)
     {
	   printf("Element found at: %d position",mid);
	   flag=1;
	   break;
     }   
   else if(arr[mid]<target)
	   low=mid+1;
   else
	   high=mid-1;

 }

 if(!flag)
 printf("Element not found");

}



