#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Sales{
  char S_id[100];
  float score;
  int flag;
};


int main()
{
    int n;
    printf("Enter student count: ");
    scanf("%d",&n);
    
    struct Sales s1[n] ,temp[n];
    
    printf("Enter Student Id-Student Score\n");
    for(int i=0;i<n;i++)
    {
        char str[100];
        char *token;
        scanf(" %[^\n]",str);
        token=strtok(str,"-");
        
        strcpy(s1[i].S_id,token);
        token=strtok(NULL," ");
        s1[i].score=atof(token);
        s1[i].flag=0;
    }
    
    
    int k=0;
    for(int i=0;i<n;i++)
    {
        if(s1[i].flag!=-1)
        {
           strcpy(temp[k].S_id,s1[i].S_id);
           temp[k].score=s1[i].score;
           
           int count=1;
           for(int j=i+1;j<n;j++)
            {
              if(strcmp(s1[i].S_id,s1[j].S_id)==0)
                {
                    count++;
                    temp[k].score += s1[j].score; 
                    s1[j].flag=-1;
                }
            }
            temp[k].score/=count;
            k++;
        }
    }

    
    for(int i=0;i<k-1;i++)
    {
        for(int j=0;j<k-i-1;j++)
        {
            if(temp[j].score < temp[j+1].score)
            {
                int temp_score;
                char temp_Sid[100];
                
                temp_score= temp[j].score;
                strcpy(temp_Sid,temp[j].S_id);
                
                temp[j].score=temp[j+1].score;
                strcpy(temp[j].S_id,temp[j+1].S_id);
                
                temp[j+1].score=temp_score;
                strcpy(temp[j+1].S_id,temp_Sid);
            }
        }
    }
    
    printf("\nStudent_ID-Score\n");
    for(int i=0;i<k;i++)
    printf("%s-%.2f\n",temp[i].S_id, temp[i].score);
    
    
  return 0;  
}
