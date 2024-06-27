#include<stdio.h>
#include<stdlib.h>

int main()
{
int *p=(int *)calloc(10,sizeof(int));
printf("Address of p is: %p\t",p);

free(p);
int *x;
p=x;
printf("Address of p is: %p\t",p);
printf("Address of x is: %p\t",x);
p=NULL;

printf("Address of p ifter null is: %p\t",p);


return EXIT_SUCCESS;
}
