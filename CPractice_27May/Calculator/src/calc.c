#include<stdio.h>
#include<stdlib.h>

int main()
{
int a,b;
printf("Enter two numbers: ");
scanf("%d%d",&a,&b);

char ch;
printf("Enter a operation:");
scanf(" %ch",&ch);

switch(ch)
{
  case '+': printf("Sum is: %d",sum(a,b));
            break;
  case '-': printf("Sub  is: %d",sub(a,b));
            break;

  case '*': printf("Mul is: %d",mul(a,b));
            break;

  case '/': printf("Division is: %d",div(a,b));
            break;
  default: printf("Enter a valid character");

}

  return 0;
}

