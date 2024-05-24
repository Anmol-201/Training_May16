/*
Author : Anmol Biswas
Remove repeating elements in Array
DOC : 24th May 2024
*/

#include<stdio.h>
#define MAXSIZE 100

int main()
{
int n;
int arr[MAXSIZE];
printf("Enter array size:");
scanf("%d",&n);

printf("Enter Array Elements:");
for(int i=0;i<n;i++)
 scanf("%d",&arr[i]);

for(int i=0;i<n-1;i++)
{
  for(int j=i+1;j<n;j++)
  {
    if(arr[j]!=-1 && arr[i]==arr[j])
	    arr[j]=-1;
  }
}

int ans[MAXSIZE];
int k=0;
for(int i=0;i<n;i++)
{
 if(arr[i]!=-1)
 {
   ans[k]=arr[i];
   k++;
 }
}

printf("Array after removing elements are:\n");
for(int i=0;i<k;i++)
{
 printf("%d\t",ans[i]);
}

return 0;
}


