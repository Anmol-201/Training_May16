#include <stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXSIZE 3

#define SUCCESS 0
#define FAILURE 1

static int counter=0;

typedef struct Node
{
    int data;
    struct Node *next;
}Node;



int push(Node **top,int data)
{
    if(counter==MAXSIZE)
    {
        printf("Stack overflow!");
        return FAILURE;
    }
    
    Node *new=(Node*)malloc(sizeof(Node));
    new->data=data; 
    
    if(new==NULL)
    {
        printf("Error while creating node");
        return FAILURE;
    }
    
    if((*top)==NULL)
    {
        (*top)=new;
        (*top)->next=NULL;
        counter++;
        return SUCCESS;
    }
    
    new->next=*top;
    *top=new;
    counter++;
    
    return SUCCESS;
}




int pop(Node **top)
{
    if(counter==0)
    {
         printf("Stack underflow!");
         return FAILURE;
    }
    
    if(counter==1)
    {
        free(*top);
        *top=NULL;
        counter--;
        return SUCCESS;
    }
    
    Node *temp=*top;
    *top=temp->next;
    printf("%d",temp->data);
    free(temp);
    counter--;
    
    return SUCCESS;
}


void myfflush(void)
{
    while('\n' != getchar());
}

void display_stack(Node *top)
{
    if (top==NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    
    printf("\tElements in Stack are:\n");
    while(top!=NULL)
    {
        printf("\t%d\n",top->data);
        top=top->next;
    }
}




int main(int argc, char *argv[])
{
    Node *top=NULL;

    while(1)
    {
        
        system("clear");
        int choice=0;
        int data;

        printf("\n**************Stack Operation******************\n\n");
        printf("\t1. Push\n");
        printf("\t2. Pop\n");
        printf("\t3. Display Stack\n");
        printf("\t4. Exit\n\n");
        printf("\tEnter your choice: ");
        scanf("%d", &choice);
        myfflush();

        switch(choice)
        {
            case 1:
                if(counter==MAXSIZE)
                {
                    printf("Stack overflow!");
                    break;
                }
                else 
                {
                printf("\tEnter data: ");
                scanf("%d",&data);
                if(push(&top,data)==SUCCESS)
                    printf("Inserted successfully\n");
                }
                break;

            case 2:
                pop(&top);
                break;
                
            case 3:
                display_stack(top);
                break;

            case 4:
                printf("\texited\n");
                return SUCCESS;
                break;
                
            default:
                printf("\twrong choice, try again\n");
                break;
        }
        printf("\n\tpress enter to continue...");
        myfflush();
    }
    return SUCCESS;
}

