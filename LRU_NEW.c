#include<stdio.h>
#include<stdlib.h>

int main()
{
    int pno,fno,flag=0,miss=0,hit=0;
    printf("enter the number of frames: ");
    scanf("%d",&fno);

    printf("enter the number of pages: ");
    scanf("%d",&pno);

    int pseq[pno];
    int fseq[fno];
    int usage[fno];
    for(int i=0;i<fno;i++)
    {
        fseq[i]=-1;
        usage[i]=0;
    }

    printf("START ENTERING..");
    for(int i=0;i<pno;i++)
    {
        scanf("%d",&pseq[i]);
    }

    for(int i=0;i<pno;i++)
    {
        flag =0;
        for(int j=0;j<fno;j++)
        {
            if(fseq[j] == pseq[i])
            {
                hit++;
                flag =1;
                usage[j]=i+1;
                break;
            }
        }
        if(flag == 0)
        {
            miss++;
            int min_usage=usage[0];
            int min_index=0;
            for(int u=0;u<fno;u++)
            {
                // finding the process with the minimum usage to replace 
                if(usage[u] < min_usage)
                {
                    min_usage = usage[u];
                    min_index=u;
                }
            }
            // replace the page which has the minimum usage 
            fseq[min_index]=pseq[i];
            usage[min_index]=i+1; 
            printf("frames: ");
            for(int k=0;k<fno;k++)
            {   
                if(fseq[k]==-1)
                {
                    printf("* ");
                    continue;
                }
                printf("%d ",fseq[k]);
            }
            printf("\n");
        }
    }
    printf("\nHIT:%d\nMISS:%d",hit,miss);
    printf("\nhit ratio:%f\nmiss ratio:%f",(float)hit/pno,(float)miss/pno);
    
}