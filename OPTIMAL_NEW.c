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
    int optimal[fno];
    for(int i=0;i<fno;i++)
    {
        fseq[i]=-1;
    }

    printf("START ENTERING..");
    for(int i=0;i<pno;i++)
    {
        scanf("%d",&pseq[i]);
    }
    for(int i=0;i<pno;i++)
    {
        flag=0;
        for(int j=0;j<fno;j++)
        {
            if(fseq[j]==pseq[i])
            {
                hit++;
                flag =1;
                break;
            }
            
        }
        if(flag == 0)
        {   
            miss++;
            flag =0;
            for(int q=0;q<fno;q++)
            {
                if(fseq[q] == -1)
                {
                fseq[q]=pseq[i];
                flag=1;
                break;
                
                }
            }
           
            if(flag ==0)
            {
                
                for(int u=0;u<fno;u++)
                {   
                    optimal[u]=-1;
                    int occ=0;
                    for(int v=i+1;v<pno;v++)
                    {   
                        if(fseq[u]==pseq[v])
                        {
                            optimal[u]=++occ;
                            break;
                        }
                        else
                        {
                            occ++;
                        }
                       
                    }
                }
                int max=0,max_index=-1;
                for(int k=0;k<fno;k++)
                {
                    if(optimal[k] == -1)
                    {   
                        max_index=k;
                        break;
                    }
                    else if(max < optimal[k])
                    {   
                       
                        max = optimal[k];
                        max_index = k;
                    }
                   
                }
                fseq[max_index]=pseq[i];
                
            }
        }
        printf("frames: ");
        for(int j=0;j<fno;j++)
        {   
            if(fseq[j]==-1)
            {
                printf("* ");
                continue;
            }
            printf("%d ",fseq[j]);
        }
        printf("\n");

            
    }
        printf("\nHIT:%d\nMISS:%d",hit,miss);


}