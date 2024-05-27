#include <stdio.h>
#define MAX 100

int main()
{
    int arr1[MAX], arr2[MAX];
    int n,m;
    int freq[1000]={0};
    printf("Enter array 1 size: ");
    scanf("%d",&n);
    printf("Enter array 2 size: ");
    scanf("%d",&m);
    
    printf("Enter array 1 elements: \n");
    for(int i=0;i<n;i++)
    scanf("%d", &arr1[i]);
    
    printf("Enter array 2 elements: \n");
    for(int i=0;i<m;i++)
    scanf("%d", &arr2[i]);
    
    printf("Common elements are: \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr1[i]==arr2[j])
               printf("%d\t",arr1[i]);
        }
    }
    
    return 0;
}


