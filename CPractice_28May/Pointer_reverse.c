#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    printf("Enter how many int blocks: ");
    scanf("%d",&n);
    
    int *p=malloc(n*sizeof(int));
    
    if(p)
    {
        printf("Enter elements: \n");
        for(int i=0;i<n;i++)
        {
            //*(p+i)=i;  or  *(p+i)=i+1; 
            scanf("%d",(p+i));
        }
        
        p=p+n-1;
        printf("Numbers in reverse is:\n");
        for(int i=0;i<n;i++)
          printf("%d\t",*(p-i));  // *(p+(i-1))
          
        p=p-n+1;
        free(p);
        p=NULL;
        return 0;
    }
    
   else
   {
     printf("\nMemory allocation failed - not enough memory.\n");
     return 1;
   }
}
