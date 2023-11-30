#include<stdio.h>
#include<stdlib.h>
void accept_matrx(int pno,int res,int M[pno][res])
{
    for(int i=0;i<pno;i++)
    {
        for(int j=0;j<res;j++)
        {
            scanf("%d",&M[i][j]);
        }
    }
    
}
void display_matrix(int pno,int res,int M[pno][res])
{
     for(int i=0;i<pno;i++)
    {
        for(int j=0;j<res;j++)
        {
            printf("%d ",M[i][j]);
        }
        printf("\n");
    }
}
int main()
{
     int pno,res,flag=0;
    printf("Enter the number of processes: ");
    scanf("%d",&pno);

    printf("Enter the number of resources required: ");
    scanf("%d",&res);

    int ALLLOCATION[pno][res];
    int MAXIMUM[pno][res];
    int NEEDED[pno][res];
    int AVAILABLE[res];
    int is_completed[pno];
    int safe_seq[pno];
    int completed=0;

    for(int k=0;k<pno;k++)
    {
        is_completed[k]=0;
    }

    printf("enter the allocation matrix: \n");
    accept_matrx(pno,res,ALLLOCATION);
    printf("enter the Maximum needed matrix: \n");
    accept_matrx(pno,res,MAXIMUM);
    
    printf("enter the available resources first\n");
    for(int i=0;i<res;i++)
    {
        scanf("%d",&AVAILABLE[i]);
    }

    for(int i=0;i<pno;i++)
    {
        for(int j=0;j<res;j++)
        {
            NEEDED[i][j]=MAXIMUM[i][j]-ALLLOCATION[i][j];
        }
    }

    for(int a=0;a<pno;a++)
    {
        for(int i=0;i<pno;i++)
        {   
            flag=0;
            if(is_completed[i]==0)
            {
                for(int j=0;j<res;j++)
                {
                    if(NEEDED[i][j] > AVAILABLE[j])
                    {
                        flag=1;
                        break;
                    }
                }
            }
            if(flag==0)
            {   
                safe_seq[completed]=i+1;
                completed++;
                is_completed[i]=1;
                for(int k=0;k<pno;k++)
                {
                    AVAILABLE[k]+=ALLLOCATION[i][k];
                }

            }
          
        }
    }
    printf("safe sequence is : ");
    int deadlock=0;
    for(int u=0;u<pno;u++)
    {
        if(is_completed[u]==0)
        {
            deadlock=1;
            printf("process is in deadlock!");
            break;
        }
        if(deadlock==0)
        {
            printf("%d ",safe_seq[u]);
        }
    }
}