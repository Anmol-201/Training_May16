#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#define MAX  6
#define SIZE 3

int main()
{
  FILE* infile = NULL; /* File pointer */
  char *input[SIZE] = {"PRISM\n", "Nalandafum\n", "Aricentoni\n"};
  char output[MAX];
  int fputs_ret = 0; /* Return value from fputs */
  int fclose_ret = 0; /* Return value from fclose */
  int index = 0; /* for loop index */
  char *temp;
  memset(output, 0, MAX); /* Initializing the array */
  infile = fopen("sample.txt", "w");
  if(NULL == infile) /* Error check for fopen */
  {
    printf("File can not be opened\n");
    return 0;
  }

  for(index = 0; index < SIZE; index += 1)
  {
   fputs_ret = fputs(input[index], infile);
   if(EOF == fputs_ret) /* Error check for fputs */
   {
    printf("Error in fputs\n");
    fclose_ret = fclose(infile); /* Closing the file */
    if(0 != fclose_ret) /* Error check for fclose */
    {
     printf("Error in fclose\n");
     return 0;
    }
    return 0;
   }
  }

  fclose_ret = fclose(infile);
  if(0 != fclose_ret) /* Error check for fclose */
  {
   printf("Error in fclose\n");
   return 0;
  }

  infile = fopen("sample.txt", "r");
  if(NULL == infile) /* Error check for fopen */
  {
    printf("File can not be opened\n");
    return 0;
  }

  while(!feof(infile))
  {
    temp = fgets(output, MAX, infile);
    if(*temp=='\n')
        *temp= '\0';    
    
    if(temp!=NULL)
     {
      int x=strlen(output);
      
       printf("%s\n", output);
       printf("%d\n",x);
     }
  }
  
  
  fclose_ret = fclose(infile);
  if(0 != fclose_ret) /* Error check for fclose */
  {
   printf("Error in fclose\n");
   return 0;
  }
  return 0;
 }
