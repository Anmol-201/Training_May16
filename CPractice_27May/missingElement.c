#include<stdio.h>

#define MAX 100


int main()
{

	int arr[MAX];
	int n;
	printf("Enter array size: ");
	scanf("%d",&n);
	
	printf("Enter array elemets: ");
	for(int i=0;i<n;i++)
	scanf("%d",&arr[i]);

	int sum=0;
	for(int i=0;i<n;i++)
	sum+=arr[i];
	
        n=n+1;
        int missing=(n*(n+1))/2 - sum;	
	printf("Missing number is: %d",missing);

	return 0;
}
