#include <stdio.h>
struct Date
 {
   unsigned int Day : 5;
   unsigned int Month : 4;
   int Year: 12;
 };

int main()
{
  struct Date c = {01, 05, 2022};
  printf("The date is %d / %d / %d\n", c.Day, c.Month,c.Year);
  printf("The size of Date is %ld bytes.\n", sizeof(c));
  return 0;
}
