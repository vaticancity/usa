#include <stdio.h>
int n, Pid[10], AT[10], BT[10], CT[10], TAT[10], WT[10], RT[10], start_time = 0, tTAT = 0, tWT = 0, ATAT = 0, AWT = 0, ART = 0;

void sortProcesses(int n, int AT[], int BT[], int Pid[])
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (AT[i] > AT[j])
            {
                // swap AT
                int temp = AT[i];
                AT[i] = AT[j];
                AT[j] = temp;

                // swap BT
                temp = BT[i];
                BT[i] = BT[j];
                BT[j] = temp;

                // swap Pid
                temp = Pid[i];
                Pid[i] = Pid[j];
                Pid[j] = temp;
            }
        }
    }
}

int main()
{
    printf("Welcome to FCFS Process Scheduling....!!!\n\n");
    printf("Enter the number of process : ");
    scanf("%d", &n);

    printf("\n\nEnter the Arrival Time of the Processes\n");
    for (int i = 0; i < n; i++)
    {
        Pid[i] = i;
        printf("Arrival Time of Process %d : ", i);
        scanf("%d", &AT[i]);
    }

    printf("\n\nEnter the Burst Time of the Processes\n");
    for (int i = 0; i < n; i++)
    {
        printf("Burst Time of Process %d : ", i);
        scanf("%d", &BT[i]);
    }

    // Sorting the arrival times and keeping track of process IDs

    sortProcesses(n, AT, BT, Pid);

    // checking 2 cases for AT
    // case 1 :- i = 0 -> start time = 0
    // case 2 :- i != 0 -> start time = CT[i-1]
    //      CT[i] = start time + BT

    // Calculate completion times (CT)
    CT[0] = AT[0] + BT[Pid[0]];
    for (int i = 1; i < n; i++)
    {
        if (AT[i] > CT[i - 1])
        {
            CT[i] = AT[i] + BT[Pid[i]];
        }
        else
        {
            CT[i] = CT[i - 1] + BT[Pid[i]];
        }
    }

    // Calculate (TAT, WT, RT)
    for (int i = 0; i < n; i++)
    {
        TAT[i] = CT[i] - AT[i];
        WT[i] = TAT[i] - BT[Pid[i]];
        RT[i] = CT[i - 1] - AT[i];
    }

    printf("\nPid \t AT \t BT \t CT \t TAT \t WT \t RT\n");
    for (int i = 0; i < n; i++)
    {
        printf(" %d \t %d \t %d \t %d \t %d \t %d \t %d \n ", Pid[i], AT[i], BT[Pid[i]], CT[i], TAT[i], WT[i], RT[i]);
    }

    // Calculate averages
    for (int i = 0; i < n; i++)
    {
        tTAT = tTAT + TAT[i];
        tWT = tWT + WT[i];
    }

    ATAT = tTAT / n;
    AWT = tWT / n;
    ART = AWT;

    printf("\n\n Average TAT is : %d ", ATAT);
    printf("\n\n Average WT is : %d ", AWT);
    printf("\n\n Average RT is : %d ", ART);

    return 0;
}