#include<stdio.h>
#include<stdlib.h>

typedef struct
 {
   char a;   // 1 byte
   int  b;   // 4 bytes
 } temp1;

typedef struct
{
  char a;   // 1 byte
  int  b;   // 4 bytes
  char c;   // 1 byte
} temp2;


typedef struct
{
  char a;   // 1 byte
  char c;   // 1 byte
  int  b;   // 4 bytes
 } temp3;
 
 
 
int main()
{
  printf("sizeof(structure temp) = %lu\n", sizeof(temp1));
  printf("sizeof(structure temp) = %lu\n", sizeof(temp2));
  printf("sizeof(structure temp) = %lu\n", sizeof(temp3));
  
  return 0;
}
