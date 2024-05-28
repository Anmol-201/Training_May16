#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Sales{
  char P_id[100];
  int rate;
  int flag;
};

int main()
{
    int n;
    printf("Enter sales count: ");
    scanf("%d",&n);
    getchar();
    
    struct Sales s1[n] ,temp[n];
    
    printf("Enter Product_Id - Sales_amount\n");
    for(int i=0;i<n;i++)
        {
            char str[100];
            char *token;
            scanf(" %[^\n]",str);
            token=strtok(str,"-");
            
            strcpy(s1[i].P_id,token);
            token=strtok(NULL," ");
            s1[i].rate=atoi(token);
            s1[i].flag=0;
        }
        
    
    int k=0;
    for(int i=0;i<n;i++)
    {
        if(s1[i].flag!=-1)
        {
           strcpy(temp[k].P_id,s1[i].P_id);
           temp[k].rate=s1[i].rate;  
           
           for(int j=i+1;j<n;j++)
            {
                if(strcmp(s1[i].P_id,s1[j].P_id)==0)
                {
                    temp[k].rate = (temp[k].rate > s1[j].rate) ? temp[k].rate : s1[j].rate; 
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
            if(temp[j].rate < temp[j+1].rate)
            {
                int temp_rate;
                char temp_Pid[100];
                
                temp_rate= temp[j].rate;
                strcpy(temp_Pid,temp[j].P_id);
                
                temp[j].rate=temp[j+1].rate;
                strcpy(temp[j].P_id,temp[j+1].P_id);
                
                temp[j+1].rate=temp_rate;
                strcpy(temp[j+1].P_id,temp_Pid);
            }
        }
    }
    
    printf("\nProduct_ID-Total_sales_amount\n");
    for(int i=0;i<k;i++)
    printf("%s-%d\n",temp[i].P_id, temp[i].rate);
    
    
  return 0;  
}
