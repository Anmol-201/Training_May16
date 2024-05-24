/*
Author : Anmol Biswas
Celcius to Farenheit
DOC : 23rd May 2024
*/



#include <stdio.h>

int main()
{
    float cel;
    printf("Enter Temperature in Celcius: ");
    scanf("%f",&cel);
    printf("Temperature in Farenheit is: %fF", (cel * 9.0 / 5.0) + 32.0);   
    
    return 0;
}
