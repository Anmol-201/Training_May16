/*
Author : Anmol Biswas
Armstrong number
DOC : 24th May 2024
*/

#include<stdio.h>
#include<math.h>

int powr(int x,int y)
{
	int res=1;
	while(y--)
	{
	   res=res*x;
	}

	return res;
}

int main()
{
  int num;
  printf("Enter a number:");
  scanf("%d",&num);

  int num1=num;
  int len=0;
  while(num)
  {
   len++;
   num/=10;
  }

  int arm=0;
  int k=len;
  int num2=num1;

  while(k--)
  {
    arm+=powr(num1%10,len);
    num1/=10;
  }

  int arm1=(int)arm;
  if(arm1==num2)
          printf("ARMSTRONG NUMBER!");
  else
          printf("Not a armstrong number");

  return 0;
}


