#include <stdio.h>
#include <stdlib.h>

struct Process {
    int pid;
    int AT;
    int BT;
    int priority;
    int CT;
    int WT;
    int TAT;
};

int compareProcesses(const void *a, const void *b) {
    struct Process *processA = (struct Process *)a;
    struct Process *processB = (struct Process *)b;

    if (processA->priority < processB->priority) return -1;
    else if (processA->priority > processB->priority) return 1;
    else if (processA->AT < processB->AT) return -1;
    else if (processA->AT > processB->AT) return 1;

    return 0;
}

void priorityScheduling(struct Process *processes, int n) {
    qsort(processes, n, sizeof(struct Process), compareProcesses);
    int currentTime = 0;

    for (int i = 0; i < n; i++) {
        if (currentTime < processes[i].AT) {
            currentTime = processes[i].AT;
        }

        processes[i].CT = currentTime + processes[i].BT;
        processes[i].WT = processes[i].CT - processes[i].AT - processes[i].BT;
        processes[i].TAT = processes[i].CT - processes[i].AT;
        currentTime += processes[i].BT;
    }
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    for (int i = 0; i < n; i++) {
        printf("Enter PID, arrival time, burst time, and priority for process %d: ", i + 1);
        scanf("%d %d %d %d", &processes[i].pid, &processes[i].AT, &processes[i].BT, &processes[i].priority);
    }

    priorityScheduling(processes, n);

    printf("\nPID | Arrival Time | Burst Time | Priority | Completion Time | Waiting Time | Turnaround Time\n");
    printf("--- | ------------   | ---------- | -------- | --------------- | ------------ | -----------------\n");
   

    for (int i = 0; i < n; i++) {
        printf("%3d | %13d | %11d | %17d | %13d | %15d\n", processes[i].pid, processes[i].AT,
               processes[i].BT, processes[i].priority, processes[i].CT,
               processes[i].WT, processes[i].TAT);
    }

    return 0;
}
