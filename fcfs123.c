#include<stdio.h>
#include<stdlib.h>

struct process
{
    int PID;
    int AT;
    int BT;
    int CT;
    int ST;
    int WT;
    int TAT;

};
int main()
{   
    int pno;
    printf("enter the number of processes: ");
    scanf("%d",&pno);
    struct process p[pno];

    for(int i=0;i<pno;i++)
    {
        printf("enter the PID,AT,BT for process %d: ",i+1);
        scanf("%d %d %d",&p[i].PID,&p[i].AT,&p[i].BT);
    }

    for(int i=0;i<pno;i++)
    {
        for(int j=0;j<pno-i-1;j++)
        {
            if(p[j].AT>p[j+1].AT)
            {
                struct process temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }

    p[0].WT=0;
    p[0].CT=p[0].AT+p[0].BT;
    for(int k=1;k<pno;k++)
    {
        p[k].CT=p[k-1].CT+p[k].BT;
          
    }
    for(int i=0;i<pno;i++)
    {
        p[i].TAT=p[i].CT-p[i].AT;
        p[i].WT=p[i].TAT-p[i].BT;

    }
     printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < pno; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].PID, p[i].AT, p[i].BT, p[i].CT, p[i].TAT, p[i].WT);
    }
   
    
}