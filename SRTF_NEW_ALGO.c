#include<stdio.h>
#include<stdlib.h>

struct process
{
    int PID;
    int AT;
    int BT;
    int CT;
    int RBT;
    int ST;
    int TAT;
    int WT;
    
};
int main()
{
    int pno;
    printf("enter the number of processes: ");
    scanf("%d",&pno);

    struct process p[pno];
    int is_completed[pno];
    for(int k=0;k<pno;k++)
    {
        is_completed[k]=0;
    }
    
    for (int i=0;i<pno;i++)
    {
        printf("Enter the PID,AT,BT of Process %d: ",i+1);
        scanf("%d %d %d",&p[i].PID,&p[i].AT,&p[i].BT);
        p[i].RBT=p[i].BT;
    }
    int current_time=0;
    int completed=0;

    while (completed!=pno)
    {   
        int min=999,index=-1;
        for(int i=0;i<pno;i++)
        {
            if(p[i].AT<=current_time && is_completed[i]==0)
            {
                if(p[i].RBT<min)
                {
                    min=p[i].RBT;
                    index=i;
                }
                if(p[i].RBT==min)
                {
                    if(p[i].AT<p[index].AT)
                    {
                        min=p[i].RBT;
                        index=i;
                    }
                }
            }
        }
        if(index!=-1)
        {
            if(p[index].RBT==p[index].BT)
            {
                p[index].ST=current_time;
                
            }
            current_time++;
            p[index].RBT-=1;
            if(p[index].RBT==0)
            {
                p[index].CT=current_time;
                p[index].TAT=p[index].CT-p[index].AT;
                p[index].WT=p[index].TAT-p[index].BT;
                is_completed[index]=1;
                completed++;
            }
        }
        else
        {
            current_time++;
        }
    }
    printf("PID\tAT\tBT\tCT\tTAT\tWT\tST\n");
    for(int i=0;i<pno;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].PID,p[i].AT,p[i].BT,p[i].CT,p[i].TAT,p[i].WT,p[i].ST);
    }
    
}