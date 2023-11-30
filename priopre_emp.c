#include <stdio.h>
#include <stdlib.h>

struct Process {
    int pid;
    int AT;
    int BT;
    int CT;
    int WT;
    int FE;
    int RT;
    int TAT;
    int RBT;
    int priority;
    int completed;
};

void calctimes(struct Process *processes, int n) {
    for (int i = 0; i < n; i++) {
        processes[i].RT = processes[i].FE - processes[i].AT - 1;
        processes[i].WT = processes[i].CT - processes[i].AT - processes[i].BT;
        processes[i].TAT = processes[i].CT - processes[i].AT;
    }
}

int findprocess(struct Process *processes, int n, int currentTime) {
    int index = -1, maxpriority = -1;
    for (int i = 0; i < n; i++) {
        if ((!processes[i].completed) && (currentTime >= processes[i].AT) &&
            (processes[i].priority > maxpriority)) {
            index = i;
            maxpriority = processes[i].priority;
        }
    }
    return index;
}

void prioritypreemptivescheduling(struct Process *processes, int n) {
    int TBT = 0;
    for (int i = 0; i < n; i++) {
        processes[i].FE = -1;
        processes[i].RBT = processes[i].BT;
        TBT += processes[i].BT;
    }

    int currentTime = 0;
    while (currentTime < TBT) {
        int index = findprocess(processes, n, currentTime);
        processes[index].RBT--;
        currentTime++;
        if (processes[index].FE == -1) {
            processes[index].FE = currentTime;
        }
        if (processes[index].RBT == 0) {
            processes[index].completed = 1;
            processes[index].CT = currentTime;
        }
    }

    calctimes(processes, n);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct Process processes[n];
    for (int i = 0; i < n; i++) {
        processes[i].completed = 0;
        printf("Enter PID, arrival time, burst time, and priority for process %d: ", i + 1);
        scanf("%d%d%d%d", &processes[i].pid, &processes[i].AT, &processes[i].BT, &processes[i].priority);
    }

    prioritypreemptivescheduling(processes, n);

    printf("PID | Arrival Time | Burst Time | Priority | Completion Time | Waiting Time | Turnaround Time | Response time\n");
    printf("--- | ------------ | ---------- | -------- | --------------- | ------------ | ----------------| -------------\n");

    float TWT = 0, TTAT = 0, TRT = 0;
    for (int i = 0; i < n; i++) {
        printf("%3d | %12d | %10d | %8d | %15d | %12d | %15d | %13d\n",
               processes[i].pid, processes[i].AT, processes[i].BT, processes[i].priority,
               processes[i].CT, processes[i].WT, processes[i].TAT, processes[i].RT);
        TWT += processes[i].WT;
        TTAT += processes[i].TAT;
        TRT += processes[i].RT;
    }

    printf("\nAWT = %.2f\nATAT = %.2f\nART = %.2f", TWT / n, TTAT / n, TRT / n);
    return 0;
}
