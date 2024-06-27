#include <header.h>

int main(int argc, char *argv[])
{
    Node *head = NULL;

    while (1)
    {

        system("clear");
        int choice = 0;
        char str[SIZE];
        char after[SIZE];

        memset(str, 0, SIZE);
        memset(after, 0, SIZE);

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
                printf("\tenter string: ");
                get_string_input(str);
                if (SUCCESS == insert_at_beg(&head, str))
                {
                    printf("\tInserted Successfully\n");
                }
                break;

            case 2:
                printf("\tenter string: ");
                get_string_input(str);
                printf("\tenter string after which you want to insert: ");
                get_string_input(after);
                if (SUCCESS == insert_in_middle(&head, str, after))
                {
                    printf("\tInserted Successfully\n");
                }
                break;

            case 3:
                printf("\tenter string: ");
                get_string_input(str);
                if (SUCCESS == insert_at_end(&head, str))
                {
                    printf("\tInserted Successfully\n");
                }
                break;

            case 4:
                if (SUCCESS == delete_at_beg(&head))
                {
                    printf("\tDeleted Successfully\n");
                }
                break;

            case 5:
                printf("\tenter string which you want to delete: ");
                get_string_input(str);
                if (SUCCESS == delete_in_middle(&head, str))
                {
                    printf("\tDeleted Successfully\n");
                }
                break;

            case 6:
                if (SUCCESS == delete_at_end(&head))
                {
                    printf("\tDeleted Successfully\n");
                }
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

//	free(head);


    return SUCCESS;
}


