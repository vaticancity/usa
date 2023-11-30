#include <stdio.h>
#include <limits.h>

int n, Pid[10], AT[10], BT[10], CT[10], TAT[10], WT[10], remain_time[10];

int main()
{
    printf("!... Welcome to SRTF Algorithm ...!\n\n");
    printf("Enter the number of processes : ");
    scanf("%d", &n);

    printf("\n\nEnter the Arrival Time of Processes\n");
    for (int i = 0; i < n; i++)
    {
        Pid[i] = i;
        printf("Arrival Time of Process %d : ", i);
        scanf("%d", &AT[i]);
    }

    printf("\n\nEnter the Brust Time of Processes\n");
    for (int i = 0; i < n; i++)
    {
        Pid[i] = i;
        printf("Brust Time of Process %d : ", i);
        scanf("%d", &BT[i]);

        remain_time[i] = BT[i];
    }

    int current_time = 0;
    int completed = 0;

    while (completed < n)
    {
        int min_remaining_time = INT_MAX;
        int shortest_process = -1;

        for (int i = 0; i < n; i++)
        {
            if (AT[i] <= current_time && remain_time[i] < min_remaining_time && remain_time[i] > 0)
            {
                min_remaining_time = remain_time[i];
                shortest_process = i;
            }
        }   

        if (shortest_process == -1)
        {
            current_time++;
        }
        else
        {
            remain_time[shortest_process]--;
            current_time++;

            if (remain_time[shortest_process] == 0)
            {
                completed++;
                CT[shortest_process] = current_time;
                TAT[shortest_process] = CT[shortest_process] - AT[shortest_process];
                WT[shortest_process] = TAT[shortest_process] - BT[shortest_process];
            }
        }
    }

    printf("\nPid \t AT \t BT \t CT \t TAT \t WT\n");
    for (int i = 0; i < n; i++)
    {
        printf(" %d \t %d \t %d \t %d \t %d \t %d\n ", Pid[i], AT[i], BT[i], CT[i], TAT[i], WT[i]);
    }

    int tTAT = 0, tWT = 0;
    for (int i = 0; i < n; i++)
    {
        tTAT += TAT[i];
        tWT += WT[i];
    }

    float ATAT = (float)tTAT / n;
    float AWT = (float)tWT / n;

    printf("\n\n Average TAT is : %.2f\n", ATAT);
    printf(" Average WT is : %.2f\n", AWT);

    return 0;
}