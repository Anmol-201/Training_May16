#include <stdio.h>
#define MAX 100

int main()
{
    int arr[MAX], cnt[MAX]={0};
    int n;
    printf("Enter array size: ");
    scanf("%d",&n);
    
    printf("Enter array elements: ");
    for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
    
    for(int i=0;i<n;i++)
        cnt[arr[i]]+=1;
    
    printf("Duplicate elements are: \n");
    for(int i=0;i<MAX;i++)
    {
        if(cnt[i]>1)
        printf("%d\t",i);
    }
    
    return 0;
}

