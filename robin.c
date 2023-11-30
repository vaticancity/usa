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
    int completed;
};

void calctimes(struct Process *processes, int n) {
    for (int i = 0; i < n; i++) {
        processes[i].RT = processes[i].FE - processes[i].AT;
        processes[i].WT = processes[i].CT - processes[i].AT - processes[i].BT;
        processes[i].TAT = processes[i].CT - processes[i].AT;
    }
}

void RRAscheduling(struct Process *processes, int n, int tq) {
    int TBT = 0;
    for (int i = 0; i < n; i++) {
        processes[i].FE = -1;
        processes[i].RBT = processes[i].BT;
        TBT += processes[i].BT;
    }

    int currentTime = 0;
    while (currentTime < TBT) {
        for (int i = 0; i < n; i++) {
            if ((!processes[i].completed) && (processes[i].AT <= currentTime)) {
                if (processes[i].FE == -1) {
                    processes[i].FE = currentTime;
                }

                if (processes[i].RBT < tq) {
                    currentTime += processes[i].RBT;
                    processes[i].RBT = 0;
                } else {
                    processes[i].RBT -= tq;
                    currentTime += tq;
                }

                if (processes[i].RBT == 0) {
                    processes[i].CT = currentTime;
                    processes[i].completed = 1;
                }
            }
        }
    }

    calctimes(processes, n);
}

int main() {
    int n;
    int tq;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct Process processes[n];
    for (int i = 0; i < n; i++) {
        processes[i].completed = 0;
        printf("Enter PID, arrival time, burst time for process %d: ", i + 1);
        scanf("%d%d%d", &processes[i].pid, &processes[i].AT, &processes[i].BT);
    }

    printf("\nEnter time quantum: ");
    scanf("%d", &tq);
    RRAscheduling(processes, n, tq);

    printf("PID | Arrival Time | Burst Time | Completion Time | Waiting Time | Turnaround Time | Response time\n");
    printf("--- | ------------ | ---------- | --------------- | ------------ | ----------------| -------------\n");

    float TWT = 0, TTAT = 0, TRT = 0;
    for (int i = 0; i < n; i++) {
        printf("%3d | %12d | %10d | %15d | %12d | %15d | %13d\n",
               processes[i].pid, processes[i].AT, processes[i].BT,
               processes[i].CT, processes[i].WT, processes[i].TAT, processes[i].RT);
        TWT += processes[i].WT;
        TTAT += processes[i].TAT;
        TRT += processes[i].RT;
    }

    printf("\nAWT = %.2f\nATAT = %.2f\nART = %.2f", TWT / n, TTAT / n, TRT / n);
    return 0;
}
