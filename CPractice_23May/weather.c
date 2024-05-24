/*
Author : Anmol Biswas
Weather based comments
DOC : 23rd May 2024
*/


#include <stdio.h>

int main()
{
    int temp;
    printf("Enter Temperature: ");
    scanf("%d",&temp);
    
    if(temp>30)
    printf("It's hot outside, stay hydrated!");
    else if(temp>=20 && temp<30)
    printf("The weather is nice and warm.");
    else if(temp>=10 && temp<=19)
    printf("It's a bit chilly, wear a jacket.");
    else if(temp<10)
    printf("It's cold outside, stay warm!");
    
    return 0;
}

