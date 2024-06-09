#include <stdio.h>
#include<string.h>
#include<stdlib.h>

#define SIZE 25

#define SUCCESS 0
#define FAILURE 1

typedef struct Node
{
    int data;
    struct Node *next;
}Node;



void myfflush(void)
{
    while('\n' != getchar());
}




Node* create_node(int data)
{
    Node *new=(Node *)malloc(sizeof(Node));
    new->next=NULL;
    new->data=data;
    
    return new;
}




void insert_at_beg(Node **head, int data)
{
    Node *new=create_node(data);
    new->next=*head;
    *head=new;
    
    return;
}


//after a node
void insert_middle(Node **head, int data , int item)
{
    
    Node *new_node=create_node(data);
    if(*head==NULL)
    {
        *head=new_node;
        return;
    }
    
    if((*head)->data==item)
    {
        (*head)->next=new_node;
        return;
    }
    
    Node *temp=*head;
    while(temp)
    {
        if(temp->data==item)
        {
            new_node->next=temp->next;
            temp->next=new_node;
            return;
        }
        temp=temp->next;
    }
    
    printf("specified Node not in list: ");
    return;
}



void insert_end(Node **head, int data)
{
    Node *new=create_node(data);
    if(*head==NULL)
    {
        *head=new;
        return;
    }
    
    Node *p=*head;
    while(p->next)
    p=p->next;
    
    p->next=new;
    return;
}




void delete_begin(Node **head)
{
    if(*head==NULL)
    {
        printf("\tList is empty, deletion failed");
        return;
    }
    
    Node *temp=*head;
    *head=(*head)->next;
    free(temp);
    return;
}



void delete_middle(Node **head,int item)
{
    Node *temp = *head;
    if(*head==NULL)
    {
        printf("\tList is empty, deletion failed\n");
        return;
    }
    else
    {
        if(temp->data==item)
        {
            *head=temp->next;
            free(temp);
            return;
        }
    }


    if(temp->next==NULL)
    {
        printf("\t does not exist in the list\n");
        return;
    }

    Node *free_node=temp;
    temp=temp->next;
    while(temp->next)
    {
        if(temp->data==item)
        {
            free_node->next=temp->next;
            free(temp);
            return;
        }
        
        free_node=temp;
        temp=temp->next;
    }
    
    
    printf("\t does not exist in the list\n");
    return;
}



void delete_end(Node **head)
{
    if(*head==NULL)
    {
        printf("\tList is empty, deletion failed\n");
        return;
    }
    
    Node *temp=*head;
    if((*head)->next==NULL)
    {
        free(temp);
        *head=NULL;
        return;
    }
    
    
    while (temp->next->next)
        temp=temp->next;

    Node *free_node=temp->next;
    temp->next = NULL;
    free(free_node);

    return;
}



void display_list(Node *head)
{
    if (head==NULL)
    {
        printf("\tList is empty\n");
        return;
    }
    
    printf("\tElements in list are:\n");
    while(head!=NULL)
    {
        printf("\t%d\n",head->data);
        head=head->next;
    }
    return;
}


void free_list(Node **head)
{
    Node *temp = *head;
    while (temp != NULL)
    {
      Node *free_node = temp;
      temp = temp->next;
      free(free_node);
    }
    *head = NULL;
}





int main(int argc, char *argv[])
{
    Node *head=NULL;

    while (1)
    {

        system("clear");
        int choice = 0;
        int data, item;
        printf("\n**************Linked List Operation******************\n\n");
        printf("\t1. Insert at Beginning\n");
        printf("\t2. Insert after a Node\n");
        printf("\t3. Insert at End\n");
        printf("\t4. Delete at Beginning\n");
        printf("\t5. Delete a specified Node\n");
        printf("\t6. Delete at End\n");
        printf("\t7. Display\n");
        printf("\t8. Exit\n\n");
        printf("\tEnter your choice: ");
        scanf("%d", &choice);
        myfflush();

        switch(choice)
        {
            case 1:
                printf("\tenter Data: ");
                scanf("%d",&data);
                insert_at_beg(&head, data);
                break;

            case 2:
                printf("\tenter Data: ");
                scanf("%d",&data);
                printf("\n Enter element after: ");
                scanf("%d",&item);
                insert_middle(&head,data,item);
                break;
                
            case 3:
                printf("\tenter Data: ");
                scanf("%d",&data);
                insert_end(&head, data);
                break;


            case 4:
                delete_begin(&head);
                break;

            case 5:
                printf("\tenter Node which you want to delete: ");
                scanf("%d",&data);
                delete_middle(&head,data);
                break;

            case 6:
                delete_end(&head);
                break;

            case 7:
                display_list(head);
                break;
            case 8:
                free_list(&head);
                printf("\texited\n");
                return SUCCESS;
            default:
                printf("\twrong choice, try again\n");
                break;
        }
        printf("\n\tpress enter to continue...");
        myfflush();
    }
    return SUCCESS;
}


