#include <stdio.h>
#define MAX 100

int main()
{
    int arr[MAX];
    int n;
    printf("Enter array 1 size: ");
    scanf("%d",&n);
    
    printf("Enter array 1 elements: \n");
    for(int i=0;i<n;i++)
    scanf("%d", &arr[i]);
    
    int k;
    printf("Enter k value: ");
    scanf("%d",&k);
    k=k%n;
    
    //Reversing whole array
    int i=0;
    int j=n-1;
    while(i<=j)
    {
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        
        i++;j--;
    }
    
    //reversing first k elements
    i=0;
    j=k-1;
    while(i<=j)
    {
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        
        i++;j--;
    }
    
    //reversing rest elements
    i=k;
    j=n-1;
    while(i<=j)
    {
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        
        i++;j--;
    }
    
    printf("Rotated array is: \n");
    for(int p=0;p<n;p++)
     printf("%d\t",arr[p]);
    
    return 0;
}

