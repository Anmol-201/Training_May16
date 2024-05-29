#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
if(argc<4)
{
  printf("Too less arguments\n");
  return EXIT_FAILURE;
}

int val1=atoi(argv[1]);
int val2=atoi(argv[3]);
char ch=argv[2][0];

switch(ch)
{
	case '+': printf("Sum is: %d",val1+val2);
		  break;	
	case '-': printf("Diff is: %d",val1-val2);
		  break;	
	case '*': printf("Mul is: %d",val1*val2);
		  break;
	case '/': printf("Div is: %d",val1/val2);
		  break;
	default: printf("Invalid operator!");		  
}

EXIT_SUCCESS;
}
