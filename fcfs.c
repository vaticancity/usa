#include <stdio.h>
#include <stdlib.h>

struct Process {
    int pid;
    int AT;
    int BT;
    int CT;
    int WT;
    int TAT;
};

void FCFSscheduling(struct Process *processes, int n) {
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].AT > processes[j + 1].AT) {
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

  
    int currentTime = 0;
    for (int i = 0; i < n; i++) {
        if (currentTime < processes[i].AT) {
            currentTime = processes[i].AT;
        }

        processes[i].CT = currentTime + processes[i].BT;
        processes[i].WT = currentTime - processes[i].AT;
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
        printf("Enter PID, arrival time, and burst time for process %d: ", i + 1);
        scanf("%d%d%d", &processes[i].pid, &processes[i].AT, &processes[i].BT);
    }

    FCFSscheduling(processes, n);

    printf("\nPID | Arrival Time | Burst Time | Completion Time | Waiting Time | Turnaround Time\n");
    printf("--- | -------------- | ----------- | ----------------- | ------------- | ----------------\n");

    float TWT = 0, TTAT = 0;
    for (int i = 0; i < n; i++) {
        printf("%3d | %13d | %11d | %17d | %13d | %15d\n", processes[i].pid,
               processes[i].AT, processes[i].BT, processes[i].CT, processes[i].WT, processes[i].TAT);
        TWT += processes[i].WT;
        TTAT += processes[i].TAT;
    }

    printf("\nAverage Waiting Time (AWT): %.2f\nAverage Turnaround Time (ATAT): %.2f\n", TWT / n, TTAT / n);

    return 0;
}
