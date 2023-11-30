#include<stdio.h>
int main()
{
    int fno,n,page_index=0,hit=0,miss=0,i,j,flag;
    printf("enter the number of frames : ");
    scanf("%d",&fno);
    int f[fno];

    for(i=0;i<fno;i++)
    {
        f[i] = -1;
    }

    printf("enter the number of pages: ");
    scanf("%d",&n);
    int p[n];

   

    printf("enter the page sequence: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&p[i]);
    }

    for(i=0;i<n;i++)
    {
        flag=0;
        for(j=0;j<fno;j++)
        {
            if(f[j] == p[i])
            {
                flag = 1;
                hit++;
                break;
            }
        }
        if(flag == 0)
        {
            f[page_index] = p[i];
            page_index = (page_index + 1) % fno;
            miss++;
            printf("frames: ");
           for(j=0;j<fno;j++)
            {
                printf("%d ",f[j]);
            }  
            printf("\n"); 
        }
    }

    printf("\nHit: %d",hit);
    printf("\nMiss: %d",miss);
    printf("\nHit ratio: %f",(float)hit / n);
    printf("\nMiss Ratio: %f",(float)miss/n);

    
}