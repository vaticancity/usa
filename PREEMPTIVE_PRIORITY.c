#include<stdio.h>
#include<stdlib.h>

struct process
{

    int PID;
    int AT;
    int BT;
    int CT;
    int PRIORITY;
    int WT;
    int TAT;
    int ST;
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
        printf("enter the PID,AT,BT,PRIORITY for process %d: ",i+1);
        scanf("%d %d %d %d",&p[i].PID,&p[i].AT,&p[i].BT,&p[i].PRIORITY);
        p[i].RBT=p[i].BT;
    }

    int completed=0;
    int current_time=0;
    int is_completed[pno];
    for(int i=0;i<pno;i++)
    {
        is_completed[i]=0;
    }

    while(completed!=pno)
    {   
        int index=-1,min=999;
        for(int i=0;i<pno;i++)
        {
            if(p[i].AT<=current_time && is_completed[i]==0)
            {
                if(p[i].PRIORITY < min)
                {
                    min=p[i].PRIORITY;
                    index=i;
                }
                if(p[i].PRIORITY==min)
                {
                    if(p[i].AT == p[index].AT)
                    {   
                        if(p[i].RBT==p[index].RBT)
                        {
                            min=p[i].PRIORITY;
                            index=i;

                        }
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
            p[index].RBT = p[index].RBT-1;
            current_time++;
            if(p[index].RBT==0)
            {
                p[index].CT=current_time;
                p[index].TAT=p[index].CT-p[index].AT;
                p[index].WT=p[index].TAT-p[index].BT;
                completed++;
                is_completed[index]=1;
            }
        }
        else
        {
            current_time++;
        }
    }
    float avg_tat=0;
    float avg_wt=0;

    for(int j=0;j<pno;j++)
    {
         avg_tat+=p[j].TAT;
         avg_wt+=p[j].WT;
    }
    avg_tat = avg_tat/pno;
    avg_wt = avg_wt/pno;


    printf("PID\tAT\tBT\tP\tCT\tTAT\tWT\tST\n");
    for(int i=0;i<pno;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].PID,p[i].AT,p[i].BT,p[i].PRIORITY,p[i].CT,p[i].TAT,p[i].WT,p[i].ST);

    }
    printf("\nAVG WT:%f\nAVG TAT:%f",avg_wt,avg_tat);


}