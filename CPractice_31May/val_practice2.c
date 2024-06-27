#include<stdio.h>
#include<stdlib.h>

int main(){

int *arr=(int *)malloc(10*sizeof(int));

printf("\nValue at base : %d",*arr);
printf("\n value of aout of block address: %d",arr[10]);


return EXIT_SUCCESS;
}
