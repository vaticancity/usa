#include <stdio.h>
#include <stdlib.h>

struct Process {
    int pid;
    int AT;
    int BT;
    int CT;
    int WT;
    int TAT;
    int completed;
};

// Function to find the next process to execute based on Shortest Job First (SJF) scheduling
int findProcess(struct Process *processes, int n, int currentTime) {
    int index = -1, minBT = 999;

    // Iterate through processes to find the one with the shortest burst time
    for (int i = 0; i < n; i++) {
        if (!processes[i].completed && currentTime >= processes[i].AT &&
            processes[i].BT < minBT) {
            index = i;
            minBT = processes[i].BT;
        }
    }

    return index;
}

// Function to perform SJF scheduling
void SJFscheduling(struct Process *processes, int n) {
    int TBT = 0;

    // Calculate total burst time
    for (int i = 0; i < n; i++) {
        TBT += processes[i].BT;
    }

    int currentTime = 0;

    // Execute processes until all are completed
    while (currentTime < TBT) {
        int index = findProcess(processes, n, currentTime);

        // Update process information
        processes[index].CT = currentTime + processes[index].BT;
        processes[index].WT = processes[index].CT - processes[index].AT - processes[index].BT;
        processes[index].TAT = processes[index].CT - processes[index].AT;
        currentTime += processes[index].BT;
        processes[index].completed = 1;
    }
}

int main() {
    int n;

    // Input the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Declare an array of processes
    struct Process processes[n];

    // Input process details
    for (int i = 0; i < n; i++) {
        processes[i].completed = 0;
        printf("Enter PID, arrival time, burst time for process %d: ", i + 1);
        scanf("%d%d%d", &processes[i].pid, &processes[i].AT, &processes[i].BT);
    }

    // Perform SJF scheduling
    SJFscheduling(processes, n);

    // Display the results
    printf("PID | Arrival Time | Burst Time | Completion Time | Waiting Time | Turnaround Time\n");
    printf("--- | ------------ | ---------- | --------------- | ------------- | ----------------\n");

    float TWT = 0, TTAT = 0;

    // Display process details
    for (int i = 0; i < n; i++) {
        printf("%3d | %12d | %10d | %15d | %13d | %15d\n",
               processes[i].pid, processes[i].AT, processes[i].BT,
               processes[i].CT, processes[i].WT, processes[i].TAT);

        TWT += processes[i].WT;
        TTAT += processes[i].TAT;
    }

    // Display average waiting time and average turnaround time
    printf("\nAverage Waiting Time (AWT) = %.2f\n", TWT / n);
    printf("Average Turnaround Time (ATAT) = %.2f\n", TTAT / n);

    return 0;
}
