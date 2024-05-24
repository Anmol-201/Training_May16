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

 printf("Enter array elements: ");
 for(int i=0;i<n;i++)
   scanf("%d",&arr[i]);

 for(int i=0;i<n-1;i++)
 {
   for(int j=0;j<n-i-1;j++) 
     {
       if(arr[j]>arr[j+1])
       {
         int temp=arr[j];
	 arr[j]=arr[j+1];
	 arr[j+1]=temp;
       }
     }
 }

 printf("Sorted Array elements are:\n");
 for(int i=0;i<n;i++)
   printf("%d\t",arr[i]);
 

}

