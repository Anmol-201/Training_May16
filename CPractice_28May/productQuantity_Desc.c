#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Sales{
  char P_id[100];
  int qty;
  int flag;
};


int main()
{
    int n;
    printf("Enter sales count: ");
    scanf("%d",&n);
    
    struct Sales s1[n] ,temp[n];
    
    printf("Enter Product_Id - Product Quantity\n");
    for(int i=0;i<n;i++)
    {
        char str[100];
        char *token;
        scanf(" %[^\n]",str);
        token=strtok(str,"-");
        
        strcpy(s1[i].P_id,token);
        token=strtok(NULL," ");
        s1[i].qty=atoi(token);
        s1[i].flag=0;
    }
        
    
    int k=0;
    for(int i=0;i<n;i++)
    {
        if(s1[i].flag!=-1)
        {
           strcpy(temp[k].P_id,s1[i].P_id);
           temp[k].qty=s1[i].qty;
           
           for(int j=i+1;j<n;j++)
            {
              if(strcmp(s1[i].P_id,s1[j].P_id)==0)
                {
                    temp[k].qty += s1[j].qty; 
                    s1[j].flag=-1;
                }
            }
            k++;
        }
    }

    
    for(int i=0;i<k-1;i++)
    {
        for(int j=0;j<k-i-1;j++)
        {
            if(temp[j].qty < temp[j+1].qty)
            {
                int temp_qty;
                char temp_Pid[100];
                
                temp_qty= temp[j].qty;
                strcpy(temp_Pid,temp[j].P_id);
                
                temp[j].qty=temp[j+1].qty;
                strcpy(temp[j].P_id,temp[j+1].P_id);
                
                temp[j+1].qty=temp_qty;
                strcpy(temp[j+1].P_id,temp_Pid);
            }
        }
    }
    
    printf("\nProduct_Id-Total_Quantity\n");
    for(int i=0;i<k;i++)
    printf("%s-%d\n",temp[i].P_id, temp[i].qty);
    
    
  return 0;  
}
