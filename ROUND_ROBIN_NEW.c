#include<stdio.h>
#include<stdlib.h>

struct process
{
    int PID;
    int AT;
    int BT;
    int CT;
    int ST;
    int TAT;
    int WT;
    int RBT;
    
};
int main()
{
    int pno;
    printf("enter the number of processes: ");
    scanf("%d",&pno);

    struct process p[pno];
    for(int i=0;i<pno;i++)
    {
        printf("enter PID,AT,BT for process %d :",i+1);
        scanf("%d %d %d",&p[i].PID,&p[i].AT,&p[i].BT);
        p[i].RBT=p[i].BT;
    }
    printf("enter the time quantum:");
    int tq;
    scanf("%d",&tq);

    int completed=0;
    int current_time=0;
    int is_completed[pno];
    for(int k=0;k<pno;k++)
    {
        is_completed[k]=0;
    }

    while(completed!=pno)
    {
        for(int i=0;i<pno;i++)
        {
            
            
                if(p[i].AT<=current_time && p[i].RBT>0)
                {
                    if(p[i].RBT<=tq)
                    {
                        p[i].ST=current_time;
                        p[i].CT=p[i].ST+p[i].RBT;
                        p[i].TAT=p[i].CT-p[i].AT;
                        p[i].WT=p[i].TAT-p[i].BT;
                        p[i].RBT=0;
                        current_time=p[i].CT;
                        completed++;
                    }
                    else
                    {
                        p[i].ST=current_time;
                        current_time=current_time+tq;
                        p[i].RBT-=tq;
                    }
                }
            
        }
    }
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < pno; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].PID, p[i].AT, p[i].BT, p[i].CT, p[i].TAT, p[i].WT);
    }

}