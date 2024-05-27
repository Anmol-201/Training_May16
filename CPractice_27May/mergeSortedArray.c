#include <stdio.h>
#define MAX 100

int main()
{
    int arr1[MAX], arr2[MAX];
    int n,m;
    printf("Enter array 1 size: ");
    scanf("%d",&n);
    printf("Enter array 2 size: ");
    scanf("%d",&m);
    
    printf("Enter sorted array 1 elements: \n");
    for(int i=0;i<n;i++)
    scanf("%d", &arr1[i]);
    
    printf("Enter sorted array 2 elements: \n");
    for(int i=0;i<m;i++)
    scanf("%d", &arr2[i]);
    
    int k=n+m-1;
    int arr3[MAX];
    
    int i=n-1;
    int j=m-1;
    
    while(i>=0 && j>=0)
    {
        if(arr1[i]>arr2[j])
        {
            arr3[k]=arr1[i];
            i--;
            k--;
        }
        else
        {
            arr3[k]=arr2[j];
            j--;
            k--;
        }
    }
    
    while(i>-1)
    {
        arr3[k]=arr1[i];
        i--;
        k--;
    }
    while(j>-1)
    {
        arr3[k]=arr2[j];
        j--;
        k--;
    }
    
    printf("Merged sorted array is: \n");
    for(int p=0;p<n+m;p++)
      printf("%d\t",arr3[p]);
    return 0;
}

