#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 25

int top=-1;

void push(int arr[],int data)
{
    if(top==MAXSIZE-1)
    {
        printf("Stack overflow!");
        return;
    }
    
    top++;
    arr[top]=data;
}


int pop(int arr[])
{
    if(top==-1)
    {
        printf("Stack underflow!");
        return -1;
    }
    
    int temp=arr[top];
    top--;
    
    return temp;
}


int main()
{
    
    int stack[MAXSIZE];
   
    
    push(stack,40);
    push(stack,50);
    push(stack,70);
    push(stack,80);
    printf("%d ",pop(stack));
    printf("%d ",pop(stack));
    printf("%d ",pop(stack));
    push(stack,100);
    printf("%d ",pop(stack));
    return 0;
}

