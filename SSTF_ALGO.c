#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    printf("enter the number of requests: ");
    scanf("%d",&n);

    int head,flag=0,dist=0;
    int req[n];
    int is_completed[n];
    for(int k=0;k<n;k++)
    {
        is_completed[k]=0;
    }
    int completed=0;
    printf("Start entering: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&req[i]);
    }
    printf("enter the head pointer position: ");
    scanf("%d",&head);

    while(completed!=n)
    {   
        
        int min=999,index=-1,diff=0;
        for(int i=0;i<n;i++)
        {
            diff=abs(head-req[i]);
            if(diff<min)
            {
                min=diff;
                index=i;
            }
        }
        dist=dist+abs(head-req[index]);
        head=req[index];
        is_completed[index]=1;
        completed++;

        printf("%d ",head);
    }
    printf("\ndistance:%d",dist);

    
}