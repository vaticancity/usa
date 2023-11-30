#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, head;
    printf("enter the number of requests: ");
    scanf("%d", &n);
    int req[n], store[n], order[n];

    printf("Start entering..\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &req[i]);
        order[i] = -1;  // Initialize order array to -1
    }
    printf("enter the head pointer location  :");
    scanf("%d", &head);

    for (int i = 0; i < n; i++)
    {
        int min = 999;
        for (int j = 0; j < n; j++)
        {
            if (req[j] != 0)
            {
                int dist = abs(head - req[j]);
                if (dist < min)
                {
                    min = dist;
                    store[i] = dist;
                    order[i] = req[j];  // Store the visited request
                }
            }
        }
        for (int k = 0; k < n; k++)
        {
            if (req[k] != 0)
            {
                int dist = abs(head - req[k]);
                if (min == dist)
                {
                    head = req[k];
                    req[k] = 0;
                    break;
                }
            }
        }
    }

    float seek_time = 0;
    printf("seek sequence:");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", store[i]);
        seek_time = seek_time + store[i];
    }

    printf("\nOrder of requests visited:");
    for (int i = 0; i < n; i++)
    {
        if (order[i] != -1)
        {
            printf(" %d", order[i]);
        }
    }

    printf("\n seek time: %f ", (seek_time));
    printf("\n");
    printf("\nAvg seek time: %f ", (seek_time / n));

    return 0;
}