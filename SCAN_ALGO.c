#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,head,dist=0,index;
    printf("enter the number of requests: ");
    scanf("%d",&n);
    
    int req[n];
    int arr[n];

    printf("start entering :\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&req[i]);
    }

    int tracks;
    printf("enter the number of tracks: ");
    scanf("%d",&tracks);

    printf("enter the head pointer : ");
    scanf("%d",&head);
    int head1=head;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(req[j]>req[j+1])
            {
                int temp=req[j];
                req[j]=req[j+1];
                req[j+1]=temp;
            }
        }
    }

    for(int k=0;k<n;k++)
    {
        printf("%d ",req[k]);
    }

    int c = n-1;
// to find the nearest number to the head pointer this will stop immidiately if the number is greater
    while(head < req[c])
    {
        index=c;
        c--;
    }
   // printf("\n%d ",index);
    printf("\n");
    for(int j=index;j<n;j++)
    {
        printf("%d-> ",req[j]);
        dist=dist+abs(head-req[j]);
        head=req[j];

    }
    dist = dist+abs(head-(tracks-1));
    head=tracks-1;
    printf("%d->",tracks-1);
    for(int u=index-1;u>=0;u--)
    {   
        dist=dist+abs(head-req[u]);
        head=req[u];
        printf(" %d->",req[u]);
    }
    printf("\ndistance:%d",dist);
    printf("\ndistance:%d",((tracks-1)-head1)+(tracks-1)-req[0]);
    

}