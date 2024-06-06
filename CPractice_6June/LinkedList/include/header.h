#ifndef __HEADER__
#define __HEADER__

#include <stdio.h>
#include<string.h>
#include<stdlib.h>

#define SIZE 25

#define SUCCESS 0
#define FAILURE 1

typedef struct Node
{
    char *str;
    struct Node *next;
}Node;

extern void myfflush(void);
extern void get_string_input(char *);


extern int insert_at_beg(Node **, char *);
extern int insert_in_middle(Node **, char *, char * after);
extern int insert_at_end(Node **, char *);

extern int delete_at_beg(Node **);
extern int delete_in_middle(Node **, char *str);
extern int delete_at_end(Node **);

extern void display_list(Node *);
extern void free_list(Node **);


#endif

