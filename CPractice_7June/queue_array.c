#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
int queue[MAXSIZE];
int front=-1, rear=-1;

void enque(int data)
{
    if(rear==MAXSIZE)
    {
        printf("Queue is full!");
    }
    
    else if(front==-1 && rear==-1)
    {
        front=0;rear=0;
        queue[rear]=data;
    }
    else
    {
        rear=rear+1;
        queue[rear]=data;
    }
}



int dequeu()
{
    int data;
    
    if(front==rear)
    {
        printf("queue is empty!");
        exit(0);
    }
    else
    {
        data=queue[front];
        front=front+1;
    }
    return data;
}




int main()
{
    enque(2);
    enque(7);
    enque(8);
    enque(9);
    enque(5);
    enque(10);
    printf("%d\t",dequeu());
    printf("%d\t",dequeu());
    printf("%d\t",dequeu());
    printf("%d\t",dequeu());
    printf("%d\t",dequeu());
    printf("%d\t",dequeu());
    
        
    return 0;
}

