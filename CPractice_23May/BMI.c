/*
Author : Anmol Biswas
BMI calculator
DOC : 23rd May 2024
*/

#include <stdio.h>

int main()
{
  float weight,height;
  printf("Enter your weight(Kg) and height(Meters): ");
  scanf("%f %f",&weight,&height);
  
  float bmi=weight/(height*height);
  
  if(bmi<18.5)
    printf("BMI is: %f Underweight",bmi);
else if(bmi>=18.5 && bmi<=24.9)
    printf("BMI is: %f Normal",bmi);
else if(bmi>=25.0 && bmi<=29.9)
    printf("BMI is: %f Overweight",bmi);
else if(bmi>=30.0)
    printf("BMI is: %f Obesity",bmi);
    
  return 0;
}


