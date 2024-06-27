#include<header.h>

void myfflush(void)
{
    while('\n' != getchar());
}

void get_string_input(char *input)
{
    while(1)
    {
        fgets(input,SIZE-1, stdin);
        int len = strlen(input);
        if(len == 1)
        {
            printf("\t Empty String, enter again:  ");
            memset(input, 0, SIZE);
            continue;
        }
        if(input[len-1] == '\n')
        {
            input[len-1] ='\0';
        }
        else
        {
            myfflush();
        }
        break;
    }
}

int create_node(Node **new_node, int data_len)
{
    *new_node = (Node *)malloc(sizeof(Node));
     if (NULL == *new_node)
     {
         perror("error while creating node");
         return FAILURE;
     }

    (*new_node)->str = (char *)calloc(data_len, sizeof(char));
    if (NULL == (*new_node)->str)
    {
         perror("error while creating node");
         return FAILURE;
     }

    (*new_node)->str = (char *)calloc(data_len, sizeof(char));
    if (NULL == (*new_node)->str)
    {
         perror("error while creating node, allocating memory for str");
         return FAILURE;

    }
    (*new_node)->next = NULL;
    return SUCCESS;
}

int insert_at_beg(Node **head, char *str)
{
    Node *new_node = NULL;
    if (FAILURE == create_node(&new_node, strlen(str) + 1))
    {
        return FAILURE;
    }
    strcpy(new_node->str, str);

    new_node->next = *head;
    *head = new_node;

    return SUCCESS;
}

int insert_in_middle(Node **head, char *str, char *after)
{
    Node *tmp = NULL;

    Node *new_node = NULL;
    if (FAILURE == create_node(&new_node, strlen(str) + 1))
    {
        return FAILURE;
    }
    strcpy(new_node->str, str);

    if(NULL == *head)
    {
        *head = new_node;
        return SUCCESS;
    }

    tmp = *head;

    while (NULL != tmp->next)
    {
        if(!strcmp(tmp->str, after))
        {
            new_node->next = tmp->next;
            tmp->next = new_node;
            return SUCCESS;
        }
        tmp = tmp->next;
    }

    tmp->next = new_node;

    return SUCCESS;
}

int insert_at_end(Node **head, char *str)
{
    Node *tmp = NULL;

    Node *new_node = NULL;
    if (FAILURE == create_node(&new_node, strlen(str) + 1))
    {
        return FAILURE;
    }
    strcpy(new_node->str, str);
    if(NULL == *head)
    {
        *head = new_node;
        return SUCCESS;
    }

    tmp = *head;

    while (NULL != tmp->next)
    {
        tmp = tmp->next;
    }

    tmp->next = new_node;

    return SUCCESS;
}
int delete_at_beg(Node **head)
{
    Node *tmp = *head;

    if(NULL == tmp)
    {
        printf("\tList is empty, deletion failed");
        return FAILURE;
    }

    *head = (*head)->next;
    free(tmp->str);
    free(tmp);
    return SUCCESS;
}

int delete_in_middle(Node **head, char *str)
{
    Node *tmp = *head;

    if(NULL == tmp)
    {
        printf("\tList is empty, deletion failed\n");
        return FAILURE;
    }
    else
    {
        if(!strcmp(tmp->str, str))
        {
            *head = tmp->next;
            free(tmp->str);
            free(tmp);
            return SUCCESS;
        }
    }

    if(NULL == tmp->next)
    {
        printf("\t\"%s\" does not exist in the list\n", str);
        return FAILURE;
    }

    do
    {
        if (!strcmp(tmp->next->str, str))
        {
            Node *free_node = tmp->next;
            tmp->next = tmp->next->next;
            free(free_node->str);
            free(free_node);
            return SUCCESS;
        }
        tmp = tmp->next;
    }while (NULL != tmp->next);

    printf("\t\"%s\" does not exist in the list\n", str);
    return FAILURE;
}

int delete_at_end(Node **head)
{
    Node *tmp = *head;

    if(NULL == tmp)
    {
        printf("\tList is empty, deletion failed\n");
        return FAILURE;
    }

    if(NULL == tmp->next)
    {
        free(tmp->str);
        free(tmp);
        *head = NULL;
        return SUCCESS;

    }

    while (NULL != tmp->next->next)
    {
        tmp = tmp->next;
    }

    Node *free_node = tmp->next;
    tmp->next = NULL;
    free(free_node->str);
    free(free_node);

    return SUCCESS;

}

void display_list(Node *head)
{
    if (NULL == head)
    {
        printf("\tList is empty\n");
        return;
    }
    else
    {
        printf("\tElements in list are:\n");
    }
    while(head != NULL)
    {
        printf("\t%s\n", head->str);
        head = head->next;
    }
}




/*
void free_list(Node **head)
{
    Node *tmp = *head;
    while (tmp != NULL)
    {
       Node *free_node = tmp;
       tmp = tmp->next;
       free(free_node->str);
       free(free_node);
    }
    *head = NULL;
}*/

void free_list(Node **head) {
    while (*head != NULL) {
        Node *free_node = *head;
        *head = (*head)->next;
        free(free_node->str);
        free(free_node);
    }
}


