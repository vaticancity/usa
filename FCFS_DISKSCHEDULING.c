#include<stdio.h>
#include<stdlib.h>

int main()
{
    int head,dist,n;
    printf("enter the number of requests: ");
    scanf("%d",&n);
    int req[n];
    int seek[n];
    int d=0;

    printf("start entering...\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&req[i]);
    }

    printf("enter the head position: ");
    scanf("%d",&head);

    for(int j=0;j<n;j++)
    {
        dist=abs(head-req[j]);
        head=req[j];
        seek[j]=dist;
        d=d+seek[j];        
    }
    for(int i=0;i<n;i++)
    {   
        printf("%d ",seek[i]);
    }
    printf("\nSEEK TIME:%d",d);
}