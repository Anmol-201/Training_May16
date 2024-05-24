/*
Author : Anmol Biswas
Closest perfect square integer
DOC : 24th May 2024
*/

#include<stdio.h>
#include<math.h>
#include<limits.h>
#define MAXSIZE 100

int main()
{
int num;
printf("Enter your number: ");
scanf("%d",&num);

double root=sqrt(num);
int up=ceil(root);
int diff=INT_MAX;
int ans=0;
for(int i=up-1;i<=up;i++)
{
  int res=abs(num-i*i);
  if(res<diff)
  {
  diff=res;
  ans=i;
  }
}

printf("Closest perfect square integer is: %d",ans*ans);

return 0;
}

