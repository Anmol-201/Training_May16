#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0


typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}Node;


Node* create_node(int data)
{
    Node *new=(Node*)malloc(sizeof(Node));
    new->data=data;
    new->left=NULL;
    new->right=NULL;
    
    return new;
}


Node* insert(Node **root,int data)
{
    if((*root)==NULL)
    {
        return create_node(data);
    }
    else
    {
        if(data < (*root)->data)
            (*root)->left=insert((&(*root)->left),data);
        else
            (*root)->right=insert(&((*root)->right),data);
    }
    
    return (*root);
}


void inorder(Node *root)
{
	if(root==NULL)
		return;
        
	inorder(root->left);
	printf("%d->",root->data);
	inorder(root->right);
}


void preorder(Node *root)
{
	if(root==NULL)
		return;
        
	printf("%d->",root->data);
	preorder(root->left);
	preorder(root->right);
}


void postorder(Node *root)
{
	if(root==NULL)
		return;
        
	postorder(root->left);
	postorder(root->right);
	printf("%d->",root->data);
}


Node* findleft(Node *temp)  // In-Predecessor (largest in left sub-tree)
{
    while(temp->right)
    temp=temp->right;
    
    return temp;
}
Node* findright(Node *temp)  // In-Successor (smallest in right sub-tree)
{
    while(temp->left)
    temp=temp->left;
    
    return temp;
}


void delete_node(Node** root, int val) {
    if (*root == NULL)
    {
        printf("Empty tree");
        return;
    } 
    else if (val < (*root)->data) 
        delete_node(&((*root)->left), val);
        
    else if (val > (*root)->data)
        delete_node(&((*root)->right), val);
    
    else
    {
        if ((*root)->left == NULL)
        {
            
            // Case 1 : No child
            Node* temp = (*root)->right;
            free(*root);
            *root = temp;
            
        // Case 2 : 1 child      
        } 
        else if ((*root)->right == NULL)
        {
            Node* temp = (*root)->left;
            free(*root);
            *root = temp;
        } 
        else
        {
            // Case 3: Node with two children
            Node* temp = findleft((*root)->left); // In-order predecessor
            (*root)->data = temp->data;
            delete_node(&((*root)->left), temp->data);
        }
    }
}


int main()
{
    Node *root=NULL;
    int choice;
        int item;
        do
        {
                printf("\n\n1: Insert an element in the tree");
                printf("\n2: Display inorder traversal ");
                printf("\n3: Delete a node from tree ");
                printf("\n4: Display preorder traversal ");
                printf("\n5: Display postorder traversal ");
                printf("\n6: exit\n");
                scanf("\n%d",&choice);
                switch(choice)
                {
                        case 1: {
                                   printf("\nEnter a node to be inserted ");
                                   scanf("%d",&item);
                                   
                                   root=insert(&root,item);
                                   printf("%d",item);
                                   break;
                                }
                                
                        case 2: {
                                  inorder(root);
                                  break;
                                }
                                
                        case 3: {
                                   printf("\nEnter a node to be deleted ");
                                   scanf("%d",&item);
                                   delete_node(&root,item);
                                   break;
                                }
                                
                        case 4: {
                                  preorder(root);
                                  break;
                                }
                                
                        case 5: {
                                  postorder(root);
                                  break;
                                }
                }
        }while(choice!=6);


    return 0;
}


