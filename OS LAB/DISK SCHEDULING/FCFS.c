#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int n;
    float seek_time=0;

    printf("enter the number of requests :");
    scanf("%d",&n);
    int req[n];
    int store[n];

    printf("start entering...");
    for(int i=0;i<n;i++)
    {   
        printf("\nenter reqest %d: ",i+1);
        scanf("%d",&req[i]);    
    }

    int head;
    printf("enter the head position : ");
    scanf("%d",&head);

    for(int i=0;i<n;i++)
    {   
        store[i] = abs(head-req[i]);
        seek_time = seek_time + store[i];
        head = req[i];
        printf("%d ",store[i]);
    }

    printf("\nTotal seek time: %f",seek_time);
    printf("\n");
    printf("Average seek time: %f",seek_time / n);
}