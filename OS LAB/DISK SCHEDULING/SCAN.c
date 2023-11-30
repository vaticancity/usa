#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void sort(int req[], int no_req)
{
    for(int i = 0; i < no_req-1; i++)
    {
        for(int j = 0; j < no_req-i-1; j++)
        {
            if (req[j] > req[j+1]) 
            {
                int temp = req[j];
                req[j] = req[j+1];
                req[j+1] = temp;
            }
        }
    }
}

void elevator(int req[], int no_req, int head, int tracks)
{
    int distarray[100], s=0, index = -1, c = 0, flag = 0, seq[no_req + 1];
    float s1;

    for(int i = 0; i < no_req; i++)
    {
        if(req[i] > head)
        {
            index = i;
            seq[c] = req[i];
            c++;
            flag = 1;
        }
    }

    seq[c] = tracks - 1;

    for(int j = index; j >= 0; j--)
    {
        if(head > req[j])
        {
            seq[c+1] = req[j];
            c++;
        }
    }

    printf("The sequence is: ");
    for(int i = 0; i < no_req+1; i++)
    {
        printf("%d ", seq[i]);
    }
    
    for(int i = 0; i < no_req+1; i++)
    {
        int dist = abs(head - seq[i]);
        distarray[i] = dist;
        head = seq[i];
    }

    printf("\nDIST: ");
    for(int i = 0; i < no_req+1; i++)
    {
        printf("%d ", distarray[i]);
    }

    for(int i = 0; i < no_req+1; i++)
    {
        s = s + distarray[i];
    }
    s1 = (float)s/no_req;

    printf("\nThe total seek time is: %d\n", s);
    printf("The avg seek time is: %.2f\n", s1);
}

int main()
{
    int tracks;
    printf("Enter the number of tracks: ");
    scanf("%d", &tracks);

    int no_req;
    printf("Enter the number of requests: ");
    scanf("%d", &no_req);

    int req[no_req];
    printf("Enter the requests..");
    for(int i = 0; i < no_req; i++)
    {
        printf("Request %d: ", i+1);
        scanf("%d", &req[i]);
    }

    sort(req, no_req);

    int head;
    printf("Enter the current head: ");
    scanf("%d", &head);

    elevator(req, no_req, head, tracks);

    return 0;
}